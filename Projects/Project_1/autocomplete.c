#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Comparator function for read_in_terms qsort
int compare_terms(const void *a, const void *b) {
    return strcmp(((struct term*)a)->term, ((struct term*)b)->term);
}

void read_in_terms(struct term **terms, int *pnterms, char *filename) {
    int i = 0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    char line[200];
    *pnterms = 0;
    while (fgets(line, sizeof(line), fp)) {
        (*pnterms)++;
    }
    *terms = (struct term*)malloc(*pnterms * sizeof(struct term));
    if (*terms == NULL) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return;
    }
    rewind(fp);
    for (i = 0; i < *pnterms; i++) {
        if (fgets(line, sizeof(line), fp)) {
            sscanf(line, "%lf\t%199s", &(*terms)[i].weight, (*terms)[i].term);
        }
    }

    fclose(fp);
    qsort(*terms, *pnterms, sizeof(struct term), compare_terms);
}

int lowest_match(struct term* terms, int nterms, char* substr) {
    if (nterms == 0) {
        return -1;
    }
    int left = 0, right = nterms - 1, res = -1;
    int len_substr = strlen(substr);

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strncmp(terms[mid].term, substr, len_substr);
        if (cmp < 0) {
            left = mid + 1;
        }
        else {
            res = mid;
            right = mid - 1;
        }
    }
    return (res != -1 && strncmp(terms[res].term, substr, len_substr) == 0) ? res : -1;
}

int highest_match(struct term* terms, int nterms, char* substr) {
    int left = 0, right = nterms - 1, res = -1;
    int len_substr = strlen(substr);
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strncmp(terms[mid].term, substr, len_substr);
        if (cmp < 0) {
            left = mid + 1;
        }
        else if (cmp == 0) {
                res = mid;
                left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }
    
    return (res != -1 && strncmp(terms[res].term, substr, len_substr) == 0) ? res : -1;
}

// Comparator function for autocomplete qsort
int compare_by_weight(const void *a, const void *b) {
    double weight_a = ((struct term*)a)->weight;
    double weight_b = ((struct term*)b)->weight;

    // To sort in descending order, reverse the comparison:
    return (weight_b - weight_a);
}

void autocomplete(struct term** answer, int* n_answer, struct term* terms, int nterms, char* substr) {
    int start = lowest_match(terms, nterms, substr);
    if (start == -1) {
        *answer = NULL;
        *n_answer = 0;
        return;
    }
    int i = start, count = 0;
    while (i < nterms && strncmp(terms[i].term, substr, strlen(substr)) == 0) {
        count++;
        i++;
    }
    *answer = (struct term*)malloc(count * sizeof(struct term));
    *n_answer = count;
    for (i = 0; i < count; i++) {
        (*answer)[i] = terms[start + i];
    }
    qsort(*answer, *n_answer, sizeof(struct term), compare_by_weight);
}
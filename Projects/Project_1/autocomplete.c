#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Comparator function for read_in_terms qsort
int sort_lexico(const void *a, const void *b) {
    // Cast the void pointers to 'term' pointers
    const struct term *termA = (const struct term *)a;
    const struct term *termB = (const struct term *)b;

    // Compare the 'term' strings lexicographically using strcmp
    return strcmp(termA->term, termB->term);
}

void read_in_terms(struct term **terms, int *pnterms, char *filename) {
    FILE *fp = fopen(filename, "r");  // Open the file for reading
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    char line[200];
    fgets(line, sizeof(line), fp);  // Read the first line
    line[strlen(line) - 1] = '\0';  // Remove the newline character
    *pnterms = atoi(line);  // Convert the first line to number of terms

    *terms = (struct term*)malloc(*pnterms * sizeof(struct term));  // Allocate memory for the terms
    if (*terms == NULL) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return;
    }

    for (int j = 0; j < *pnterms; j++) {
        fgets(line, sizeof(line), fp);  // Read each subsequent line
        int weight = 0;

        char *weight_char = strtok(line, "\t");  // Get the weight part of the line
        weight = char_to_int(weight_char, &weight);  // Convert weight from string to int
        (*terms)[j].weight = weight;  // Store the weight in the struct

        char *term_to_save = strtok(NULL, "\n");  // Get the term part of the line
        strcpy((*terms)[j].term, term_to_save);  // Store the term in the struct
    }

    fclose(fp);  // Close the file after reading

    qsort(*terms, *pnterms, sizeof(struct term), sort_lexico);  // Sort the terms lexicographically
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
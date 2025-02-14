#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    struct term *terms;
    int nterms;

    // Comparator function for qsort
    int compare_terms(const void *a, const void *b) {
        return strcmp(((struct term*)a)->term, ((struct term*)b)->term);
    }
    
    void read_in_terms(struct term **p_p_terms, int *p_nterms, const char *filename) {
        int i = 0;
    
        // Open the file "filename.txt"
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;  // Return if file opening fails
        }
    
        // Count the number of terms and store it in *p_nterms
        char line[200]; // Assumes line is <= 200 characters
        *p_nterms = 0;
        while (fgets(line, sizeof(line), fp)) {
            (*p_nterms)++;
        }
    
        // Allocate memory for terms
        *p_p_terms = (struct term*)malloc(*p_nterms * sizeof(struct term));
        if (*p_p_terms == NULL) {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;  // Return if memory allocation fails
        }
    
        // Rewind file to read terms into the allocated array
        rewind(fp);
    
        // Read data into allocated array
        for (i = 0; i < *p_nterms; i++) {
            if (fgets(line, sizeof(line), fp)) {
                // sscanf parses the line to extract the weight and term
                sscanf(line, "%lf\t%199s", &(*p_p_terms)[i].weight, (*p_p_terms)[i].term);
            }
        }
    
        fclose(fp);
    
        // Sort the terms lexicographically using strcmp
        qsort(*p_p_terms, *p_nterms, sizeof(struct term),
            (int (*)(const void *, const void *))compare_terms);
    }
    
    int lowest_match(struct term* p_p_terms, int nterms, const char* substr) {
        if (nterms == 0) return -1;  // Handle case where there are no terms
        
        int left = 0;
        int right = nterms - 1;
        int res = -1;
        int len_substr = strlen(substr);
    
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = strncmp(p_p_terms[mid].term, substr, len_substr);
    
            if (cmp < 0) {
                // The term at mid is lexicographically less than the prefix.
                left = mid + 1;
            } else {
                // The term at mid is greater than or equal to the prefix.
                res = mid;
                right = mid - 1;
            }
        }
    
        // Verify that the candidate actually starts with the prefix.
        if (res != -1 && strncmp(p_p_terms[res].term, substr, len_substr) == 0) {
            return res;
        }
        return -1;
    }

    int highest_match(struct term* terms, int nterms, const char* substr) {
        int left = 0;
        int right = nterms - 1;
        int res = -1;
        int len_substr = strlen(substr);
    
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = strncmp(terms[mid].term, substr, len_substr);
    
            if (cmp < 0) {
                // Mid is lexicographically less than substr
                left = mid + 1;
            } else {
                // Mid is lexicographically greater or equal to substr
                if (cmp == 0) {
                    // Update res and continue searching to the right
                    res = mid;
                }
                right = mid - 1;
            }
        }
    
        // Verify that the candidate actually starts with the prefix.
        if (res != -1 && strncmp(terms[res].term, substr, len_substr) == 0) {
            return res;
        }
        return -1;
    }
    
    // Don't change (intitializing variables)
    struct term *answer;
    int n_answer;
    
    // Comparator function to sort by weight (non-decreasing order)
    int compare_by_weight(const void *a, const void *b) {
        double weight_a = ((struct term*)a)->weight;
        double weight_b = ((struct term*)b)->weight;
        return (weight_a > weight_b) - (weight_a < weight_b);
    }

    void autocomplete(term** p_p_answer, int* p_n_answer, term* p_terms, int nterms, char* p_substr){
        int start = lowest_match(p_terms, nterms, p_substr); // Use 'start' to hold the index.
        if (start == -1) {
            *p_p_answer = NULL;
            *p_n_answer = 0;
            return;
        }
    
        int i = start;
        int count = 0;
        while (i < nterms && strncmp(p_terms[i].term, p_substr, strlen(p_substr)) == 0) {
            count++;
            i++;
        }
    
        *p_p_answer = (term*)malloc(count * sizeof(term));
        *p_n_answer = count;
    
        for (i = 0; i < count; i++) {
            (*p_p_answer)[i] = p_terms[start + i];
        }
    
        qsort(*p_p_answer, *p_n_answer, sizeof(term), compare_by_weight);
    }    
    
    //free allocated blocks here -- not required for the project, but good practice

    free(terms);

    return 0;
}


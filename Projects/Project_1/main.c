#include "autocomplete.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, const char* filename){  

        int i = 0;
        
        // Open the file "filename.txt"
        FILE* fp = fopen(filename, "r")
        if (file == NULL){
            printf("Error openining file\n");
        }

        // Count the number of terms and store it in *pnterms
        char line[200]; // Given to assume line <= 200
        *pnterms = 0;
        while(fgets(line, sizeof(line), fp)) {
            (*pnterms)++;
        }
        
        // Allocate memory
        *terms = (term*)malloc(*pnterms * sizeof(term))
        if (*terms == NULL){
            printf("Memory allocation failed\n");
            fclose(fp);
        }
        // Rewind file reading back to the start
        // so that terms can be stored in *terms
        rewind(fp);

        // Read data into allocated array
        for (i; i < *pnterms; i++){
            if(fgets(line, sizeof(line), fp)){
                // sscanf parses through the entire line to grab both datum
                sscanf(line, "%lf\t%199s", &(*terms)[i].weight. (*terms).);
            }
        }

        fclose(fp);
        
        // Sort the terms lexicographically using strcmp
        qsort(*terms, *pnterms, sizeof(term), 
        (int (*)(const void*, const void*)) 
        (int (*)(const void*, const void*)) 
            (strcmp(((term*)a)->term, ((term*)b)->term)));
    }

    int lowest_match(term* terms, int nterms, char* substr) {
        int left = 0;
        int right = nterms - 1;
        int res = -1;
        int len_substr = strlen(substr);

        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = strncmp(terms[mid].term, substr, len_substr);

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
        if (res != -1 && strncmp(terms[res].term, substr, len_substr) == 0) {
            return res;
        }
        return -1;
    }

    highest_match(struct term* terms, int nterms, char* substr){
        int left = 0;
        int right = nterms - 1;
        int res = -1;
        int len_substr = strlen(substr);

        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = strncmp(terms[mid].term, substr, len_substr);

            if (cmp <= 0) {
                // Mid is lexicographically less or equal to substr
                if (cmp == 0){
                    // Update res and continue looking right
                    res = mid;
                }
                left = mid + 1;
            }
            else {
                // Mid is lexicographically more than substr
                right = mid - 1
            }
        }

        // Verify that the candidate actually starts with the prefix.
        if (res != -1 && strncmp(terms[res].term, substr, len_substr) == 0) {
            return res;
        }
        return -1;
    }
    
    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    
    //free allocated blocks here -- not required for the project, but good practice

    free(terms);

    return 0;
}


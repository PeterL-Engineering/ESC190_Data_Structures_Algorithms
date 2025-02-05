#include "autocomplete.h"
#include <stdio.h>

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

    }


    lowest_match(terms, nterms, "Tor");


    highest_match(terms, nterms, "Tor");
    
    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    
    free(terms);
    //free allocated blocks here -- not required for the project, but good practice
    return 0;
}


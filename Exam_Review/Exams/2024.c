// Q. 1

int compare(const void *a, const void *b) {
    return(*(int*)a - *(int*)b);
}

int my_median(int *arr, int sz) {

    qsort(arr, sz, sizeof(int), compare);

    return arr[sz/2];
}

// Q. 2

// Function to check if a character is a letter (a-z)
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to count the frequency of each letter in the string
void count_letters(char *s, int counts[]) {
    // Initialize the counts array to 0
    for (int i = 0; i < 26; i++) {
        counts[i] = 0;
    }

    // Iterate over the string
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        if (isLetter(s[i])) {
            int ascii = s[i];
            counts[ascii - 'a']++;  // Index from 0 to 25 for 'a' to 'z'
        }
    }
}

// Q. 3

char *reverse_words(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // Allocate space for the reversed string
    char *res = (char *)malloc(len + 1);  // +1 for the null terminator
    int j = 0;

    // Iterate over the string from the end to start
    int i = len - 1;
    while (i >= 0) {
        // Skip over spaces to find the end of a word
        if (str[i] == ' ') {
            i--;
            continue;
        }

        // Now, we are at the start of a word, so find its boundaries
        int word_end = i;
        while (i >= 0 && str[i] != ' ') {
            i--;
        }
        
        // Copy the word to the result array
        for (int k = i + 1; k <= word_end; k++) {
            res[j++] = str[k];
        }

        // Add space between words if not at the end
        if (i >= 0) {
            res[j++] = ' ';
        }
    }

    // Add the null terminator
    res[j] = '\0';

    return res;
}
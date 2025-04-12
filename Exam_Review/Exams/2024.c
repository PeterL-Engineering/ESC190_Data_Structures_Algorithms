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

// Q. 4 

int is_increasing(int *arr, int sz) {
    if (sz <= 1) {
        return 1;
    }

    if (arr[0] > arr[1]) {
        return 0;
    } 
    
    else {
        return is_increasing(arr + 1, sz - 1);
    }
}

// Q. 5

typedef struct CQ {
    char *arr;
    int front;
    int sz;
    int capacity;
} CQ;

void init(CQ **queue, int capacity) {
    *queue = (CQ *)malloc(sizeof(CQ));
    (*queue)->arr = (char *)malloc(capacity * sizeof(char));
    (*queue)->front = 0;
    (*queue)->sz = 0;
    (*queue)->capacity = capacity;
}

void enqueue(CQ *queue, char elem) {
    if (queue->sz == queue->capacity) {
        int new_cap = queue->capacity * 2;
        char *temp = (char *)malloc(new_cap * sizeof(char));

        for (int i = 0; i < queue->sz; i++) {
            temp[i] = queue->arr[(queue->front + i) % queue->capacity];
        }

        free(queue->arr);
        queue->arr = temp;
        queue->front = 0;
        queue->capacity = new_cap;
    }

    int rear = (queue->front + queue->sz) % queue->capacity;
    queue->arr[rear] = elem;
    queue->sz++;
}

char dequeue(CQ *queue) {
    if (queue->sz == 0) {
        return '\0';  // or handle underflow
    }

    char res = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->sz--;
    return res;
}

void free_queue(CQ *queue) {
    free(queue->arr);
    free(queue);
}
// Q. 1

char *concat_all(char **strs, int strs_sz0) {
    int i = 0;
    while (strs[i]) i++;

    char *res = (char *)malloc((sizeof(char) * strs_sz0 * i) + 1);

    for (int j = 0; j < i; j++) {
        for (int k = 0; k < strs_sz0; k++) {
            res[k + (strs_sz0 * j)] = strs[j][k];
        }
    }

    res[(strs_sz0 * i) + 1]= '\0';
    return res;
}
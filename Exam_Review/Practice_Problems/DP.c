#include <stdlib.h>
#include <limits.h>

int min(const int a, const int b) {
    return (a < b) ? a : b;
}

// Q2: Minimum number of coins for a target value
int min_num_coins(int *denominations, int num_denom, int target) {
    int *DP = (int *)malloc(sizeof(int) * (target + 1));
    for (int i = 0; i <= target; i++) {
        DP[i] = INT_MAX;
    }
    DP[0] = 0;

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < num_denom; j++) {
            if (i - denominations[j] >= 0 && DP[i - denominations[j]] != INT_MAX) {
                DP[i] = min(DP[i], DP[i - denominations[j]] + 1);
            }
        }
    }

    int result = DP[target];
    free(DP);
    return result == INT_MAX ? -1 : result;
}

// Q3: List min coins for all values up to target
int *list_min_coins(int *denominations, int num_denom, int target) {
    int *DP = (int *)malloc(sizeof(int) * target);
    for (int i = 0; i < target; i++) {
        DP[i] = min_num_coins(denominations, num_denom, i + 1);
    }
    return DP;
}

// Q4: Return actual coins used to make up the target value
int *coins_req(int *denominations, int num_denom, int target, int *res_size) {
    int *DP = (int *)malloc(sizeof(int) * (target + 1));
    int *prev = (int *)malloc(sizeof(int) * (target + 1));

    for (int i = 0; i <= target; i++) {
        DP[i] = INT_MAX;
        prev[i] = -1;
    }
    DP[0] = 0;

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < num_denom; j++) {
            int coin = denominations[j];
            if (i - coin >= 0 && DP[i - coin] != INT_MAX && DP[i - coin] + 1 < DP[i]) {
                DP[i] = DP[i - coin] + 1;
                prev[i] = coin;
            }
        }
    }

    if (DP[target] == INT_MAX) {
        *res_size = 0;
        free(DP);
        free(prev);
        return NULL;  // No solution
    }

    *res_size = DP[target];
    int *res = (int *)malloc(sizeof(int) * (*res_size));
    int curr = target, idx = 0;

    while (curr > 0) {
        int coin = prev[curr];
        res[idx++] = coin;
        curr -= coin;
    }

    free(DP);
    free(prev);
    return res;
}

// Q. 5

#include <string.h>

int canBeSegmented(char *s, char **wordDict, int num_words) {
    if (s[0] == '\0') {
        return 1; // Base case: successfully segmented entire string
    }

    for (int i = 0; i < num_words; i++) {
        int word_len = strlen(wordDict[i]);
        if (strncmp(s, wordDict[i], word_len) == 0) {
            if (canBeSegmented(s + word_len, wordDict, num_words)) {
                return 1;
            }
        }
    }

    return 0; // No valid segmentation found
}

#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharHeuristic(char *pattern, int pattern_length, int bad_char[NO_OF_CHARS]) {
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        bad_char[i] = -1;
    for (i = 0; i < pattern_length; i++)
        bad_char[(int)pattern[i]] = i;
}

void goodSuffixHeuristic(char *pattern, int pattern_length, int good_suffix[]) {
    int i, j;
    int suff[pattern_length + 1];
    suff[pattern_length] = pattern_length;
    for (i = pattern_length - 1; i >= 0; i--) {
        j = i;
        while (j >= 0 && pattern[j] == pattern[pattern_length - 1 - i + j])
            j--;
        suff[i] = i - j;
    }
    for (i = 0; i < pattern_length; i++)
        good_suffix[i] = pattern_length;
    j = 0;
    for (i = pattern_length - 1; i >= 0; i--) {
        if (suff[i] == i + 1) {
            while (j < pattern_length - 1 - i) {
                if (good_suffix[j] == pattern_length)
                    good_suffix[j] = pattern_length - 1 - i;
                j++;
            }
        }
    }
    for (i = 0; i <= pattern_length - 2; i++)
        good_suffix[pattern_length - 1 - suff[i]] = pattern_length - 1 - i;
}

void boyerMoore(char *text, char *pattern) {
    int pattern_length = strlen(pattern);
    int text_length = strlen(text);

    int bad_char[NO_OF_CHARS];
    int good_suffix[pattern_length];
    badCharHeuristic(pattern, pattern_length, bad_char);
    goodSuffixHeuristic(pattern, pattern_length, good_suffix);

    int shift = 0;
    while (shift <= (text_length - pattern_length)) {
        int j = pattern_length - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            printf("Pattern found at index %d\n", shift);
            shift += (shift + pattern_length < text_length) ? pattern_length - bad_char[text[shift + pattern_length]] : 1;
        } else {
            shift += max(good_suffix[j], j - bad_char[text[shift + j]]);
        }
    }
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%[^\n]", text);
        getchar(); 

    printf("Enter the pattern: ");
    scanf("%[^\n]", pattern);
    boyerMoore(text, pattern);
    return 0;
}

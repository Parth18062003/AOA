#include <stdio.h>
#include <string.h>

void computeLPSArray(char pat[], int M, int lps[]);

void KMP(char pat[], char txt[])
{
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0, j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

void computeLPSArray(char pat[], int M, int lps[])
{
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    char txt[100], pat[100];

    printf("Enter the text: ");
    scanf("%s", txt);

    printf("Enter the pattern to be matched: ");
    scanf("%s", pat);

    KMP(pat, txt);
    return 0;
}

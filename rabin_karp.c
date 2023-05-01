#include <stdio.h>
#include <string.h>

#define d 10

void rabinKarp(char pattern[], char text[], int q) {
  int m = strlen(pattern);
  int n = strlen(text);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == m)
        printf("Pattern is found at position:  %d \n", i + 1);
    }

    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}

int main() {
  char text[10],pattern[10];
  printf("Enter Text: ");
  scanf("%s",&text);
  printf("Enter Pattern: ");
  scanf("%s",&pattern);
  int q = 13;
  rabinKarp(pattern, text, q);
}

/*Rabin_Karp(T[0...(n-1)],P[0.....(m-1)])
{
    mod T := mod(T[0....(m-1)], q);
    mod P := mod(P[0....(n-1)], q);
    for i := 1 to n-m+1
        if mod P = mod T
            if T[i....i+m-1] = P
            return i;
        mod P := mod(s[i+1.....i+m], q)
    return not found;
}*/    

#include <stdio.h>

void radix(int s[], int n);

void radix(int s[], int n) {
  int R[n], bit = 1;
  int max = maxof(s);
  
  while(max/bit > 0) {
    int S[10] = {0};  
    for(int i = 0; i < n; i++)
      S[(s[i]/bit)%10]++;
    for(int i = 1; i < 10; i++)
      S[i] += S[i-1];
    for(int i = n-1; i >= 0; i--) {
      R[S[(s[i]/bit)%10] - 1] = s[i];
      S[(s[i]/bit)%10]--;
    }
    for(int i = 0; i < n; i++)
      s[i] = R[i];
    bit *= 10;
  }
}

#include <stdio.h>

void merge(int s[], int n);
void __merge(int s[], int s1[], int m, int s2[], int n);

void merge(int s[], int n) {
  if(n <= 1) return;
  int mid = n/2, s1[mid], s2[n-mid];
  
  for(int i = 0; i < mid; i++) s1[i] = s[i];
  for(int i = 0; i < n-mid; i++) s2[i] = s[mid+i];
  
  merge(s1, mid);
  merge(s2, n-mid);
  __merge(s, s1, mid, s2, n-mid);
}

void __merge(int s[], int s1[], int m, int s2[], int n) {
  int _s[m+n], i = 0, j = 0, k = 0;
  
  while(i < m && j < n)
    if(s1[i] < s2[j])
      _s[k++] = s1[i++];
    else
      _s[k++] = s2[j++];
  
  for(int _i = i; i < m; i++) _s[k+_i] = s1[_i];
  for(int i = j; i < n; i++) _s[k++] = s2[i];
  for(int i = 0; i < m+n; i++) s[i] = _s[i];
}

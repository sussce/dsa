void prekmp(char *x, int n, int T[]);
void kmp(char *x, int m, char *y, int n);

void kmp(char *x, int m, char *y, int n) {
  int T[m], i = 0, j = 0;
 
   prekmp(x, m, T);

   while (j < n) {
      while (i > -1 && x[i] != y[j])
         i = T[i];
      i++;
      j++;
      if (i >= m) {
        printf("%d\n", j-i);
        i = T[i];
      }
   }
}

/* 0  1  2  3  4  5  6
   A  B  C  D  A  B  D
  -1  0  0  0 -1  0  2
m: 01234567890123456789012
S: ABCAB CDABABCDABCDABDE
*/
void prekmp(char *x, int n, int T[]) {
   int i = 0, j = T[0] = -1;

   while (i < n) {
      while (j > -1 && x[i] != x[j])
         j = T[j];
      i++;
      j++;
      if (x[i] == x[j])
         T[i] = T[j];
      else
         T[i] = j;
   }
}

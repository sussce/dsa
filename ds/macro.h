#ifndef MACRO_H
#define MACRO_H
#include <assert.h>

typedef enum {false, true} bool;

#define null NULL
#define nullptr NULL

#define ab(a, b) (a b)
#define ab1(a, b) (a##b)
#define eq(a, b) ((a) == (b))
#define mod(a, b) (a%b)
#define square(a) (a*a)

/* #define FOR(TYPE, IDENT, BEGIN, END) \ */
/*   for( \ */
/*     TYPE IDENT = BEGIN, IDENT##_end = static_cast<decltype(IDENT)>(END); \ */
/*     IDENT < IDENT##_end; \ */
/*     ++IDENT \ */
/*   ) */
/* #define FOR_STEP(TYPE, IDENT, BEGIN, END, STEP) \ */
/*   for( \ */
/*     TYPE IDENT = (TYPE)(BEGIN), IDENT##_end = static_cast<decltype(IDENT)>(END); \ */
/*     IDENT < IDENT##_end; \ */
/*     IDENT += STEP \ */
/*   ) */
/* #define FOR_ITER(IDENT, BEGIN, END) \ */
/*   for( \ */
/*     auto IDENT = BEGIN, IDENT_end = END; \ */
/*     IDENT != IDENT_end; \ */
/*     ++IDENT \ */
/*   ) */
#define for1(i, v, n) for (int i = (v); i < (n); i++)
#define array_sz(s) \
  (sizeof (s)/((void *)s == &s ? sizeof (s[0]) : 0))
#define digits(n) \
  ({ int _c = 0; for (int _i = n; _i != 0; _i /= 10, _c++); _c; })

#define max(a, b) \
  ({ typeof (a) _a = (a); \
    typeof (b) _b = (b); \
    _a > _b ? _a : _b; })

#define min(a, b) \
  ({ typeof (a) _a = (a); \
    typeof (b) _b = (b); \
    _a < _b ? _a : _b; })

#define maxof(s) \
  ({ typeof (s[0]) *_s = s; \
    typeof ((s)[0]) _max = _s[0]; \
    int _n = (int)( sizeof (_s) / sizeof (_s[0]) ); \
    for(int _i = 0; _i < _n; _i++) \
      if(_s[_i] > _max) _max = _s[_i]; _max; })

#define swap(p1, p2) \
  ({ typeof (p1) _p1 = p1; \
    typeof (p2) _p2 = p2; \
    int np1 = sizeof ((typeof (*_p1))(*_p1)), \
      np2 = sizeof ((typeof (*_p2))(*_p2)); \
    assert(np1 == np2); \
    typeof (*_p1) e = *_p1; \
    *_p1 = *_p2; \
    *_p2 = e; }) 

#define __nl() putchar('\n')
#define __printf(s, n, fm) \
  ({ typeof (s) _s = s; \
    for(int _i = 0; _i < n; _i++) \
      printf(fm, *(_s+_i)); \
    __nl(); })

#define __sprintf(s, n) \
  ({ int _n = sizeof(typeof(*s)); \
    char *fm = ""; \
    if (_n == sizeof(int)) fm = "%d "; \
    else if (_n == sizeof(char)) fm = "%c "; \
    __printf(s, n, fm); })
#endif

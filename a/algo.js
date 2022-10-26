let count = 0;
function recursive(n) {
  function __recursive() {
    if(count == n) return true;
    count++,
    recursive()
  }
}

function naive_search(str, substr) {
  if (substr.length > str.length) return false;
  
  for(let i = 0; i < str.length; i++) {
    for(let j = 0; j < substr.length; j++) {
      if(str[i+j] !== substr[j]) break;
      if(j === substr.length-1) return true;
    }
  }
  return false
}

function binary_search(array, element) {
  let first = 0,
      last = array.length-1,
      middle = Math.floor((first+last)/2);

  while(array[middle] !== element && first <= last) {
    if(array[middle] > element) {
      last = middle-1
    } else {
      first = middle+1
    }
    middle = Math.floor((first+last)/2)
  }
  return array[middle] === element ? middle : -1
}

function kmp(s, S) {
  const l = s.length, L = S.length,
        T = prekmp(s);
  let is = 0, iS = 0
  
  while(iS < L) {
    if(s[is] == S[iS]) {
      is++, iS++;
    }
    if(is == l)
      is = T[is-1]
    else if(iS < L && s[is] != S[iS]) {
      if(is != 0)
        is = T[is-1]
      else
        iS++
    }
  }
}

function prekmp(s) {
  const L = s.length, T = Array(L).fill(0);
  let pT = 1, p = 0;
   
  while(pT < L) {
    if(s[pT] == s[p]) {
      p++,
      T[pT++] = p
    } else {
      if (p != 0)
        p = T[p-1]
      else
        T[pT++] = 0
    }
  }
  return T
}

/*{
let T[0] = -1
while pT < length(s) do
  if s[pT] == s[p] then
    T[pT] = T[p]
  else
    T[pT] = p
    while p >= 0 and s[pT] != s[p] do
      p = T[p]
  pt++, p++
T[pT] = p
}*/

function bubble(s) {
  const l = s.length;
  
  for(let i = 0; i < l; i++) {
    let e = 0;
    for(let j = 0; j < l-i-1; j++) {
      if(s[j] > s[j+1]) {
        swap(s, j, j+1),
        e = 1
      }
    }
    if(!e) break
  }
}

function bubble1(s) {
  let L = s.length;
  
  for(let i = L-1; i > 0; i--) {
    let e = 0;
    for(let j = 0; j < i; j++) {
      if(s[j] > s[j+1]) {
        swap(s, j, j+1),
        e = j
      }
    }
    L = e
  }
}

function __merge(s1, s2) {
  let s = []
  while(s1.length && s2.length) {
    if(s1[0] < s2[0])
      s.push(s1.shift())
    else
      s.push(s2.shift())
  }
  return [...s, ...s1, ...s2]
}

function merge(s) {
  if(s.length <= 1) return s;
  let mid = Math.floor(s.length / 2),
      left = merge(s.slice(0, mid)),
      right = merge(s.slice(mid))
  return __merge(left, right);
}

function quick(s, left, right) {
  if(left >= 0 <= right && left < right) {
    let p = partition(s, left, right);
    quick(s, left, p),
    quick(s, p+1, right)
  }
}

function partition(s, left, right) {
  let middle = Math.floor((left + right) / 2),
      pivot = s[middle],
      i = left -1,
      j = right + 1;
  
  for(;;) {
    while(s[++i] < pivot) {}
    while(j > 0 && s[--j] > pivot) {}

    if(i >= j) return j;
    swap(s, i, j)
  }
}

function swap(s, left, right) {
  let tmp = s[left];
  s[left] = s[right],
  s[right] = tmp
}

function radix(s, ss) {
  const R = [],
        max = Math.max(...s);
  let i, bit = 1;
 
  while(Math.floor(max/bit) > 0) {
    let digit, S = Array(10).fill(0);

    for(i = 0; i < ss; i++) {
      digit = Math.floor(s[i]/bit)%10,
      S[digit]++
    }
    for(i = 1; i < 10; i++)
      S[i] += S[i-1];
    for(i = ss-1; i >= 0; i--) {
      digit = Math.floor(s[i]/bit)%10,
      R[S[digit] - 1] = s[i],
      S[digit]--;
    }
    for(i = 0; i < ss; i++)
      s[i] = R[i];
    bit *= 10;
  }
}

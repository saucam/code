#include <bits/stdc++.h>

using namespace std;

int arr[2000];

int main() {
  int t,n, temp;
  cin >> t;
  while (t > 0) {
    int prevOdd = -1, prevEven = -1, cnt = 0;
    cin >> n;
    for (int j=0; j<(2*n); j++) cin >> arr[j];
    for (int j=0; j<((2*n)) && (cnt < n-1); j++) {
      if (arr[j] % 2 == 0) {
        if (prevEven == -1) prevEven = j; else { printf("%d %d\n", prevEven + 1, j + 1); prevEven = -1; cnt++;}  
      } else {
        if (prevOdd == -1) prevOdd = j; else { printf("%d %d\n", prevOdd + 1, j + 1); prevOdd = -1; cnt++;} 
      }
    }
    t--;
  }
  return 0;
}

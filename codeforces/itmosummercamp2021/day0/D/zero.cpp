#include <bits/stdc++.h>

using namespace std;
long long a[10001];
int main() {
  int n, k;
  cin >> n;
  k = n - 1; 
  while (k >= 0) {
    cin >> a[k];
    k--;
  }
  k++;
  while (k < n) {
    cout << a[k] << " ";
    k++;
  }
  return 0;
}

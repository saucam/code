#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, i = 0;
  int arr[50];
  cin >> n >> k;
  while(i < n) {
    cin >> arr[i];
    i++;
  }
  int ans = 0;
  for(int j=0; j<n; j++) {
    if ((arr[j] >= arr[k - 1]) && arr[j] > 0) {
      ans++;
    }
  }
  
  printf("%d\n", ans);
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int arr[101];
int res[101];
int seen[101];
int main() {
  int n, m;
  int possible = 0;
  cin >> n >> m;
  for(int i=0;i<m;i++) cin >> arr[i];
  for(int i=1;i<m;i++) {
    int diff = (arr[i] - arr[i - 1] + n)%n;
    int rDiff = diff == 0? n : diff;
    if (seen[rDiff] > 0 && (seen[rDiff] != arr[i - 1] )) possible = 1;
    res[arr[i - 1]] = rDiff;
    seen[rDiff] = arr[i - 1];
  }
  int u = 1;
  while((u <=n) && (seen[u] != 0)) u++;
  int k;
  for(k=1; k<=n; k++) {
    if (res[k] == 0) {
      // Try to get a valid missing number here
      if (u > n) {
        possible = 1;
        break;
      }
      res[k] = u;
      seen[u] = k;
      while((u <= n) && (seen[u] != 0)) u++;
    }
  }
  if (possible == 0) {
    for(int p=1; p<=n; p++) {
      printf("%d ", res[p]);
    }
    printf("\n");
  } else {
    printf("%d\n", -1);
  }
  return 0;
}

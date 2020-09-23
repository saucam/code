#include <bits/stdc++.h>

using namespace std;

int arr[100];
int l[100];
int f[100];
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    for (int k=0; k<n; k++) {
      cin >> arr[k];
    }
    int fp = 0;
    int sum = 0;
    int pre = 0;
    int d = 0;
    for (int k=0; k<n; k++) {
      cin >> l[k];
      if (l[k] == 0) {
        if (d == 0) { d = 1;  }
        f[fp] = arr[k];
        sum += f[fp];
        fp++;
      } else { if (d == 0) { pre = pre + l[k];} }
    }
    sort(f, f + fp, greater<int>());
    fp = 0;  
    for (int k=0; k<n; k++) {
      if (l[k] == 0) {
        printf("%d ", f[fp]);
        fp++;
      } else {
        printf("%d ", arr[k]);
      }
    }
    printf("\n");
    t--;
  }
  return 0;
}

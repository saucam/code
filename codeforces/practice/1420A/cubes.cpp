#include <bits/stdc++.h>

using namespace std;

int mergeSort(vector<int>& v, int l, int r) {
   if (l < r) {
     int middle = l + (r - l)/2;
     int left = mergeSort(v, l, middle);
     int right = mergeSort(v, middle + 1, r);
     int ans = 0;
     int k=0, j = middle + 1;
     while(k<=middle && j<=r) {
       if (v[k] > v[j]) {
         ans += (middle - k + 1); 
         j++;
       } else {
         k++;
       }
     }
     sort(v.begin() + l, v.begin() + r + 1);
     return left + right + ans;
   } else return 0;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &a: v) cin >> a;
    int prev = v[0];
    bool t = true;
    for(int i=1;i<n;i++) {
      if (v[i] >= prev) {
        t = false;
        break;
      }
      prev = v[i];
    }
    // int ans = mergeSort(v, 0, v.size() - 1);
    if (t) cout << "NO" << "\n"; else cout << "YES" << "\n";
  }
  return 0;
}

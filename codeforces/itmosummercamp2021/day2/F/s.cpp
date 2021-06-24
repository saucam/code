#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &a: v) {
    cin >> a;
  }
  sort(v.begin(), v.end());
  int k, l, r;
  vector<int>::iterator lower, upper;
  cin >> k;
  for (int j =0 ; j < k; j++) {
    cin >> l >> r;
    lower = lower_bound(v.begin(), v.end(), l);
    upper = upper_bound(v.begin(), v.end(), r);
    int la, ua;
    if (upper == v.end()) ua = n; else ua = upper - v.begin();
    if (lower == v.end()) la = 0; else la = lower - v.begin();
    cout << (ua)-(la) << " ";
  }
  
  cout << "\n";
  return 0;
}

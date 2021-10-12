#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for(auto &e: v) {
    cin >> e;
  }
  vector<int> c(v);
  sort(c.begin(), c.end());
  int k = 0, r = c.size() - 1;
  int start = -1, end = -1;
  bool ans = true;
  while(k < r) {
    if (start == -1) {
      if (c[k] == v[k]) {
        k++;
      } else {
        start = k;
      }
    }
    if (end == -1) {
      if (c[r] == v[r]) {
        r--;
      } else {
        end = r;
      }
    }
    if (start != -1 && end != -1) {
      if (v[k] != c[r] || v[r] != c[k]) {
        ans = false;
        break;
      } else {
        k++; r--;
      }
    }
  }
  if (start == -1 && end == -1) { start = 0; end = 0; }
  if (ans) { cout << "yes\n" << start + 1 << " " << end + 1 << "\n"; } else cout << "no\n";
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n, m;
  cin >> n;
  vector<int> b(n);
  for(int &e: b) {
    cin >> e;
  }
  cin >> m;
  vector<int> g(m);
  for(int &e: g) {
    cin >> e;
  }
  sort(b.begin(), b.end());
  sort(g.begin(), g.end());
  int k =0,r=0, ans = 0;
  while((k<n) && (r<m)) {
    if (abs(b[k] - g[r]) < 2) {
      k++; r++;
      ans++;
    } else if (b[k] > g[r]) { r++; } else { k++; }
  }
  cout << ans << "\n";
  return 0;
}

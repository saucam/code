#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int t;
  cin >> t;
  while(t--) {
    int n, a, s, root = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
      cin >> a >> s;
      root = root + (a - s);
    }
    cout << root << "\n";
  }
  return 0;
}

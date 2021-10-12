#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int ans = n;
    for(int p=1;p<=sqrt(n);p++) {
      if (n % p == 0) {
        if (n/p <= k) ans = min(ans, p);
        if (p <= k) ans = min(ans, n/p);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

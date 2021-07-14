#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int d, x, y, z;
    cin >> d >> x >> y >> z;
    cout << max(7 * x, d * y + z* (7 - d)) << "\n";
  }
  return 0;
}

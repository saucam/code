#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    long long c, g;
    cin >> g >> c;
    cout << (c * c) / (2 * g) << "\n";
  }
  return 0;
}

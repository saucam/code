#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n;
  cin >> n;
  vector<int> v(n);
  int odd = 0, even = 0, k=1, fodd = 0, feven = 0;
  for(int &e: v) {
    cin >> e;
    if ((e & (0x01)) == 1) { if (odd == 0) { fodd = k; } odd++; } else { if (even == 0) { feven = k; } even++; }
    if (odd == 1 && even > 1) { cout << fodd << "\n"; break; } else if (even == 1 && odd > 1) { cout << feven << "\n"; break; }
    k++;
  }

  return 0;
}

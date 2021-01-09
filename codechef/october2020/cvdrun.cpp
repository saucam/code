#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    if (k == 0) cout << "NO" << "\n";
    else if (k == 1) cout << "YES" << "\n";
    else if (n % k == 0) {
      if (((x+1) % k) == ((y+1) % k)) cout << "YES" << "\n"; else cout << "NO" << "\n";
    } else {
      cout << "YES" << "\n";
    } 
  }
  return 0;
}

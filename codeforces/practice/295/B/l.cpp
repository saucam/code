#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n, m;
  cin >> n >> m;
  int d = 0;
  if (m == n) {
    cout << "0\n";
  } else {
    if (m > n) {
        while ( m > n) { 
          if (m % 2 == 1) d++;
          d++; 
          m = ((m + 1) / 2); 
        }
      }
      d += (n - m);
      cout << d << "\n";
  }
  return 0;
}

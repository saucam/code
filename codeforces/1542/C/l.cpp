#include <bits/stdc++.h>

using namespace std;

const long long m = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    n = n % m;
    if (n == 1) { ans = 2;}
    else {
      long long odd = n %2 == 0? n / 2: (n + 1) /2;
      ans = (((odd) % m) * 2 )%m + (((n / 6) %m - (n / 12) %m)* 4) % m + (((n / 2) %m - (n / 6) % m) * 3)%m + (((n/ 12)%m ) * 5) %m; }
    cout << ans << "\n";
  }
  return 0;
}

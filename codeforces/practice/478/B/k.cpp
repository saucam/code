#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  long long n, m;
  cin >> n >> m;
  long long r = n % m;
  long long k = n / m;
  long long mi = (r* k * (k+1)) / 2 + ((m - r) * k * (k - 1)) / 2;
  long long mx = ((n - (m - 1)) * (n - m)) / 2;
  cout << mi << " " << mx << "\n";
  return 0;
}

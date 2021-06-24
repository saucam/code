#include <bits/stdc++.h>

using namespace std;

long long mul(long long a, long long b, long long n) {
  return ((a % n) * (b % n)) % n;
}

int main() {
  long long a, b, m;
  cin >> a >> b >> m;
  long long ans = 1;
  while(b > 0) {
    if ((b & 1) == 1) {
       b = b - 1;
       ans = mul(ans, a, m);
    } else {
       a = mul(a, a, m);
       // ans = mul(ans, a, m);
       b = (b >> 1);
    }
  }
  cout << ans << "\n";
  return 0;
}

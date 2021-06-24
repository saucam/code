#include <bits/stdc++.h>

using namespace std;

long long calc(long long n) {
   if (n == 0) return 0;
   if (n == 1) return 1;
   long long t = calc(n / 2);
   if ((n & 1) == 0) {
     return t;
   } else {
     return (t + calc(n + 1));
   }
}

int main() {
  long long n;
  cin >> n;
  long long ans = calc(n);

  cout << ans << "\n";
  return 0;
}

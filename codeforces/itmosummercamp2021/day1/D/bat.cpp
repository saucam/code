#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, p;
  cin >> t >> p;
  double ans = 0.0;
  if (p >= 20 ) {
    double rate = ((t * 1.0) / (100.0 - p));
    ans = ans + (rate * (p - 20.0)) + ((2.0 * rate) * (20.0));
  } else {
    ans = (2.0 * t * p) / (80.0 + 2.0 * (20.0 - p));
  }
  printf("%.4f", ans);
  return 0;
}

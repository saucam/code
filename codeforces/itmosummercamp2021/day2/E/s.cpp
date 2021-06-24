#include <bits/stdc++.h>

using namespace std;

double f(double x) {
  return sqrt(x) + (x * x);
}

int main() {
  double c;
  cin >> c;

  double l = 1.0;
  double r = c;
  double e = 0.000001;
  double ans = 0.0;
  for (int i = 0; i < 10000; i++) {
     double mid = (l + r) / 2.0;
     ans = mid;
     if ((f(ans) - c) > e) {
        r = mid;
     } else {
        l = mid;
     }
  }
  printf("%.6f", ans);
  return 0;
}

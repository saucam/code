#include <bits/stdc++.h>

using namespace std;

double power(double a, int n) {
  double ans = 1.0;
  while (n > 0) {
    if (n % 2 != 0) {
       ans = a * ans;
    }
    a = a * a;
    n = n / 2;
  }
  return ans;
}

int main() {
  int n, m;
  double ans = 0.0;
  cin >> m >> n;
  for (int i=1; i<=m; i++) {
    ans = ans + (i*(power((1.0*i)/m, n) - power(((1.0*i)-1)/m, n)));
  }
  printf("%f\n", ans);
  return 0;
}

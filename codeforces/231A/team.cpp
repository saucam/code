#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  while (n > 0) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c >= 2) ans++;
    n--;
  }
  printf("%d\n", ans);
  return 0;
}

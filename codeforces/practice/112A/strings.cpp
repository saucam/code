#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b;
  int ans;
  cin >> a >> b;
  transform(a.begin(), a.end(), a.begin(), ::toupper);
  transform(b.begin(), b.end(), b.begin(), ::toupper);
  if (a < b) ans = -1; else if (b < a) ans = 1; else ans = 0;
  printf("%d\n", ans);
  return 0;
}

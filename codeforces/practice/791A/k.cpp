#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int a, b;
  cin >> a >> b;
  int ans = 0;
  while(a <= b) {
    a = 3 * a;
    b = 2 * b;
    ans++;
  }
  cout << ans;
  return 0;
}

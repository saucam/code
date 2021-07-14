#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  vector<int> s = {4, 7, 44, 77, 47, 74, 444, 447, 474, 744, 477, 747, 774, 777};
  int n;
  cin >> n;
  bool ans = false;
  for(int r: s) {
    if (n%r == 0) {
       ans = true;
       break;
    }
  }
  if (ans) cout << "YES\n"; else cout << "NO\n";
  return 0;
}

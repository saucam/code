#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int t;
  cin >> t;
  while(t--) {
    for(int i=0; i<9; i++) {
      string s;
      cin >> s;
      replace(s.begin(), s.end(), '1', '2');
      cout << s << "\n";
    }
  }
  return 0;
}

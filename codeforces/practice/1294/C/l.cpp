#include <bits/stdc++.h>

using namespace std;

pair<int, int> getDivs(int x) {
  for(int j=2;j<=sqrt(x);j++) {
    if (x%j == 0) {
      if (x/j != j) {
        return {j, x/j};
      }
    }
  }
  return {0, 0};
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int t;
  cin >> t;
  while(t--) {
    int n;
    bool f = false;
    cin >> n;
    for(int j=2; j<=sqrt(n);j++) {
      if (n%j == 0) {
        pair<int, int> bc = getDivs(n/j);
        if (bc.first != 0 && bc.first != j && bc.second != j) {
          cout <<"YES\n";
          cout << j << " " << bc.first << " " << bc.second << "\n";
          f = true;
          break;
        }
      }
    }
    if (!f) cout << "NO\n";
  }
  return 0;
}

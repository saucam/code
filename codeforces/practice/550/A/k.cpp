#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  string s;
  cin >> s;
  int k=0;
  int n = s.size();
  vector<pair<int, int>> ab;
  vector<pair<int, int>> ba;
  while(k < n - 1) {
      if (s[k] == 'A' && s[k + 1] == 'B') {
        ab.push_back({k, k+1});
      }
      if (s[k] == 'B' && s[k + 1] == 'A') {
        ba.push_back({k, k+1});
      }
      k++;
  }
  bool found =false;
  for(int i=0; i<ab.size(); i++) {
    for (int j=0; j<ba.size(); j++) {
      if (abs(ab[i].first - ba[j].first) > 1) {
        found = true;
        break;
      }
    }
  }
  if (found) cout << "YES\n"; else cout << "NO\n";
  return 0;
}

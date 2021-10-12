#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int m, s;
  cin >> m >> s;
  vector<int> v(m, 0);
  int d = 0, i=0;
  while(s > 0) {
    for (d = 9; d>=1; d--) {
      if (s >= d) break;
    }
    v[i] = d;
    s -= d;
    i++;
    if (i >= v.size()) break;
  }
  if (v[0] == 0 && m == 1 && s == 0) cout << "0 0" << "\n"; else if (v[0] == 0 || s != 0) cout << "-1 -1" << "\n"; else {
    ostringstream s;
    for(auto &e: v) {
      s << e;
    }
    
    reverse(v.begin(), v.end());
    if (v[0] == 0) {
      v[0] = 1;
      int i = 1;
      while(i < v.size() && (v[i] == 0)) i++;
      v[i]--;
    }
    for(auto &e: v) {
      cout << e;
    }
    cout << " " << s.str();
    cout << "\n";
  }
  return 0;
}

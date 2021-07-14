#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  map<string, int> m;
  cin >> n;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    if (m.find(s) != m.end()) {
      int t = m[s];
      m[s]++;
      cout << s << t + 1 << "\n"; 
    } else {
      m.insert({s, 0});
      cout << "OK\n";
    }
  }
  return 0;
}

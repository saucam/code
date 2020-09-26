#include <bits/stdc++.h>

using namespace std;

int getMostSig(int a) {
  int k = 0;
  while(a > 0) {
    a = (a >> 1);
    k++;
  }
  return k;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &a: v) cin >> a;
    long long ans = 0;
    map<int, long long> m; 
    for(auto k: v) {
      int s = getMostSig(k);
      if (m.find(s) != m.end()) {
        m[s] = m[s] + 1;      
      } else {
        m[s] = 1;
      }
    }
    for(auto const& k: m) {
      ans = ans + (k.second * (k.second - 1))/2;
    }
    cout << ans << "\n";
  }
  return 0;
}

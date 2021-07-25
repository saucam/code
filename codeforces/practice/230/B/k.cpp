#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n;
  cin >> n;
  set<long long> s;
  vector<int> v(1e6 + 1, 0);
  for(int i=2; i<=1001; i++) {
    if (v[i] == 0) {
      for(int j=2; j*i <=1e6; j++) {
        v[i*j] = 1;
      }
    }
  }
  for(long long i=2; i<=1e6; i++) {
    if (v[i] == 0) {
      s.insert(i*i);
    }
  }
  for(int i=0; i<n; i++) {
    long long a;
    cin >> a;
    string ans = (s.find(a) != s.end()) ? "YES": "NO";
    cout << ans << "\n";
  }
  return 0;
}

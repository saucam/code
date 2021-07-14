#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n, t;
  cin >> t;
  while(t--) {
    cin >> n; 
    vector<int> v(n);
    for(auto &e: v) {
      cin >> e;
    }
    long long ans = 0;
    sort(v.begin(), v.end());
    for(int i=0; i<n-1; i++) {
      ans += (n-i-1)*v[i] - (i)*v[i];
    }
    cout << ans - v[n - 1] << "\n";
  }
  return 0;
}

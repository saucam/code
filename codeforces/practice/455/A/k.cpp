#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n, e;
  cin >> n; 
  vector<pair<int, int> > v;
  map<int, int> m;
  vector<long long> dp(n, 0);
  for(int i=0; i<n; i++) {
    cin >> e;
    m[e]++;
  }
  for(const pair<int, int>& p: m ) {
     v.push_back(p);
  }
  
  // dp[0] = 0;
  dp[0] = 1LL * v[0].second * v[0].first;
  for(int i=1; i<v.size();i++) {
    int prv = (v[i - 1].first + 1 == v[i].first)? i - 2: i - 1;
    if (prv >= 0) dp[i] = dp[prv];  
    dp[i] += (1LL * v[i].first * v[i].second);
    dp[i] = max(dp[i - 1], dp[i]);
  }
  cout << dp[v.size() - 1] << "\n";

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> v = { a, b, c };
  sort(v.begin(), v.end());
  vector<int> dp(n + v[2] + 1, 0);
  for(int e: v) {
    dp[e] = 1;
  }
  int k = 0;
  while(k < n+1 ) {
    for(int e: v) {
      if (dp[k] > 0) {
        dp[k + e] = max(dp[k] + 1, dp[k + e]);
      }
    }
    k++;
  }
  cout << dp[n] << "\n";
  return 0;
}

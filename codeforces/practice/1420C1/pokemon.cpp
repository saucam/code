#include <bits/stdc++.h>
#include <array>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for(auto &a: v) cin >> a;
    // positive is 0, negative is 1
    // vector<array<int, 2> > dp(n, { 0, 0 } );
    long long dp[300000][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = v[0];
    dp[0][1] = 0;
    if (n > 1) {
      dp[1][0] = max(dp[0][0], v[1]);
      dp[1][1] = max(dp[0][1], dp[0][0] - v[1]);
    }
    for(int k=2;k<n;k++) {
      dp[k][0] = max(dp[k - 1][0], dp[k - 1][1] + v[k]);
      dp[k][1] = max(dp[k - 1][1], dp[k - 1][0] - v[k]);
    }
    long long ans = max(dp[n -1][0], dp[n-1][1]);
    printf("%lld\n", ans);
  }
  return 0;
}

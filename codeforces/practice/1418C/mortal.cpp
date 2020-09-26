#include <bits/stdc++.h>

using namespace std;

int dp[200000][2];
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    int a[200001];
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    memset(dp, 0, 200001);
    if (a[0] == 1) dp[1][0] = 1; else dp[1][0] = 0;
    dp[1][1] = dp[1][0];
    dp[2][0] = dp[1][0] + a[1]; 
    dp[2][1] = dp[1][0];
    // assuming 0 is friend, 1 is me
    for (int k=3; k<=n; k++) {
      dp[k][0] = min(dp[k - 1][1] + a[k-1], dp[k - 2][1] + a[k-1] + a[k-2]);
      dp[k][1] = min(dp[k-1][0], dp[k-2][0]);
    }
    int ans = min(dp[n][0], dp[n][1]);
    printf("%d\n", ans);
    t--;
  }
  return 0;
}

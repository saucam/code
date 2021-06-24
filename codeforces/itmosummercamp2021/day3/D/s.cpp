#include <bits/stdc++.h>

using namespace std;

int dp[1002][1002];
int main() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();
  int c = 0;
  dp[0][0] = 0;

  for (int i=0; i<=n; i++) dp[i][0] = i;
  for (int j=0; j<=m; j++) dp[0][j] = j;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      dp[i][j] = 10000;
      dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
      dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        if (a[i] == b[j]) {
          c = 0 ;
        } else {
          c = 1;
        }
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + c);
    }    
  }

  cout << dp[n][m];
  return 0;
}

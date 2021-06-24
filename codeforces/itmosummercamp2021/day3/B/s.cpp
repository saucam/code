#include <bits/stdc++.h>

using namespace std;

int dp[1002][1002];
int t[1002][1002];
int main() {
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0;j<m; j++) {
      cin >> t[i][j];
    }
  }

  // init
  for(int i=0; i<=n; i++) {
    for(int j=0;j<=m; j++) {
      dp[i][j] = 100000000;    
    }
  }
  dp[0][0] = 0;
  dp[0][1] = 0; dp[1][0] = 0;   
  dp[1][1] = t[0][0];
  for(int i=1; i<=n; i++) {
    for(int j=1;j<=m; j++) {
      dp[i][j] = t[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);    
    }
  }
 
  cout << dp[n][m];
  return 0;
}

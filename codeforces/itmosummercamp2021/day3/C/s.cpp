#include <bits/stdc++.h>

using namespace std;

int dp[1002][101];
int w[101];
int c[101];
int pr[1002][102];
int main() {
  int n, W;
  cin >> n >> W;
  for(int i=0; i<n; i++) {
    cin >> w[i];
  }

    for(int j=0;j<n; j++) {
      cin >> c[j];
    }

  // init
  for (int j=0; j<n;j++) {
    dp[0][j] = 0;
  }
  for (int k=0; k<=W;k++) {
    dp[k][0] = 0;
  }

  pr[0] = -1;
  for(int i=1; i<=W; i++) {
    for(int j=1;j<=n; j++) {
      if (w[j - 1] < i) {
        int include = dp[ i - w[j - 1]][j - 1] + c[j - 1];
        if (include > dp[i][j - 1]) {
          dp[i][j] = include;
          pr[i][j] = j - 1;
        } else {
          pr[i][j] = pr[i][j - 1];
          dp[i][j] = dp[i][j - 1]; 
        }
        // dp[i][j] = max(dp[i - w[j - 1]][j - 1] + c[j - 1], dp[i][j - 1])
      }
    }
  }
  cerr << dp[W][n] << "\n";
  vector<int> l;
  int last = n; 
  while(last >= 0) {
    if (pr[last] != pr[last-1]) {
      l.push_back(last);
    }
    last = pr[last];
  }
  cout << l.size() << "\n";
  for(int p=l.size()-1;p>=0;p--) {
    cout << l[p] << " ";
  }
  return 0;
}

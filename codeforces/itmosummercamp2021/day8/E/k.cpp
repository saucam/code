#include <bits/stdc++.h>

using namespace std;

int dp[(1 << 14) - 1][14];
const int INF = 1e8;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  
  int n;
  cin >> n; 
  vector<vector<int>> g(n, vector<int>(n));
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<int>> dp(1 << n, vector<int>(n, INF));
 vector<vector<pair<int, int>>> prv( (1 << n), vector<pair<int, int>>(n));
 for(int i=0; i< n; ++i) {
   dp[1 << i][i] = 0;
   prv[1<<i][i] = {-1, -1};
 }
 
 for(int mask = 1; mask < (1 << n); mask++) {
   for(int v=0; v<n; v++) {
     if (mask & (1 << v)) {
       for (int u =0; u< n; u++) {
         if (!(mask & (1 << u))) {
           int nmask = (mask | (1 << u));
           if (dp[mask][v] + g[u][v] < dp[nmask][u]) {
             dp[nmask][u] = dp[mask][v] + g[u][v];
             prv[nmask][u] = {mask, v};
           }
         }
       }
     }
   }
  }
  int ans = INF;
  int last = -1;
  for(int v=0; v<n; v++) {
    if (ans > dp[(1 << n) - 1][v]) {
      ans = dp[(1 << n) - 1][v];
      last = v;
    }
  }
  
  int mask = ((1 << n) - 1);
  vector<int> order;

  while(last != -1) {
    order.push_back(last);
    tie(mask, last) = prv[mask][last]; 
  }

  cout << ans << "\n";
  for(int i=order.size()-1; i>=0; i--) { cout << order[i]+1 << " "; }
  cout << "\n";
 
  return 0;
}

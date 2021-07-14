#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<pair<int, int>> &dp, vector<vector<int>> &g, vector<int> &w) {
    dp[v].first = 0;
    dp[v].second = w[v];
    for (int u: g[v]) {
      dfs(u, dp, g, w);
      dp[v].first += max(dp[u].first, dp[u].second);
      dp[v].second += dp[u].first;
    }

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int > w(n);
  int root = -1;
  for(int i=0; i< n; i++) {
    int p;
    cin >> p >> w[i];
    if (p == 0) {
      root = i;
    } else {
      --p;
      g[p].push_back(i);
    }
  }
  vector<pair<int, int>> dp(n);
  dfs(root, dp, g, w);
  cout << max (dp[root].first, dp[root].second) << "\n";

  return 0;
}

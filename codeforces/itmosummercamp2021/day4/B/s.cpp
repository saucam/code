#include <bits/stdc++.h>

using namespace std;

int cc[100001];
void dfs(vector<vector<int>> &g, int u, int k) {
  cc[u] = k;
  for (auto v: g[u]) {
    if (cc[v] == 0) {
      dfs(g, v, k);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  int a, b;
  for (int i = 0 ; i < m; i ++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int k=1;
  for (int i=1; i<=n; i++) {
    if (cc[i] == 0) {
      dfs(g, i, k);
      k++;  
    }
  }

  cout << k-1 << "\n";
  for(int i=1; i<=n; i++) {
    cout << cc[i] << " ";
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int cc[100001];
bool isB = true;
void dfs(vector<vector<int>> &g, int u, int color) {
  cc[u] = color;
  for (auto v: g[u]) {
    if (cc[v] == -1) {
      dfs(g, v, 1-color);
    } else if (cc[v] == color) {
      isB = false;
      return;
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
  for (int i = 1; i<=n; i++) cc[i] = -1;
  int color=0;
  for (int i=1; i<=n; i++) {
    if (cc[i] == -1) {
      dfs(g, i, color);  
    }
  }

  if (isB) {
    cout << "YES" << "\n"; 
    for(int i=1; i<=n; i++) {
      cout << cc[i]+1 << " ";
    }
  } else {
    cout << "NO";
  }
  return 0;
}

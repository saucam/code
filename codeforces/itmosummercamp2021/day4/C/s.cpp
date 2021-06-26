#include <bits/stdc++.h>

using namespace std;

int cc[100001];
int ind[100001];
vector<int> order;

void dfs(vector<vector<int>> &g, int u) {
  cc[u] = 1;
  for (auto v: g[u]) {
    if (cc[v] == 0) {
      dfs(g, v);
    }
  }
  order.push_back(u);
}

int main() {
  int n, m;
  bool cycle = false;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  int a, b;
  for (int i = 0 ; i < m; i ++) {
    cin >> a >> b;
    g[a].push_back(b);
  }
  for (int i=1; i<=n; i++) {
    if (cc[i] == 0) {
      dfs(g, i);
    }
  }

  for(int i=n-1; i>=0; i--) {
    ind[order[i]] = n - 1 - i;
  }

  for (int i=1; i<=n; i++) {
    for (auto v: g[i]) {
       if (ind[i] >= ind[v]) {
          cycle = true;
          break;
       }
    }
  }

  if (cycle) {
    cout << "-1";
  } else {
    for(int i=n-1; i>=0; i--) {
      cout << order[i] << " ";
    }
  }
  return 0;
}

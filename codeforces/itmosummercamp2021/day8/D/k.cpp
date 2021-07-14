#include <bits/stdc++.h>

using namespace std;
long long large = 100000000000;
long long sp[100001];
int cc[100001];
vector<int> order;
void dfs(vector<vector<pair<int, int>>> &g, int u) {
  cc[u] = 1;
  for (auto v: g[u]) {
    if (cc[v.first] == 0) {
      dfs(g, v.first);
    }
  }
  order.push_back(u);
}

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<pair<int, int>>> g(n + 1);
  int a, b, weight;
  for (int i = 0 ; i < m; i ++) {
    cin >> a >> b >> weight;
    g[a].push_back({b, weight});
  }
  
  for(int i=1; i<=n; i++) {
    sp[i] = large;
  }

  // run dfs from s
  dfs(g, s);
  for (int i=1; i<=n; i++) {
    if ((i != s) && cc[i] == 0) {
      dfs(g, i);  
    }
  }

  int k = n;
  for(k = n-1; order[k] != s; k--) {
  //  sp[order[k]] = ((-1)*large);
  }
  sp[order[k]] = 0;
  for(int i=k; i>=0; i--) {
    int node = order[i];
    for(auto v: g[node]) {
       sp[v.first] = min(sp[v.first], sp[node] + v.second);
    }
  }
  if (sp[t] == large) cout << "Unreachable"; else cout << sp[t];
  cout << "\n";
  return 0;
}

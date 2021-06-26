#include <bits/stdc++.h>

using namespace std;
long long large = 10000000000;
long long sp[100001];
int cc[100001];
vector<int> order;
map<pair<int, int>, int> w;
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
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<int>> g(n + 1);
  int a, b, weight;
  for (int i = 0 ; i < m; i ++) {
    cin >> a >> b >> weight;
    g[a].push_back(b);
    w.insert(make_pair(make_pair(a, b), weight));
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
  for(k = n; order[k] != s; k--) {
    sp[order[k]] = -1;
  }
  sp[order[k]] = 0;
  cerr << "k = " << k << "\n";
  for (int i=n; i>=1; i--) cerr << order[i] << " ";
  for(int i=k; i>=1; i--) {
    for(auto v: g[order[i]]) {
       sp[v] = min(sp[v], sp[i] + w[make_pair(order[i], v)]);
    }
  }
  if (sp[t] == -1) cout << "Unreachable"; else cout << sp[t];
  return 0;
}

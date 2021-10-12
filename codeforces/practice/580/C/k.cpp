#include <bits/stdc++.h>

using namespace std;

int ans = 0;
void dfs(int k, int m, int scats, vector<vector<int>> &g, vector<int> &v, vector<int> &cats) {
  v[k] = 1;
  int pathcats = scats + 1;
  bool isLeaf = true;
  if (cats[k] == 0) { pathcats=0; }
  if (pathcats <= m ) {
    for(int n: g[k]) {
      if (v[n] == 0) {
        isLeaf = false;
        dfs(n, m, pathcats, g, v, cats);
      }
    }
    if (isLeaf) ans++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n, m;
  cin >> n >> m;
  vector<int> cats(n+1);
  vector<int> v(n + 1, 0);
  for(int i=1; i<=n; i++) {
    cin >> cats[i];
  }
  vector<vector<int>> g(n+1);
  for(int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, m, 0, g, v, cats);
  cout << ans << "\n";
  return 0;
}

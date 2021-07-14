#include <bits/stdc++.h>

using namespace std;

int logn;
vector<int> calcDepth(vector<int> &p) {
  vector<int> d(p.size());
  d[0] = 0;
  for(int i=1; i<p.size(); i++) {
    d[i] = d[p[i]] + 1;
  }
  return d;
}

vector<vector<int>> pre(vector<int> &p) {
  logn = 1;
  int n = p.size();
  while( (1 << logn) <= n) logn++;
  vector<vector<int>> jmp(p.size(), vector<int>(logn));
  for (int i=0; i<n; i++) {
    jmp[i][0] = p[i];
  }
  jmp[0][0] = 0;
  for(int k= 1; k<logn; k++) {
    for (int i=0; i<n; i++) {
      jmp[i][k] = jmp[jmp[i][k-1]][k - 1];
    }
  }
  return jmp;
}

int lca(int u, int v, vector<vector<int>> & jmp, vector<int> &d) {
  if (d[u] < d[v]) {
    swap(u, v);
  }
  int delta = d[u] - d[v];
  for (int k = logn - 1; k >= 0; k--) {
     if (delta >= (1 << k)) {
       u = jmp[u][k];
       delta -= (1 << k);
     }
  }
  if (u == v) return u;

  for(int k=logn - 1; k >= 0; k--) {
    int u_ = jmp[u][k];
    int v_ = jmp[v][k];
    if (u_ != v_) {
      u = u_;
      v = v_;
    }
  }
  return jmp[u][0];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n, m;
  cin >> n; 
  vector<int> p(n);
  p[0] = -1;
  for(int i=1; i< n; i++) {
    cin >> p[i];
    p[i]--;
  }
  vector<int> d = calcDepth(p);
  vector<vector<int>> jmp = pre(p);
  cin >> m;
  for(int i=0; i< m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    cout << lca(u, v, jmp, d) + 1<<"\n";
  }
  return 0;
}

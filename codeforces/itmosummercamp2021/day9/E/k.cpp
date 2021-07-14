#include <bits/stdc++.h>

using namespace std;

const int DRAW = 1;
const int LOSE = 0;
const int WIN = 2;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n, m;
  while( cin >> n >> m) {
    
  vector <vector<int>> gr(n);
  vector<int> deg(n);
  vector<int> losing(n, 0);

  for (int i=0; i< m; i++) {
    int from, to;
    cin >> from >> to;
    --from; --to;
    gr[to].push_back(from);
    deg[from]++;
  }
  queue<int> q;
  vector<int> g (n, DRAW);
  for (int i=0; i<n; i++) {
    if (deg[i] == 0) {
      g[i] = LOSE;
      q.push(i);
    }
  }
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(int u: gr[v]) {
      if (g[u] != DRAW) continue;
      if (g[v] == LOSE) {
        g[u] = WIN;
        q.push(u);
      }
      if (g[v] == WIN) {
        losing[u]++;
        if (losing[u] == deg[u]) {
          g[u] = LOSE;
          q.push(u);
        }
      }
    }
  }
  for (int i=0; i<n; i++) {
    if (g[i] == WIN) {
      cout << "FIRST\n";
    } else if (g[i] == LOSE) {
      cout << "SECOND\n";
    } else {
      cout << "DRAW\n";
    }
  }
  cout << "\n";
  }
  return 0;
}

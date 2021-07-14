#include <bits/stdc++.h>

using namespace std;

const int WIN = 2;
const int DRAW = 1;
const int LOSE = 0;

bool dfs(vector<vector<int>> &gr, vector<int> &vis, vector<int> &win, int v) {
  if (vis[v]) {
    return win[v];
  }
  vis[v] = true;
  win[v] = false;

  for(int u: gr[v]) {
    if (!dfs(gr, vis, win, u)) {
      win[v] = true;
      break;
    }
  }
  return win[v];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  vector <vector<int>> gr(n);
  vector <int> vis(n, 0);
  vector <int> win(n, false);
  for (int i=0; i< m; i++) {
    int from, to;
    cin >> from >> to;
    --from; --to;
    gr[from].push_back(to);
  }

  dfs(gr, vis, win, s - 1);

    if (win[s - 1]) {
      cout << "First player wins\n";
    } else {
      cout << "Second player wins\n";
    }
  return 0;
}

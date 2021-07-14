#include <bits/stdc++.h>

using namespace std;


const int WIN = 2;
const int DRAW = 1;
const int LOSE = 0;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  cin >> n;
  vector <vector<int>> incoming(n + 1);
  vector<int> deg(n + 1);
  vector<int> losing(n + 1, 0);

  for(int i=1; i<=n; i++) {
    int from = i;
    incoming[i - 1].push_back(from);
    deg[from]++;
    if (i % 3 == 0) {
      if (i > 1) {
        incoming[i - 2].push_back(from);
        deg[from]++;
      }
    } else if (i % 3 == 1) {
     if (i > 2) {
       incoming[i - 3].push_back(from);
       deg[from]++;
     }
    } else if (i % 3 == 2) {
      if (i > 2) {
       incoming[i - 3].push_back(from);
       deg[from]++;
      } if (i > 1) {
        incoming[i - 2].push_back(from);
        deg[from]++;
      }
    }
  }
   
  queue<int> q;
  vector<int> g (n + 1, DRAW);
  g[0] = LOSE;
  q.push(0);
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(int u: incoming[v]) {
      // if (g[u] != DRAW) continue;
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
    if (g[n] == WIN) {
      cout << "1\n";
    } else if (g[n] == LOSE) {
      cout << "2\n";
    }
  return 0;
}

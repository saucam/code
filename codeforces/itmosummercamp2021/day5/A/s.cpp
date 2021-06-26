#include <bits/stdc++.h>

using namespace std;

int g[1001][1001];
int d[1001];

int main() {
  int n, s;
  cin >> n >> s;
  int a, b;
  queue<int> q;
  for (int i = 1 ; i <= n; i ++) {
    for (int j = 1 ; j <= n; j ++) {
      cin >> a;
      g[i][j] = a;
    }
  }
 
  for(int i=1; i<=n;i++) {
    d[i] = -1;
  }
 
  d[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int k = q.front();
    q.pop();
       for (int i=1; i<=n; i++) {
         if (g[k][i] == 1) {
            if (d[i] == -1) {
               d[i] = d[k] + 1;
               q.push(i);
            }
         }
       }
  }
  for (int i=1; i<=n; i++) {
    cout << d[i] << " ";
  }
  return 0;
}

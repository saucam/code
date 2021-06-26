#include <bits/stdc++.h>

using namespace std;

unsigned long long d[2001];
int  g[2001][2001];
int main() {
  int n, s, f;
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin >> n >> s >> f;
  for(int i = 1; i<=n; i++ ) {
    for (int j=1; j<=n; j++) {
      cin >> g[i][j];
    }
  }

  for(int i=1; i<=2001;i++) {
    d[i] = 9223372036854775807;
  }
 
  d[s] = 0l;
  bool relax = true;
  // Using Dijkstra
   for (int k=1; k<=n;k++) {
     relax = false;
    for (int i = 1; i <= (n); i++) {
      for (int j = 1; j<= (n); j++) {
        if (g[i][j] >= 0) {
          if (d[j] > (d[i] + g[i][j])) {
            d[j] = d[i] + g[i][j];
            relax = true;
          }
        }
      }
    }
    if (!relax) break;
  } 
 

  if (d[f] == 9223372036854775807) cout << "-1"; else cout << d[f];
  return 0;
}

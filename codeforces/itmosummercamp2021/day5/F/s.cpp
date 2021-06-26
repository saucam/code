#include <bits/stdc++.h>

using namespace std;

int g[101][101];
long long d[101][101];

int main() {
  int n;
  cin >> n;
  int a, b;
  for (int i = 1 ; i <= n; i ++) {
    for (int j = 1 ; j <= n; j ++) {
      cin >> a;
      g[i][j] = a;
    }
  }
 
  for(int i=1; i<=n;i++) {
    for(int j=1; j<=n;j++) {

      if (i == j) {
        d[i][i] = 0; 
      } else d[i][j] = g[i][j];
  }

  for (int k=1; k<=n k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i=1; i<=n; i++) {
    for (int j=1; i<=n; j++) {
    cout << d[i][j] << " ";
  }
    cout << "\n";
  }
  return 0;
}

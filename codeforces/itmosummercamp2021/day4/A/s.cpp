#include <bits/stdc++.h>

using namespace std;

int mat[101][101];
int main() {
  int n, m;
  cin >> n >> m;
  int a, b;
  for (int i = 0 ; i < m; i ++) {
    cin >> a >> b;
    mat[a][b] = 1;
    mat[b][a] = 1;
  }
  for (int i=1; i<=n; i++) {
    for (int j = 1; j<=n; j++) {
      cout << mat[i][j] << " ";
    }    
    cout << "\n";
  }

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector<long long> pw;
vector<long long> twpw;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  long long n, m, az, u, v, r;
  cin >> n >> m >> az;
  cin >> u >> v;
  pw.assign(n, 0);
  pw[1] = 1;
  twpw.assign(n, 1);
  twpw[0] = 1;
  twpw[1] = 2;
  for (int i = 2; i<=n; i++) {
    pw[i] = pw[i - 1];
    if ((2 * (1 << pw[i])) <= i) pw[i]++;
    twpw[i] = twpw[i - 1]*2;
  }

  for (int i=) cerr << "pw["<<
  vector<vector<long long>> t(n);
  t[0] = {az};
  for(int i=1; i<n; i++) {
    int k = pw[i];
    vector<long long> v(k);
    v[0] = az;
    t[i] = v; 
    for(int j=1; (i + twpw[j])<=n; j++ ) {
      t[i][j] = min(t[i][j - 1], t[i + twpw[j - 1]][j - 1]);
    }
  }
  
  for(int i=0; i<m; i++) {
    int k = pw[v];
    r = min(t[u][k], t[v - twpw[k] + 1][k]);
    u = ((17 * u)%n + 751 + r%n + 2*i) %n + 1;
    v = ((13 * v)%n + 593 + r%n + 5*i) %n + 1;
  }
  cout << u << " " << v << r << "\n";

  return 0;
}

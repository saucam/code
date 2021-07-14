#include <bits/stdc++.h>

using namespace std;

vector<unsigned long long> a;
vector<unsigned long long> prf;
unsigned long long mod = (1 << 16);
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  unsigned long long n, x, y, az;
  cin >> n >> x >> y >> az;
  unsigned long long m, z, t, bz;
  cin >> m >> z >> t >> bz;
  a.assign(n, 0);
  prf.assign(n, 0);
  unsigned long long mod2 = 1;
  for(int i=0; i<30; i++) {
    mod2 = mod2*2;
  }
  a[0] = az;
  prf[0] = az;
  for(int i=1; i<n; i++) {
    a[i] = (((x%mod*(a[i-1]%mod))%mod) + y)%mod;
    prf[i] = prf[i - 1] + a[i];
  }
  
  unsigned long long ans = 0;
  unsigned long long bz1 = ((((z%mod2)*(bz%mod2))%mod2) + t + mod2)%mod2;
  unsigned long long cz = bz%n;
  unsigned long long cz1 = bz1%n;
  unsigned long long l, r;
  for(int i=0; i<m; i++) {
    if (cz < cz1) {l = cz; r = cz1;} else {l = cz1; r = cz;}
    if (l == 0) ans += prf[r]; else ans += (prf[r] - prf[l - 1]);
    bz = ((((z%mod2)*bz1)%mod2) + t + mod2)%mod2;
    bz1 = ((((z%mod2)*bz)%mod2) + t + mod2)%mod2;
    cz = bz%n;
    cz1 = bz1%n;
  }
  cout << ans << "\n";
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int lim = 1e5 + 1;
long long pw(long long a, long long b) {
  long long ans = 1;
  while(b > 0) {
    if ((b%2) == 1) ans = ((ans * a)%mod);
    a = ((a * a)%mod);
    b = (b/2);
  }
  return ans;
}

long long genPal(int num) {
  int n = num;
  long long p = num;
  n/=10;
  while(n > 0) {
    p = p * 10 + (n % 10);
    n/=10;
  }
  return p;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  vector<long long> c(lim);
  c[0] = 0;
  for(int i=1; i< lim; i++) {
    c[i] = genPal(i);
  }
  sort(c.begin(), c.end());
  vector<long long> pf(lim, 0);
  for(int k=1; k< lim; k++) {
    pf[k] = pf[k - 1] + c[k];
  }
  // for(int k=1; k<(1e5 + 1); k++) cout << "c["<<k<<"] = " << c[k]<<" ";
  int t;
  cin >> t;
  while(t--) {
    int l, r;
    cin >> l >> r;
    long long s = pf[r] - pf[l];
    cout << pw(c[l] %mod, s) << "\n";
  }
  return 0;
}

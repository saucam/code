#include <bits/stdc++.h>

using namespace std;

/*int bin(vector<int> &p, int l, int r, int t, int i) {
  if (l == (r - 1)) return l;
  cerr << "l = " << l << " r = " << r; 
  int m = (l + r) / 2;
  int st = 0;
  if (i > 0) st = p[m] - p[i - 1]; else st = p[m];
  if (t < st) return bin(p, l, m + 1, t, i);
  else return bin(p, m + 1, r, t, i);
}*/

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  long long s = 0;
  int i = 0;
  for(int &e: v) {
    cin >> e;
    s += e;
  }
  if (t >= s) { 
    cout << n << "\n";  
  } else {
    int m = 0, st = 0;
    long long cs = 0;
    for(int i=0; i< n - 1; i++) {
      while (st <n && (cs + v[st]) <= t) { cs += v[st]; st++; }
      if ( st - i > m) m = st - i;
      if (st == n) break;
      cs -= v[i];
      //int lp = bin(p, i + 1, n, t, i);
      //if (m < (lp - i + 1)) m = (lp - i + 1);
    }
    cout << m << "\n";
  }
  return 0;
}

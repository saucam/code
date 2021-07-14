#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();
vector<int> t;
int x;
void buildTree(vector<int> &a) {
  x = 1;
  int n = a.size();
  while(x < n) {
    x *= 2;
  }
  t.assign(2 * x - 1, INF);
  int cnt = 1;
  for (int i=0; i< n; i++) {
    t[i + x - 1] = (a[i] * (cnt));
    cnt = cnt * -1;
  }
  for (int v=x - 2; v >=0; v--) {
    t[v] = t[2*v +1] + t[2*v + 2];
  }
}

void st(int i, int y) {
  t[i + x - 1] = t[i + x - 1] > 0? y:y * (-1);
  int v = i + x - 1;
  while(v != 0) {
    v = (v - 1) / 2;
    t[v] = t[2*v + 1] + t[2*v + 2];
  }
}

int rsq(int v, int l, int r, int a, int b) {
  if (l > b || r < a) return 0;
  if (l >= a && r <= b) return t[v];

  int m = (l + r) /2;
  return rsq(2*v + 1, l, m, a, b) + rsq(2*v+2, m+1, r, a, b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n, m;
  cin >> n;
  vector<int > a(n);
  for(auto &e: a) {
    cin >> e;
  }
  buildTree(a);
   
  int q, d, r;
  cin >> m;
  for( int i=0; i< m; i++) {
    cin >> q >> d >> r;
     if (q == 1) {
       int cnt = 1;
       if (d%2 == 0) cnt = -1;
       cout << (cnt) * rsq(0, 0, x - 1, d - 1, r - 1) << "\n";
     } else {
       st(d - 1, r);
     }
  }
  return 0;
}

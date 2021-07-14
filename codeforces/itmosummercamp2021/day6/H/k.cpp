#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;// numeric_limits<long long>::max();
vector<long long> t, upd;
int x;
void buildTree(int n) {
  x = 1;
  while(x < n) {
    x *= 2;
  }
  t.assign(2 * x - 1, INF);
  upd.assign(2 * x - 1, 0);
  for (int i=0; i< n; i++) {
    t[i + x - 1] = 0;
  }
  for (int v=x - 2; v >=0; v--) {
    t[v] = min(t[2*v +1], t[2*v + 2]);
  }
}


long long get(int v) {
  return t[v] + upd[v];
}

void push(int v, int l, int r) {
  if (l == r) {
    t[v] += upd[v];
  } else {
    upd[2*v + 1] += upd[v];
    upd[2*v+2] += upd[v];
    t[v] = min(get(2*v + 1), get(2*v+2));
  }
  upd[v] = 0;
}

long long rmq(int v, int l, int r, int a, int b) {
  push(v, l, r);
  if (l > b || r < a) return INF;
  if (l >= a && r <= b) return get(v);

  int m = (l + r) /2;
  return min(rmq(2*v + 1, l, m, a, b), rmq(2*v+2, m+1, r, a, b));
}

void update(int v, int l, int r, int a, int b, int x) {
  push(v, l, r);
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    upd[v] += x;
    return;
  }

  int m = (l + r) /2;
  update(2*v + 1, l, m, a, b, x);
  update(2*v+2, m+1, r, a, b, x);
  t[v] = min(get(2*v + 1), get(2*v + 2));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n, m;
  cin >> n >> m;
  buildTree(n + 1);
   
  int d, r;
  for(int i=0; i< m; i++) {
     int t;
     cin >> t;
     if (t == 2) {
       int p, q;
       cin >> p >> q;
       // min
       cout << rmq(0, 0, x - 1, p, q - 1) << "\n";
     } else {
       int p, q, add;
       cin >> p >> q >> add;
       update(0, 0 , x - 1, p, q - 1, add);
     }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const long long INF = 2 * 1e9;// numeric_limits<long long>::max();
vector<int> t, upd;
int x;
void buildTree(int n) {
  x = 1;
  while(x < n) {
    x *= 2;
  }
  t.assign(2 * x - 1, 0);
  upd.assign(2 * x - 1, -1);
  for (int i=0; i< n; i++) {
    t[i + x - 1] = 0;
  }
  for (int v=x - 2; v >=0; v--) {
    t[v] = t[2*v +1] + t[2*v + 2];
  }
}


long long get(int v) {
  return upd[v] == -1?t[v]:upd[v];
}

void push(int v, int l, int r) {
  if (upd[v] < 0) return; 
  if (l == r) {
    t[v] = upd[v];
  } else {
    upd[2*v + 1] = upd[v];
    upd[2*v+2] = upd[v];
    t[v] = get(2*v + 1) + get(2*v+2);
  }
  upd[v] = -1;
}

int rsq(int v, int l, int r, int a, int b) {
  push(v, l, r);
  if (l > b || r < a) return 0;
  if (l >= a && r <= b) return get(v);

  int m = (l + r) /2;
  return rsq(2*v + 1, l, m, a, b) + rsq(2*v+2, m+1, r, a, b);
}

void update(int v, int l, int r, int a, int b, int x) {
  push(v, l, r);
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    upd[v] = x;
    return;
  }

  int m = (l + r) /2;
  update(2*v + 1, l, m, a, b, x);
  update(2*v+2, m+1, r, a, b, x);
  t[v] = get(2*v + 1) + get(2*v + 2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n, m;
  cin >> n;
  buildTree(n + 1);
   
  int p, q;
  for(int i=0; i< n; i++) {
     char t;
     cin >> t >> p >> q;
     if (t == 'W') {
       update(0, 0 , x - 1, p, q - 1, 0);
       cout << rsq(0, 0, x - 1, p, q - 1) << "\n";
     } else {
       update(0, 0 , x - 1, p, q - 1, 1);
       cout << rsq(0, 0, x - 1, p, q - 1) << "\n";
     }
  }
  return 0;
}

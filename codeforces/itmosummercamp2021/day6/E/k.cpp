#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<pair<int, int> > t;
int x;

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {

  if (a.first < b.first) return a;
  if (b.first < a.first) return b;
  return {a.first, a.second + b.second};
}

void buildTree(vector<int> &a) {
  x = 1;
  int n = a.size();
  while(x < n) {
    x *= 2;
  }
  t.assign(2 * x - 1, {INF, 1});
  for (int i=0; i< n; i++) {
    t[i + x - 1] = {a[i], 1};
  }
  for (int v=x - 2; v >=0; v--) {
    t[v] = merge(t[2*v +1], t[2*v + 2]);
  }
}

void st(int i, int y) {
  t[i + x - 1] = {y, 1};
  int v = i + x - 1;
  while(v != 0) {
    v = (v - 1) / 2;
    t[v] = merge(t[2*v + 1], t[2*v + 2]);
  }
}

pair<int, int> rmq(int v, int l, int r, int a, int b) {
  if (l > b || r < a) return {INF, 1};
  if (l >= a && r <= b) return t[v];

  int m = (l + r) /2;
  return merge(rmq(2*v + 1, l, m, a, b), rmq(2*v+2, m+1, r, a, b));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n, m;
  int s;
  cin >> n >> m;
  vector<int > a(n + 1);
  for(int p=0; p<n; p++) {
    cin >> a[p];
  }
  buildTree(a);
   
  int d, r;
  for(int i=0; i<m; i++) {
    cin >> s >> d >> r;
     if (s == 2) {
       pair<int, int> ans = rmq(0, 0, x - 1, d, r - 1);
       cout << ans.first << " "<< ans.second << "\n";
     } else {
       st(d, r);
     }
  }
  return 0;
}

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
  for (int i=0; i< n; i++) {
    t[i + x - 1] = a[i];
  }
  for (int v=x - 2; v >=0; v--) {
    t[v] = min(t[2*v +1], t[2*v + 2]);
  }
}

void st(int i, int y) {
  t[i + x - 1] = y;
  int v = i + x - 1;
  while(v != 0) {
    v = (v - 1) / 2;
    t[v] = min(t[2*v + 1], t[2*v + 2]);
  }
}

int rmq(int v, int l, int r, int a, int b) {
  if (l > b || r < a) return INF;
  if (l >= a && r <= b) return t[v];

  int m = (l + r) /2;
  return min(rmq(2*v + 1, l, m, a, b), rmq(2*v+2, m+1, r, a, b));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  string s;
  cin >> n;
  vector<int > a(n);
  for(auto &e: a) {
    cin >> e;
  }
  buildTree(a);
   
  int d, r;
  while(cin >> s >> d >> r) {
     if (s == "min") {
       cout << rmq(0, 0, x - 1, d - 1, r - 1) << "\n";
     } else {
       st(d - 1, r);
     }
  }
  return 0;
}

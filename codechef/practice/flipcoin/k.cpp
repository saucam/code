#include <bits/stdc++.h>

using namespace std;

int x = 1;
const int ma = 1e5;
void se(vector<int > &b, int idx, int val) {
  b[idx] += val;
  idx--;
  while (idx <= ma) {
    b[idx] += val;
    idx += (idx) & (-idx);
  }
  return;
}

void update(vector<int> &b, int l, int r) {
  se(b, l, 1);
  se(b, r+1, -1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n, q;
  cin >> n >> q;
   
  vector<int> b(ma + 1, 0);
  int com, l, r;
  for(int i=0; i< n; i++) {
    cin >> com >> l >> r;
    if (com == 0) {
      update(b, l, r);
    } else {
      cout << b[r] - b[l - 1] << "\n";
    }
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long upd(map<long long, int>& m, long long ans, long long c) {
    if (m.find(ans) != m.end()) {
      m[ans]++;
    } else {
      m[ans] = 1;
    }
    if (m[ans] > c) {
      return m[ans];
    }
    return c;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t, k=1;
  cin >> t;
  while(k <= t) {
    long long a11, a12, a13, b11, b13, c11, c12, c13;
    cin >> a11 >> a12 >> a13;
    cin >> b11 >> b13;
    cin >> c11 >> c12 >> c13;
    map <long long, int> m;
    long long c = 0;
    if ((b11 + b13) % 2 == 0) c = upd(m, (b11 + b13) / 2, c);
    if ((a13 + c11) % 2 == 0) c = upd(m, (a13 + c11) / 2, c);
    if ((a12 + c12) % 2 == 0) c = upd(m, (a12 + c12) / 2, c);
    if ((a11 + c13) % 2 == 0) c = upd(m, (a11 + c13) / 2, c);
    if ((a12 - a11) == (a13 - a12) ) c++;
    if ((c12 - c11) == (c13 - c12) ) c++;
    if ((c11 - b11) == (b11 - a11) ) c++;
    if ((c13 - b13) == (b13 - a13) ) c++;
    cout << "Case #"<<k<<": " << c<<"\n";
    k++;
  }
  return 0;
}

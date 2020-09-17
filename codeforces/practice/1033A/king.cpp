#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int q1, q2;
  cin >> q1 >> q2;
  int k1, k2;
  cin >> k1 >> k2;
  int t1, t2;
  cin >> t1 >> t2;

  if ( (((k1 < q1)&&(t1 < q1)) || ( (k1 > q1) && (t1 > q1) )) && ( ((k2 < q2) && (t2 < q2)) || ( (k2 > q2) && (t2 > q2)))) {
    printf("%s\n", "YES");
  } else printf("%s\n", "NO");
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **arg) {
  int n, t;
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for(auto &a: v) { 
      cin >> a;
      if (s.find(a) == s.end()) {
        s.insert(a);
      } else {
        s.insert(a + 1);
      }
    }
    cout << s.size() << "\n";
  }
  return 0;
}

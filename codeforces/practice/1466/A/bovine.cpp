#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **arg) {
  int n,t;
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for(auto &a: v) cin >> a;
    for(int i=0; i<n; i++) {
      for(int k=i+1; k<n; k++) {
         s.insert(v[k] - v[i]);
      }
    }
    cout << s.size() << "\n"; 
  }
  return 0;
}

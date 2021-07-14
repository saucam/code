#include <bits/stdc++.h>

using namespace std;

bool p(vector<vector<int>> &g, set<int>& q, set<int>&s,  int root) {
  if (g[root].size() == 0) {
    // cerr << "root = "<< root << " ans = " << (q.find(root) != q.end()) << "\n";
    return (q.find(root) != q.end())? true:false;
  }
  int ssize = s.size();
  int cnt = 0;
  bool ans = false;
  for(auto &e: g[root]) {
    bool l = p(g, q, s, e);
    if (l == true) cnt++;
    ans = ans || l;
  }
  if (cnt > 1) {
    s.insert(root);
    // cerr << "inserted " << root << " into s" << "\n";
  }
  if (s.size() > ssize && (q.find(root) != q.end())) s.insert(root);
  // cerr <<  "ans = " << ans << " root = " << root << "\n";
  return ans || (q.find(root) != q.end());
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, root;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    for(int i=0; i<n-1; i++) {
      int a, b;
      cin >> a >> b;
      if (i == 0) root = a;
      g[a].push_back(b);
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
      int k, e;
      cin >> k;
      set<int> qlist;
      for(int i=0; i<k; i++) {
        cin >> e;
        qlist.insert(e);
      }
      // ans here
      set<int> s;
      p(g, qlist, s, root);
      if (s.size() == 1) cout << "YES\n"; else cout << "NO\n";
    }
  }
  return 0;
}

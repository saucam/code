#include <bits/stdc++.h>

using namespace std;

int d[1001];
int vis[1001];
int pr[1001];
pair<int, int> key[500];
int main() {
  int n, x1, y1, x2, y2;
  queue<int> q;
  cin >> n >> x1 >> y1 >> x2 >> y2; 
  int s = (x1) * n + (y1);
  int t = (x2)*n + (y2);
  vector <vector <int>> g(500);
    for (int i = 1; i <= (n); i++) {
      for (int j = 1; j<= (n); j++) {
        int k = ((i * n) + j);
        key[k] = make_pair(i, j);
        pair<int, int> x[] = 
        {
          {i-2,j-1},
          {i + 2,j-1},
          {i-2,j+1},
          {i+2, j+1},
          {i-1, j-2},
          {i+1,j-2},
          {i-1,j+2},
          {i+1,j+2}
        };  
        //int p[] = { (i -2)*n + (j - 1), (i + 2)*n + (j - 1), (i - 2)*n + (j + 1), (i + 2)*n + (j + 1), (i - 1)*n + (j - 2), (i + 1)*n + (j - 2), (i - 1)* n + (j + 2), (i + 1)*n + (j + 2)};
        for (auto e: x) {
          if (e.first >=1 && e.first<=n && e.second >=1 && e.second<=n ) {
            int kl = e.first*n + e.second;
            g[k].push_back(kl);
          }
        }
    }
  }

  for(int i=1; i<=1001;i++) {
    d[i] = -1;
    pr[i] = -1;
    vis[i] = 0;
  }
 
  d[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int k = q.front();
    q.pop();
       for (auto r: g[k]) {
         if (d[r] == -1) {
                 d[r] = d[k] + 1;
                 pr[r] = k;
               q.push(r);
         }
       }
   if (k == t) break;    
  }
  cout << d[t] + 1 << "\n";
  vector<int> ans;
  int last = t;
  while(last != -1) {
    ans.push_back(last);
    last = pr[last];
  }
  for(int i=ans.size()-1; i>=0; i--) {
    cout << key[ans[i]].first << " " << key[ans[i]].second<< "\n";
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &a: v) {
    cin >> a;
  } 
  for (int i=0; i<n; i++) {
    dp[i] = 1;
    for (int j = 0; j<i; j++) {
      if (v[j] < v[i]) {
        dp[i] = max(dp[i], dp[j] + 1); 
      }
    }    
  }
  vector<int> s;
  int last = 0;
  for(int i = 1; i < n; i++) {
     if (dp[i] > dp[last]) {
       last = i;
     }
  }
  int k = 0;
  while (true) {
    s.push_back(v[last]);
    if (dp[last] == 1) break;
    for (k = 0; k < last; k++) {
      if (v[k] < v[last] && ((dp[k] + 1) == dp[last])) {
         last = k;
         break;
      }
    }  
  }
  cout << s.size() << "\n";
  for (int k=s.size() - 1; k>=0; k--) {
    cout << s[k] << " ";
  }
  return 0;
}

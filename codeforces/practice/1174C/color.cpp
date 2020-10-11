#include <bits/stdc++.h>

using namespace std;

int pr[100000 + 1];
int ans[100000 + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
 vector<int> primes;
  // generate primes?
  for(int k=2;k<=1000;k++) {
    if (pr[k] == 0) {
      for(int i=2;i*k<=n;i++) {
        pr[i*k] = 1;
      }
    }
  }
  for (int k=2;k<=n;k++) {
    if (pr[k] == 0) {
      primes.push_back(k);
    }
  }
  int i = 1;
  for(auto a: primes) {
    for(int k=1;a*k<=n;k++) {
      ans[a*k] = i;
    }
    i++;
  }
  for(int i=2;i<=n;i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";    
  return 0;
}

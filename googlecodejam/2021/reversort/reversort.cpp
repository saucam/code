#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, n;
  cin >> t;
  int i=1; 
  while (i <= t) {
    cin >> n;
    int ans = 0;
    vector<int> v(n);
    for(auto &e: v) {
       cin >> e;
    }
    for(int k=0; k<n-1; k++) {
      int sm = k;
      for(int r=k;r<n;r++) {
        if (v[r] < v[sm]) {sm = r;}
      }
      ans += (sm - k + 1);
      int p=k;
      int l=sm;
       while (p<l) {
        int t = v[p];
        v[p] = v[l];
        v[l] = t;
        p++; l--; 
      }
    }
    cout << "Case #"<<i<<": "<<ans<<"\n";
    i++;
  }
}

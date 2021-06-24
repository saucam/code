#include <bits/stdc++.h>

using namespace std;

long long ans = 0;
vector<int> merge(const vector<int> a, const vector<int> b) {
  int i = 0, j = 0;
  int m = a.size();
  int n = b.size();
  vector<int> res(n + m);
  while ((i + j) < (n + m)) {
     if ((j == n) ||  (a[i] <= b[j])) {
        res[i + j] = a[i];
        i++;
     } else {
        ans = ans + (m - i);
        res[i + j] = b[j];
        j++;
    }
  }
  return res; 
}

vector<int> mergesort(vector<int> a) {
   if (a.size() == 1) {
     return a;
   }
   int n = a.size();
   vector<int> a1; a1.reserve(n/2);
   vector<int> a2; a2.reserve((n + 1) / 2);
   for (int i = 0; i < n; i++ ) {
      if (i < n / 2) {
         a1.push_back(a[i]);
      } else {
         a2.push_back(a[i]);
      }
   }
   vector<int> k1 = mergesort(a1);
   vector<int> k2 = mergesort(a2);
   return merge(k1, k2);
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &a: v) {
    cin >> a;
  }
  mergesort(v);
  
  cout << ans;
  return 0;
}

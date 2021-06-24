#include <bits/stdc++.h>

using namespace std;

int arr[101];
int main() {
  int a;
  while(cin >> a) {
    arr[a]++;
  }
  for (int i = 0; i <= 100; i++) {
    for(int j = 0; j < arr[i]; j++) cout << i << " ";
  }
  cout << "\n";
  return 0;
}

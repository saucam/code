#include <bits/stdc++.h>

using namespace std;

bool BinarySearch(int l, int r, int x, int a[]) {
    if (l == r - 1) return (a[l] == x);
    // Use addition to find middle element
    int m = (l + r) / 2;
    cout << "m = " << m << " a[m] = " << a[m] << "\n";
    if (a[m] == x) return true;
    if (a[m] > x) {
        // Discards the upper half of the array
        return BinarySearch(l, m, x, a);
    } else {
        // Discards the lower half of the array
        return BinarySearch(m, r, x, a);
    }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
  cout << BinarySearch(0, 16, 4, a) << "\n";
  return 0;
}

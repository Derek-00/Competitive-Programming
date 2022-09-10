#include <bits/stdc++.h>

using namespace std;

#define int long long

const int p = 1000000007;

class matrix {
 public:
   int arr[3][3];
   void Clear() {
     memset(arr, 0, sizeof(arr));
   }
   void one() {
     arr[1][1] = 1; arr[1][2] = 0;
     arr[2][1] = 0; arr[2][2] = 1;
   }
   void initial() {
     arr[1][1] = 1; arr[1][2] = 1;
     arr[2][1] = 1; arr[2][2] = 0;
   }
};

matrix Time(matrix a, matrix b) {
  matrix tmp;
  tmp.Clear();
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 2; j++) {
      for (int k = 1; k <= 2; k++) {
        tmp.arr[i][j] = (tmp.arr[i][j] + (a.arr[i][k] * b.arr[k][j]) % p) % p;
      }
    }
  }
  return tmp;
}

matrix fast_pow(int k) {
  matrix ans, x;
  ans.one(); x.initial();
  while (k) {
    if (k & 1) ans = Time(ans, x);
    x = Time(x, x);
    k >>= 1;
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    if (n == -1) break;
    matrix a = fast_pow(n - 2);
    cout << (a.arr[1][1] + a.arr[2][1]) % p << '\n';
  }
  return 0;
}

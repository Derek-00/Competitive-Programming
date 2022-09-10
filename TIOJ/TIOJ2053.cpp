#include <bits/stdc++.h>

using namespace std;

#define int long long

const int P = 1e9 + 7;

int x1, x2, a, b, n;

int mod(int x) {
  return (x % P);
}

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
      arr[1][1] = b; arr[1][2] = a;
      arr[2][1] = 1; arr[2][2] = 0;
    }
};

matrix Time(matrix a, matrix b) {
  matrix tmp;
  tmp.Clear();
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 2; j++) {
      for (int l = 1; l <= 2; l++) {
        tmp.arr[i][j] = tmp.arr[i][j] + mod(mod(a.arr[i][l]) * mod(b.arr[l][j]));
      }
    }
  }
  return tmp;
}

matrix fast_pow(int n) {
  matrix ans, tmp;
  ans.one();
  tmp.initial();
  while (n) {
    if (n & 1) ans = Time(ans, tmp);
    tmp = Time(tmp, tmp);
    n >>= 1;
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> x1 >> x2 >> a >> b >> n;
  x1 %= P; x2 %= P;
  a %= P; b %= P;
  matrix ans = fast_pow(n - 2);
  cout << mod(mod(mod(ans.arr[1][1]) * x2) + mod(mod(ans.arr[1][2]) * x1));
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
int sum[maxn];

void build(int p) {
  int v;
  cin >> v;
  if (v == -1) return;
  sum[p] += v;
  build(p - 1);
  build(p + 1);
}

bool initial() {
  int v;
  cin >> v;
  if (v == -1) return false;
  memset(sum, 0, sizeof(sum));
  int p = maxn / 2;
  sum[p] = v;
  build(p - 1);
  build(p + 1);
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int kase = 0;
  while (initial()) {
    cout << "Case " << ++kase << ":\n";
    int p = 0;
    while (sum[p] == 0) p++;
    for (int i = p; sum[i] != 0; i++) {
      if (i > p) {
        cout << " ";
      }
      cout << sum[i];
    }
    cout << "\n\n";
  }
  return 0;
}

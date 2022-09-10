/**
 *    author:  wy
 *    created: Thu, 07 Jul 2022 08:53:55 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;
const int inf = (int) 1e9;

struct node {
  int c, h;
  int nxt, prv;
  bool alive = true;
} a[N];

vector<int> que;

void Remove(int i) {
  if (!a[i].alive) {
    return;
  }
  int n = a[i].nxt;
  int p = a[i].prv;
  if (a[i].c - a[i].h < a[p].c && a[i].c + a[i].h > a[n].c) {
    return;
  }
  a[i].alive = false;
  a[p].nxt = n;
  a[n].prv = p;
  que.push_back(i);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].c;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].h;
    a[i].nxt = i + 1;
    a[i].prv = i - 1;
  }
  for (int i = 1; i <= n; i++) {
    a[i].nxt = i + 1;
    a[i].prv = i - 1;
  }
  a[0].c = 0; a[0].h = inf;
  a[n + 1].c = l; a[n + 1].h = inf;
  for (int i = 1; i <= n; i++) {
    Remove(i);
  }
  int mx = 0;
  for (int b = 0; b < (int) que.size(); b++) {
    int i = que[b];
    mx = max(mx, a[i].h);
    Remove(a[i].prv);
    Remove(a[i].nxt);
  }
  cout << (int) que.size() << '\n';
  cout << mx << '\n';
  return 0;
}

/**
 *    author:  wy
 *    created: Tue, 19 Jul 2022 08:15:20 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 1000010;

int n, p, l, r;
int s[N], dist[N];

inline bool Valid(int x) {
  return (0 <= x && x < n);
}

int main() {
  scanf("%d %d %d %d", &n, &p, &l, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  memset(dist, -1, sizeof(dist));
  vector<int> que(1, 0);
  dist[0] = 0;
  for (int b = 0; b < (int) que.size(); b++) {
    if (Valid(que[b] - l)) {
      int nxt = s[que[b] - l];
      if (Valid(nxt) && dist[nxt] == -1) {
        dist[nxt] = dist[que[b]] + 1;
        que.push_back(nxt);
      }
      if (nxt == p) {
        break;
      }
    }
    if (Valid(que[b] + r)) {
      int nxt = s[que[b] + r];
      if (Valid(nxt) && dist[nxt] == -1) {
        dist[nxt] = dist[que[b]] + 1;
        que.push_back(nxt);
      }
      if (nxt == p) {
        break;
      }
    }
  }
  printf("%d\n", dist[p]);
  return 0;
}

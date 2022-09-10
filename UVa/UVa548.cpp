#include <bits/stdc++.h>

using namespace std;

const int maxv = 1e4 + 10;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_list(int *a) {
  string line;
  if (!getline(cin, line)) return false;
  stringstream ss(line);
  n = 0;
  int x;
  while (ss >> x) {
    a[n++] = x;
  }
  return n > 0;
}

int build(int l1, int r1, int l2, int r2) {
  if (l1 > r1) return 0;
  int root = post_order[r2];
  int p = l1;
  while (in_order[p] != root) p++;
  int cnt = p - l1; // number of left child
  lch[root] = build(l1, p - 1, l2, l2 + cnt - 1);
  rch[root] = build(p + 1, r1, l2 + cnt, r2 - 1);
  return root;
}

int best, best_sum; // the answer and the weight

void dfs(int u, int sum) {
  sum += u;
  if (!lch[u] && !rch[u]) { // the leaf
    if (sum < best_sum || (sum == best_sum && u < best)) {
      best = u; best_sum = sum;
    }
  }
  if (lch[u]) dfs(lch[u], sum);
  if (rch[u]) dfs(rch[u], sum);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (read_list(in_order)) {
    read_list(post_order);
    build(0, n - 1, 0, n - 1);
    best_sum = INT_MAX;
    dfs(post_order[n - 1], 0);
    cout << best << '\n';
  }
  return 0;
}

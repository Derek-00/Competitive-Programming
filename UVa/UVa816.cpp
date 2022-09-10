#include <bits/stdc++.h>

using namespace std;

struct node {
  int r, c, dir;
  node(int r = 0, int c = 0, int dir = 0): r(r), c(c), dir(dir) {
  }
};

const int maxn = 10;
const char *dirs = "NESW";
const char *turns = "FLR";

bool has_edge[maxn][maxn][4][3];
int d[maxn][maxn][4];
node p[maxn][maxn][4];
int r0, c0, dir, r1, c1, r2, c2;

int dir_id(char c) {
  return strchr(dirs, c) - dirs;
}

int turn_id(char c) {
  return strchr(turns, c) - turns;
}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

bool read_case() {
  char s1[99], s2[99];
  if (scanf("%s%d%d%s%d%d", &s1, &r0, &c0, &s2, &r2, &c2) != 6) return false;
  printf("%s\n", s1);
  dir = dir_id(s2[0]);
  r1 = r0 + dr[dir];
  c1 = c0 + dc[dir];
  memset(has_edge, false, sizeof(has_edge));
  while (true) {
    int r, c;
    scanf("%d", &r);
    if (r == 0) break;
    scanf("%d", &c);
    while (scanf("%s", &s1) && s1[0] != '*') {
      for (int i = 1; i < strlen(s1); i++) {
        has_edge[r][c][dir_id(s1[0])][turn_id(s1[i])] = true;
      }
    }
  }
  return true;
}

void print_ans(node u) {
  vector<node> nodes;
  while (true) {
    nodes.push_back(u);
    if (d[u.r][u.c][u.dir] == 0) break;
    u = p[u.r][u.c][u.dir];
  }
  nodes.emplace_back(r0, c0, dir);
  int cnt = 0;
  for (int i = (int) nodes.size() - 1; i >= 0; i--) {
    if (cnt % 10 == 0) printf(" ");
    printf(" (%d,%d)", nodes[i].r, nodes[i].c);
    if (++cnt % 10 == 0) printf("\n");
  }
  if ((int) nodes.size() % 10 != 0) printf("\n");
}

node walk(const node &u, int turn) {
  int dir = u.dir;
  if (turn == 1) dir = (dir + 3) % 4;
  if (turn == 2) dir = (dir + 1) % 4;
  return node(u.r + dr[dir], u.c + dc[dir], dir);
}

inline bool inside(int r, int c) {
  return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}

void solve() {
  queue<node> q;
  memset(d, -1, sizeof(d));
  d[r1][c1][dir] = 0;
  q.emplace(r1, c1, dir);
  while (!q.empty()) {
    node u = q.front(); q.pop();
    if (r2 == u.r && c2 == u.c) {
      print_ans(u);
      return;
    }
    for (int i = 0; i < 3; i++) {
      node v = walk(u, i);
      if (has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {
        d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
        p[v.r][v.c][v.dir] = u;
        q.push(v);
      }
    }
  }
  printf("  No Solution Possible\n");
}

int main() {
  while (read_case()) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct node {
  node *left, *right;
  bool have_value;
  int v;
  node(): have_value(false), v(0), left(0), right(0) {
  }
};

node* newnode() {
  return new node();
}

const int maxn = 1e5;
node* root;
char s[maxn];
bool failed;

void addnode(int v, char* s) {
  int n = strlen(s);
  node* u = root;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      if (u -> left == NULL) u -> left = newnode();
      u = u -> left;
    } else if (s[i] == 'R') {
      if (u -> right == NULL) u -> right = newnode();
      u = u -> right;
    }
  }
  if (u -> have_value) failed = true;
  u -> v = v;
  u -> have_value = true;
}

bool read_input() {
  failed = false;
  root = newnode();
  while (true) {
    if (scanf("%s", &s) != 1) return false;
    if (strcmp(s, "()") == 0) break;
    int v;
    sscanf(&s[1], "%d", &v);
    addnode(v, strchr(s, ',') + 1);
  }
  return true;
}

bool bfs(vector<int>& ans) {
  queue<node*> q;
  ans.clear();
  q.push(root);
  while ((int) q.size()) {
    node* u = q.front(); q.pop();
    if (u -> have_value == false) return false;
    ans.push_back(u -> v);
    if (u -> left != NULL) q.push(u -> left);
    if (u -> right != NULL) q.push(u -> right);
  }
  return true;
}

void remove_tree(node* u) {
  if (u == NULL) return;
  remove_tree(u -> left);
  remove_tree(u -> right);
  delete u;
}

int main() {
  while (read_input()) {
    if (failed) {
      printf("not complete\n");
      continue;
    }
    vector<int> ans;
    if (bfs(ans)) {
      for (int i = 0; i < (int) ans.size(); i++) {
        if (i > 0) {
          printf(" ");
        }
        printf("%d", ans[i]);
      }
    } else {
      printf("not complete");
    }
    printf("\n");
    remove_tree(root);
  }
  return 0;
}

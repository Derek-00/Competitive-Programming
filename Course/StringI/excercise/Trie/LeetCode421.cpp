/**
 *    author:  willy
 *    created: Fri, 17 Dec 2021 03:55:25 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  struct node {
    node* to[2] = {nullptr};
    int id = -1;
  };

  node* root;

  void add(node* cur, string s, int id) {
    for (int i = 0; i < (int) s.size(); i++) {
      int val = (int) (s[i] == '1');
      if (cur->to[val] == nullptr) {
        cur->to[val] = new node();
      }
      cur = cur->to[val];
    }
    cur->id = id;
  }

  int findMaximumXOR(vector<int>& a) {
    int n = (int) a.size();
    vector<string> s(n);
    const int MAX = 32;
    root = new node();
    for (int i = 0; i < n; i++) {
      bitset<MAX> b(a[i]);
      s[i] = b.to_string();
      add(root, s[i], i);
    }
    int ans = 0;
    auto Get = [&](int x, string s) {
      auto cur = root;
      for (int i = 0; i < (int) s.size(); i++) {
        int best = (s[i] != '1');
        if (cur->to[best] != nullptr) {
          cur = cur->to[best];
          if (cur->id != -1) {
            int val = a[cur->id];
            ans = max(ans, (x ^ val));
          }
        } else {
          if (cur->to[best ^ 1] != nullptr) {
            cur = cur->to[best ^ 1];
            if (cur->id != -1) {
              int val = a[cur->id];
              ans = max(ans, (x ^ val));
            }
          } else {
            break;
          }
        }
      }
    };
    for (int i = 0; i < n; i++) {
      Get(a[i], s[i]);
    }
    return ans;
  }
};

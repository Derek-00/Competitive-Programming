/**
 *    author:  willy
 *    created: Mon, 15 Nov 2021 13:00:29 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& a) {
    const int n = (int) a.size();
    unordered_map<int, int> id;
    for (int i = 0; i < n; i++) {
      id[a[i]] = i;
    }
    unordered_map<int, int> mx_len;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] - a[j] < a[j] && id.count(a[i] - a[j])) {
          mx_len[j * n + i] = mx_len[id[a[i] - a[j]] * n + j] + 1;
          ans = max(ans, mx_len[j * n + i] + 2);
        }
      }
    }
    return (ans >= 3 ? ans : 0);
  }
};

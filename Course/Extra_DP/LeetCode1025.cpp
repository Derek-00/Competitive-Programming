/**
 *    author:  willy
 *    created: Mon, 15 Nov 2021 13:11:34 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool divisorGame(int n) {
    vector<bool> win(n + 1, false);
    for (int i = 1; i <= n; i++) {
      if (win[i]) {
        continue;
      }
      for (int j = 1; j < i; j++) {
        if (i % j == 0 && !win[i - j]) {
          win[i] = true;
        }
      }
    }
    return win[n];
  }
};

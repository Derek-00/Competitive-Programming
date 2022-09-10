/**
 *    author:  willy
 *    created: Mon, 08 Nov 2021 01:35:16 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int longestStrChain(vector<string>& words) {
  sort(words.begin(), words.end(), [&](string a, string b) {
    return (int) a.size() < (int) b.size();
  });
  const int n = (int) words.size();
  auto Can = [&](string a, string b) {
    for (int ptr = 0; ptr < (int) b.size(); ptr++) {
      string c(b.begin(), b.end());
      c.erase(c.begin() + ptr);
      if (a == c) {
        return true;
      }
    }
    return false;
  };
  vector<int> dp(n, 1);
  for (int l = n - 2; l >= 0; l--) {
    int r = l + 1;
    while (r < n && words[l].size() == words[r].size()) {
      r++;
    }
    while (r < n && words[l].size() + 1 == words[r].size()) {
      if (Can(words[l], words[r])) {
        dp[l] = max(dp[l], dp[r] + 1);
      }
      r++;
    }
  }
  return *max_element(dp.begin(), dp.end());
}

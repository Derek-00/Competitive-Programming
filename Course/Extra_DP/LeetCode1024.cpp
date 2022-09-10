/**
 *    author:  willy
 *    created: Tue, 16 Nov 2021 07:10:47 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int videoStitching(vector<vector<int>>& clips, int time) {
  const int n = (int) clips.size();
  vector<int> dp(101, 0);
  for (int i = 0; i < n; i++) {
    dp[clips[i][0]] = max(dp[clips[i][0]], clips[i][1]);
  }
  int tag = 0;
  int nxt = 0;
  int ans = 0;
  for (int i = 0; i <= tag && i < time; i++) {
    nxt = max(nxt, dp[i]);
    if (tag == i) {
      ans++;
      tag = nxt;
    }
  }
  return (tag >= time ? ans : -1);
}

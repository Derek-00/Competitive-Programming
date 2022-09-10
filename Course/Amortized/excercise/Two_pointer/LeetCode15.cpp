/**
 *    author:  willy
 *    created: Sat, 06 Nov 2021 05:26:32 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& a) {
  const int n = (int) a.size();
  if (n < 3) {
    return vector<vector<int>>();
  }
  sort(a.begin(), a.end());
  vector<vector<int>> ans;
  for (int i = 0; i < n - 2; i++) {
    if (i > 0 && a[i] == a[i - 1]) {
      continue;
    }
    int l = i + 1, r = n - 1;
    while (l < r) {
      if (a[l] + a[r] == -a[i]) {
        ans.push_back({a[i], a[l], a[r]});
        while (l < r && a[l] == a[l + 1]) {
          ++l;
        }
        while (l < r && a[r] == a[r - 1]) {
          --r;
        }
        ++l; --r;
      } else {
        if (a[l] + a[r] > -a[i]) {
          --r;
        } else {
          ++l;
        }
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // vector<int> nums = {-1, 0, 1, 2, -1, 4};
  vector<int> nums = {0};
  auto ans = threeSum(nums);
  for (int i = 0; i < (int) ans.size(); i++) {
    for (int j = 0; j < (int) ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}

/**
 *    author:  willy
 *    created: Mon, 08 Nov 2021 13:42:59 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<int> d;
  vector<int> ret;
  for (int i = 0; i < (int) nums.size(); i++) {
    if (!d.empty() && d.front() <= i - k) {
      d.pop_front();
    }
    while (!d.empty() && nums[d.back()] <= nums[i]) {
      d.pop_back();
    }
    d.push_back(i);
    if (i >= k - 1) {
      ret.push_back(nums[d.front()]);
    }
  }
  return ret;
}

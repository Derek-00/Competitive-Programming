/**
 *    author:  willy
 *    created: Thu, 09 Dec 2021 11:26:17 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int oddEvenJumps(vector<int>& a) {
  int n = (int) a.size();
  vector<bool> odd(n, false);
  vector<bool> even(n, false);
  map<int, int> mp;
  odd[n - 1] = even[n - 1] = true;
  mp[a[n - 1]] = n - 1;
  int ans = 1;
  for (int i = n - 2; i >= 0; i--) {
    { // from Odd steps
      auto it = mp.lower_bound(a[i]);
      if (it != mp.end()) {
        odd[i] = even[it->second];
      }
    }
    { // from Even steps
      auto it = mp.upper_bound(a[i]);
      if (it != mp.begin()) {
        even[i] = odd[prev(it)->second];
      }
    }
    if (odd[i]) {
      ans += 1;
    }
    mp[a[i]] = i;
  }
  return ans;
}

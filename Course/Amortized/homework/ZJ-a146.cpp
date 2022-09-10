/**
 *    author:  willy
 *    created: Fri, 12 Nov 2021 16:35:12 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (k >= n) {
      cout << *min_element(a.begin(), a.end()) << '\n';
      cout << *max_element(a.begin(), a.end()) << '\n';
      continue;
    }
    deque<int> mx;
    deque<int> mn;
    vector<int> ans_mx;
    vector<int> ans_mn;
    for (int i = 0; i < n; i++) {
      if (!mx.empty() && i - mx.front() >= k) mx.pop_front();
      if (!mn.empty() && i - mn.front() >= k) mn.pop_front();
      while (!mx.empty() && a[mx.back()] < a[i]) {
        mx.pop_back();
      }
      mx.push_back(i);
      while (!mn.empty() && a[mn.back()] > a[i]) {
        mn.pop_back();
      }
      mn.push_back(i);
      if (i + 1 >= k) {
        ans_mx.push_back(a[mx.front()]);
        ans_mn.push_back(a[mn.front()]);
      }
    }
    for (int i = 0; i < (int) ans_mx.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans_mn[i];
    }
    cout << '\n';
    for (int i = 0; i < (int) ans_mn.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans_mx[i];
    }
    cout << '\n';
  }
  return 0;
}

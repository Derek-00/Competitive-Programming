#include <bits/stdc++.h>

using namespace std;

vector<int> pref;

NumArray(vector<int>& nums) {
	pref = vector<int>((int) nums.size());
	pref[0] = nums[0];
	for (int i = 1; i < (int) nums.size(); i++) {
		pref[i] = pref[i - 1] + nums[i];
	}
}

int sumRange(int left, int right) {
  if (left == 0) {
  	return pref[right];
	}
	return pref[right] - pref[left - 1];
}

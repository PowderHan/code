#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
int found(vector<int> nums, int L, int R, int keys) {
        int l = L, r = R;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (keys <= nums[mid])  r = mid;
            else    l = mid + 1;
        }
        return nums[l] == keys ? l : -1;
    }
    int binary_found(int l, int r, int val, vector<int> nums) {
        if (l > r)  return -1;
        if (l == r)
            return nums[l] == val ? l : -1;
        int mid = (l + r) >> 1;
        if (nums[mid] >= nums[l]) {
            if (val <= nums[mid] && val >= nums[l])
                return found(nums, l , mid, val);
            else
                return binary_found(mid + 1, r, val, nums);
        }
        else {
            if (val >= nums[mid] && val <= nums[r])
                return found(nums, mid, r, val);
            else
                return binary_found(l, mid - 1, val, nums);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int l = nums.size();
        if (l == 0) return -1;
        return binary_found(0, l - 1, target, nums);
    }
};
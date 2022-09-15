#pragma once

#include <vector>

/*
* 1480. Running Sum of 1d Array
* Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
* Return the running sum of nums.
*/

std::vector<int> runningSum(std::vector<int>& nums) {
  std::vector<int> rv;
  int tmp = 0;
  for (int x : nums)
  {
    tmp += x;
    rv.push_back(tmp);
  }
  return rv;
}

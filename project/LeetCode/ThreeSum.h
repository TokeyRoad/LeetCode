//************************************
//	file：ThreeSum.h
//  author：Tokey
//  date：2019/07/02
//************************************

/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
	[-1, 0, 1],
	[-1, -1, 2]
]
*/
#pragma once
#include "head.h"

class ThreeSum {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) {
			return vector<vector<int>>();
		}
		vector<vector<int>> vRet;
		vector<int> v;
		::sort(nums.begin(), nums.end());
		int pre = nums[0] - 1;
		for (int i = 0; i < nums.size() - 2; i++) {
			if (pre != nums[i]) {
				pre = nums[i];
				int ret = 0 - nums[i];
				auto left = nums.begin() + i + 1;
				auto right = nums.end() - 1;
				int left_pre = (*left) - 1;
				int right_pre = (*right) - 1;
				bool left_move = false;
				bool right_move = false;
				while (left < right) {
					if ((*left) == left_pre && left_move) {
						left++;
						left_move = true;
						continue;
					}
					left_pre = *left;
					left_move = false;
					if ((*right) == right_pre && right_move) {
						right--; 
						right_move = true;
						continue;
					}
					right_pre = *right;
					right_move = false;
					if ((*left) + (*right) == ret) {
						v.clear();
						v.push_back(nums[i]);
						v.push_back((*left));
						v.push_back((*right));
						vRet.push_back(v);
						left++;
						left_move = true;
						right--;
						right_move = true;
					}
					else if ((*left) + (*right) > ret) {
						right--;
						right_move = true;
					}
					else {
						left++;
						left_move = true;
					}
				}
			}
		}
		return vRet;
	}
};
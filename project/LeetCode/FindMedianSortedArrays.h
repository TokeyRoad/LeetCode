//************************************
//	file：LongestPalindrome.h
//  author：Tokey
//  date：2019/07/02
//************************************

/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
*/
#pragma once
#include "head.h"

class FindMedianSortedArrays {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> me;
		me.resize(nums1.size() + nums2.size());
		::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), me.begin());
		int count = (me.size() % 2 == 0) ? (me.size() / 2 - 1) : (me.size() / 2);
		if (me.size() % 2 == 0) {
			return (double)(me[me.size() / 2 - 1] + me[me.size() / 2]) / 2;
		}
		else {
			return me[(me.size()-1) / 2];
		}
	}
};
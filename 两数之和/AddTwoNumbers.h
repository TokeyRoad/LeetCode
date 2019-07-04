//************************************
//	file：LongestPalindrome.h
//  author：Tokey
//  date：2019/07/02
//************************************
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
#include "head.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class AddTwoNumbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* node = head;
		int upTag = 0;
		while (l1 != NULL || l2 != NULL) {
			int value = 0;
			value = (l1 == NULL) ? 0 : l1->val + (l2 == NULL) ? 0 : l2->val + upTag;
			if (l1 != NULL) {
				l1 = l1->next;
			}
			if (l2 != NULL) {
				l2 = l2->next;
			}
			upTag = value / 10;
			value = value % 10;
			node->val = value;
			if (!(l1 == NULL && l2 == NULL)) {
				node->next = new ListNode(0);
				node = node->next;
			}
		}
		if (upTag != 0) {
			node->next = new ListNode(upTag);
		}
		return head;
	}
};
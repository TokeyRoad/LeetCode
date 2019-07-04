//************************************
//	file：RemoveNthFromEnd.h
//  author：Tokey
//  date：2019/07/03
//************************************

/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。
*/
#pragma once
#include "head.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class RemoveNthFromEnd {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) {
			return NULL;
		}
		if (head->next == NULL) {
			return NULL;
		}
		ListNode *first = head;
		ListNode *second = head;
		int index = 0;
		bool tag = false;
		while (first->next != NULL) {
			first = first->next;
			if (!tag) {
				index++;
				if (index == n) {
					tag = true;
				}
			}
			else {
				second = second->next;
			}
		}
		if (!tag) {
			return head->next;
		}
		second->next = second->next->next;
		return head;
	}
};
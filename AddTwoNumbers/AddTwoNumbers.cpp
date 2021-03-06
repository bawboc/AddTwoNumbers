// AddTwoNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/*
*	The node provided by LeetCode
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
*	A very simplistic LinkedList implementation that
*	simply adds nodes to the end of the current list.
*/
class ListNodeList {
private:
	ListNode * head, *tail;

public:
	ListNodeList() {
		head = NULL;
		tail = NULL;
	}

	/*
	*	Add a node
	*	@param a	New int
	*/
	void add(int a) {
		ListNode* tmp = new ListNode(a);

		if (head == NULL) {
			head = tmp;
			tail = tmp;
		} else {
			tail->next = tmp;
			tail = tail->next;
		}
	}

	/* Returns the list */
	ListNode* getHead() { return head; }
};

class Solution {

private:
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int roundUp = 0;
		int tmpNum = 0;
		ListNodeList ret;
		while (l1 != NULL || l2 != NULL) {
			if (l1 != NULL && l2 != NULL) {
				tmpNum = l1->val + l2->val;
				if (roundUp > 0) {
					tmpNum += roundUp;
					roundUp = 0;
				}
				if (tmpNum >= 10) {
					roundUp = 1;
					tmpNum -= 10;
				}
				l1 = l1->next;
				l2 = l2->next;
			} else if (l1 != NULL && l2 == NULL) {
				tmpNum = l1->val;
				if (roundUp > 0) {
					tmpNum += roundUp;
					roundUp = 0;
				}
				if (tmpNum >= 10) {
					roundUp = 1;
					tmpNum -= 10;
				}
				l1 = l1->next;
			} else if (l1 == NULL && l2 != NULL) {
				tmpNum = l2->val;
				if (roundUp > 0) {
					tmpNum += roundUp;
					roundUp = 0;
				}
				if (tmpNum >= 10) {
					roundUp = 1;
					tmpNum -= 10;
				}
				l2 = l2->next;
			}

			ret.add(tmpNum);
		}
		if (roundUp > 0) {
			ret.add(roundUp);
		}

		return ret.getHead();
	}

	/*
	*	Utility for printing list elements
	*	@param node		Head of list
	*/
	static void printList(const ListNode* node) {
		while (node != NULL) {
			std::cout << node->val << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}
};


int main()
{
	return 0;
}


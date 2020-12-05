#include <iostream>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) 
{
	// Iterative
	// 27 / 27 test cases passed.
	// Runtime : 8 ms
	// Memory Usage : 8.7 MB
	if (head && head->next)
	{
		ListNode* prev = nullptr;
		ListNode* curr = head;
		ListNode* next = nullptr;

		// List is (head)1->2->3->4->5->nullptr
		// I must change only every element's next and it will become
		// nullptr <- 1 <- 2 <-3 <-4 <-5(head)
		// Now the element will show its previous next pointer. That's all
		while (curr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	return head;


	// Recursive
	// 27 / 27 test cases passed.
	// Runtime : 8 ms
	// Memory Usage : 9 MB

	if (head && head->next)
	{
		ListNode* rest = reverseList(head->next);
		ListNode* next = head->next;
		next->next = head;
		head->next = nullptr;

		return rest;
	}	
	return head;
}

int main()
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = nullptr;

	reverseList(&a);

	return 0;
}
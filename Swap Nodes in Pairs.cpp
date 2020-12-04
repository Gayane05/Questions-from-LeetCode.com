#include <iostream>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* swapPairs(ListNode* head) 
{
	// 55 / 55 test cases passed.
	// Runtime : 0 ms
	// Memory Usage : 8 MB

	if (head == nullptr ||head->next == nullptr)
	{
		return head;
	}
	else
	{
		ListNode* temp = head;
		head = temp->next;
		ListNode* temp_ = head->next;
		head->next = temp;
		head->next->next = swapPairs(temp_);

		return(head);

		// NTBM
		/*ListNode* temp = head->next;
		head->next = swapPairs(head->next->next);
		temp->next = head;

		return(temp);*/

	}
}

int main()
{
	ListNode* a1 = new ListNode(1);
	ListNode* a2 = new ListNode(2);
	ListNode* a3 = new ListNode(3);
	ListNode* a4 = new ListNode(4);

	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = nullptr;

	swapPairs(a1);

	delete a1;
	delete a2;
	delete a3;
	delete a4;

	return 0;
}

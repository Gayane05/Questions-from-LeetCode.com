#include <iostream>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{

	// 1568 / 1568 test cases passed.
	// Runtime : 28 ms
	// Memory Usage : 71.8 MB

	ListNode* summary_list = new ListNode(-1);
	ListNode* head(0);
	int transfer = 0;

	while (l1 && l2)
	{
		ListNode* summary_list_node = new ListNode(0);

		summary_list_node->val = l1->val + l2->val;

		if (transfer)
		{
			summary_list_node->val += transfer;
		}
		if (summary_list_node->val > 9)
		{
			transfer = summary_list_node->val / 10;
			summary_list_node->val %= 10;
		}
		else
		{
			transfer = 0;
		}
		
		l1 = l1->next;
		l2 = l2->next;

		if (summary_list->val == -1)
		{
			summary_list->val = summary_list_node->val;
			head = summary_list;
		}
		else
		{
			summary_list->next = summary_list_node;
			summary_list = summary_list->next;
		}
	}

	while(l1)
	{
		ListNode* summary_list_node = new ListNode(0);
		
		summary_list_node->val = l1->val;

		if (transfer)
		{
			summary_list_node->val += transfer;
		}
		if (summary_list_node->val > 9)
		{
			transfer = summary_list_node->val / 10;
			summary_list_node->val %= 10;
		}
		else
		{
			transfer = 0;
		}
		summary_list->next = summary_list_node;
		summary_list = summary_list->next;
		l1 = l1->next;
	}

	while (l2)
	{
		ListNode* summary_list_node = new ListNode(0);
		summary_list_node->val = l2->val;

		if (transfer)
		{
			summary_list_node->val += transfer;
		}
		if (summary_list_node->val > 9)
		{
			transfer = summary_list_node->val / 10;
			summary_list_node->val %= 10;
		}
		else
		{
			transfer = 0;
		}
		summary_list->next = summary_list_node;
		summary_list = summary_list->next;
		
		l2 = l2->next;
	}

	if (transfer)
	{
		ListNode* summary_list_node = new ListNode(transfer);
		summary_list->next = summary_list_node;
	}

	return head;
}


int main()
{
	ListNode* a1 = new ListNode(1);
	ListNode* a2 = new ListNode(8);
	/*ListNode* a3 = new ListNode(9);*/
	//ListNode* a4 = new ListNode(9);
	//ListNode* a5 = new ListNode(9);
	//ListNode* a6 = new ListNode(9);

	a1->next = a2;
	a2->next = 
	/*	a3;
	a3->next =*/
		/* a4;
	a4->next = a5;
	a5->next = a6;
	a6->next = */nullptr;

	ListNode* b1 = new ListNode(0);
	/*ListNode* b2 = new ListNode(6);
	ListNode* b3 = new ListNode(4);
	ListNode* b4 = new ListNode(9);*/

	b1->next = /*b2;
	b2->next = b3;
	b3->next = b4;
	b4->next = */nullptr;

	addTwoNumbers(a1, b1);

	delete 	a1;
	delete	a2;
	//delete	a3;
	//delete  a4;
	//delete  a5;
	//delete  a6;
	delete  b1;
	//delete	b2;
	//delete	b3;
	//delete	b4;

	return 0;
}

#include <iostream>
#include <list>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	// Runtime 16 ms
	// Memory 15.1 MB
	if (l1 == nullptr && l2 == nullptr)
	{
		return l1;
	}

	if (l1 == nullptr)
	{
		return l2;
	}
	else if (l2 == nullptr)
	{
		return l1;
	}
	ListNode* l3 = new ListNode(-1);
	ListNode* temp_1 = l1;
	ListNode* temp_2 = l2;

	while (temp_1 != nullptr && temp_2 != nullptr)
	{
		if (temp_1->val <= temp_2->val)
		{

			if (l3->val == -1)
			{
				l3 = temp_1;
				temp_1 = temp_1->next;
				l3->next = nullptr;
			}
			else
			{
				ListNode* temp = l3;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->next = temp_1;
				temp_1 = temp_1->next;
				temp->next->next = nullptr;
			}

		}
		else
		{
			if (l3->val == -1)
			{
				l3 = temp_2;
				temp_2 = temp_2->next;
				l3->next = nullptr;
			}
			else
			{
				ListNode* temp = l3;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->next = temp_2;
				temp_2 = temp_2->next;
				temp->next->next = nullptr;
			}
		}
	}

	if (temp_1 == nullptr && temp_2 != nullptr)
	{
		ListNode* temp = l3;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = temp_2;
	}
	else if (temp_1 != nullptr && temp_2 == nullptr)
	{
		ListNode* temp = l3;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = temp_1;
	}

	return l3;
}


int main()
{
	ListNode* l1 = new ListNode(2);
	/*ListNode* l1_1 = new ListNode(2);
	ListNode* l1_2 = new ListNode(4);

	l1->next = l1_1;
	l1_1->next = l1_2;*/

	ListNode* l2 = new ListNode(1);
	//ListNode* l2_1 = new ListNode(3);
	//ListNode* l2_2 = new ListNode(4);

	//l2->next = l2_1;
	//l2_1->next = l2_2;

	mergeTwoLists(l1, l2);

	return 0;
}

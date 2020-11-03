#include <iostream>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) 
{
	// 65 / 65 test cases passed.
	// Runtime : 28 ms
	// Memory Usage : 15.3 MB
	// 2 ways of solution

	// Check if the value is at head. 
	// Cases like 1->1.
	while (head && head->val == val)
	{
		if (head->next)
		{
			head = head->next;
		}
		else
		{
			head = nullptr;
		}
	}
	
	if (!head)
	{
		return head;
	}

	ListNode* temp(head);
	while (temp)
	{
		if (temp->next && temp->next->val == val)
		{
			temp->next = temp->next->next;
		}
		else
		{
			temp = temp->next;  
		}
	}


	//ListNode* temp(head);
	//while (temp)
	//{
		/*if (temp->val == val && temp == head)
			{
				// Cases like 1->1.
				// 1->1->2.
				if (temp->next)
				{
					head = temp->next;
					temp = temp->next;
				}
				else
				{
					head = nullptr;
					break;
				}
			}
			else if (temp->next)
			{
				if (temp->next->val == val)
				{
					temp->next = temp->next->next;
				}
				else
				{
					temp = temp->next;
				}
			}
			else
			{
				temp = temp->next;
			}*/
//	}

	return head;
}

int main()
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(1);
	ListNode* c = new ListNode(2);
	ListNode* d = new ListNode(1);
	ListNode* e = new ListNode(4);
	ListNode* f = new ListNode(6);
	ListNode* g = new ListNode(5);

	a->next = b;
	b->next /*= c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next*/ = nullptr;

	removeElements(a, 1);

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
		
	return 0;
}
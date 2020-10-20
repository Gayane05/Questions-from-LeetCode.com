#include <iostream>
#include <set>

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) 
{

	// 17 / 17 test cases passed.
	// Runtime : 32 ms
	// Memory Usage : 9.9 MB

	//std::set<ListNode *> nodes;
	//int i = 0;
	//ListNode temp(0);

	//if (head != nullptr)
	//{
	//	temp.next = head;

	//	while (temp.next != nullptr)
	//	{
	//		if (nodes.find(temp.next) == nodes.end())
	//		{
	//			nodes.insert(temp.next);
	//			temp.next = temp.next->next;
	//		}
	//		else
	//		{
	//			return true;
	//		}
	//	}
	//}

	// NTBM
	// 17 / 17 test cases passed.
	// Runtime : 8 ms
	// Memory Usage : 7.8 MB
	if (head == nullptr) 
	{
		return false;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;
	while (slow != fast) 
	{
		if (fast == nullptr || fast->next == nullptr) 
		{
			return false;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;

}


int main()
{
	ListNode a(3);
	ListNode b(2);
	ListNode c(0);
	ListNode d(-4);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &b;


	hasCycle(&a);

	return 0;
}
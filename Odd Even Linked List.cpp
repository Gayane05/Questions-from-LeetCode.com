#include <iostream>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) 
{
	// 71 / 71 test cases passed.
	// Runtime: 16 ms
	// Memory Usage : 11 MB
	ListNode* odd = nullptr;
	ListNode* even = nullptr;
	ListNode* evenHead = nullptr;

	if (!head)
	{
		return nullptr;
	}
	else if (!head->next)
	{
		return head;
	}
	else
	{
		odd = head;
		even = head->next;
		evenHead = head;
	}

	evenHead = even;
	while (even && even->next)
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenHead;

	return head;
}


int main()
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(5);
	ListNode* f = new ListNode(6);
	ListNode* g = new ListNode(7);
	ListNode* h = new ListNode(8);

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
	h->next = nullptr;

	oddEvenList(a);

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;

	return 0;
}

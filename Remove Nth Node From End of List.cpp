#include <iostream>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	// 208 / 208 test cases passed.
	// Runtime : 0 ms
	// Memory Usage : 11.2 MB

	ListNode* temp = head;
	int length = 0;

	while (temp != nullptr)
	{
		length++;
		temp = temp->next;
	}

	if (length < n || (length == 1 && n == 1))
	{
		return nullptr;
	}

	temp = head;
	ListNode* prev = head;
	ListNode* next = nullptr;
	ListNode* find = nullptr;

	int l = 0;
	bool prev_ = false;
	bool next_ = false;

	while (l < length)
	{
		if (l == length - n - 1)
		{
			prev = temp;
			prev_ = true;
		}
		else if(l == length - n + 1)
		{
			next = temp;
			next_ = true;
			break;
		}
		else if (l == length - n)
		{
			find = temp;
		}
		temp = temp->next;

		++l;
	}

	if (prev_ && next_ || prev_)
	{
		prev->next = next;
	}
	else if (next_)
	{
		if (head == find)
		{
			temp = head->next;
			head->next = nullptr;
			head = temp;
		}
	}

	return head;
}

int main()
{

	ListNode a(1);
	ListNode b(2);
	//ListNode c(3);
	//ListNode d(4);
	//ListNode e(5);

	a.next = &b;
	b.next = /*&c;
	c.next = &d;
	d.next = &e;
	e.next =*/ nullptr;

	removeNthFromEnd(&a, 2);

	return 0;
}
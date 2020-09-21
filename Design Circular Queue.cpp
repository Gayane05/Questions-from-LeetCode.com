#include <iostream>
#include <vector>

// 52 / 52 test cases passed.
// Runtime: 48 ms
// Memory Usage : 16.6 MB
class MyCircularQueue 
{
public:

	MyCircularQueue(int k) : size(k), head(-1), tail(-1)
	{
		queue.resize(size);
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) 
	{
		if (!isFull())
		{
			if (isEmpty())
			{
				head++;
			}
			if (tail == size - 1)
			{
				tail = -1;
			}
			queue[++tail] = value;
			
			return true;
		}
		return false;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() 
	{
		if (!isEmpty())
		{
			if (head == tail)
			{
				head = -1;
				tail = -1;
				return true;
			}
			if (head == size - 1)
			{
				head = -1;
			}
			head++; 
			return true;
		}
		return false;
	}

	/** Get the front item from the queue. */
	int Front() 
	{
		if (!isEmpty())
		{
			return queue[head];
		}
		return -1;
	}

	/** Get the last item from the queue. */
	int Rear() 
	{
		if(!isEmpty())
		{
			return queue[tail];
		}
		return -1;
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() 
	{
		return (head == tail && tail == -1);
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() 
	{
		return (tail - head == size - 1 || head - tail == 1);
	}

private:
	std::vector<int> queue;
	int head;
	int tail;
	int size;
};

int main()
{
	MyCircularQueue* obj = new MyCircularQueue(5);
	bool param_1 = obj->enQueue(5);
	param_1 = obj->enQueue(13);
	obj->enQueue(8);
	obj->enQueue(2);
	obj->enQueue(10);
	bool param_6 = obj->isFull();
	bool param_2 = obj->deQueue();
	param_2 = obj->deQueue(); 
	obj->enQueue(23);
	obj->enQueue(6);
	param_6 = obj->isFull();
	param_2 = obj->deQueue();
	param_2 = obj->deQueue();
	param_2 = obj->deQueue();
	param_2 = obj->deQueue();
	param_2 = obj->deQueue();

	bool param_5 = obj->isEmpty();

	return 0;
}

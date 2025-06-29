#include "Queue.h"
#include "PriorityQueue.h"

int main() {
	// 1

	Queue<int> queue;
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5);
	queue.Dequeue();
	queue.Dequeue();
	queue.Dequeue();
	queue.Show();

	// 2

	PriorityQueue<int> pq;

	pq.InsertWithPriority(10);
	pq.InsertWithPriority(5);
	pq.InsertWithPriority(20);
	pq.InsertWithPriority(15);

	pq.Show();

	std::cout << "Peek: " << pq.Peek() << '\n'; // 20

	pq.PullHighestPriorityElement();
	pq.Show();

	pq.PullHighestPriorityElement();
	pq.Show();
	return 0;
}
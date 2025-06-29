#pragma once

#include <iostream>

template <typename T>
class Queue {
private:
	T* data;
	int head;
	int tail;
	int size;
	int capacity;

	void Resize(int newCapacity) {
		T* newData = new T[newCapacity];
		for (int i = 0; i < size; ++i) {
			newData[i] = data[(head + i) % capacity];
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
		head = 0;
		tail = size;
	}

public:

	Queue() = default;

	~Queue() {
		delete[] data;
	}

	bool isEmpty() const {
		return size == 0;
	}

	bool isFull() const {
		return size == capacity;
	}

	void Enqueue(const T& element) {
		if (isFull()) {
			int newCap = (capacity == 0) ? 4 : capacity * 2;
			Resize(newCap);
		}
		data[tail] = element;
		tail = (tail + 1) % capacity;
		++size;
	}

	void Dequeue() {
		if (!isEmpty()) {
			head = (head + 1) % capacity;
			--size;
		}
	}

	void Show() {
		for (int i = 0; i < size; ++i) {
			std::cout << data[(head + i) % capacity] << ' ';
		}
		std::cout << '\n';
	}
};
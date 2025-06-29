#pragma once

#include <iostream>

template <typename T>
class PriorityQueue {
private:
    T* data = nullptr;
    int size = 0;
    int capacity = 0;

    void Resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    PriorityQueue(int initialCapacity = 4) {
        capacity = initialCapacity;
        data = new int[capacity];
    }

    ~PriorityQueue() {
        delete[] data;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return size == capacity;
    }

    void InsertWithPriority(int value) {
        if (IsFull()) {
            Resize(capacity * 2);
        }
        int i = size - 1;
        while (i >= 0 && data[i] < value) {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = value;
        ++size;
    }

    void PullHighestPriorityElement() {
        if (IsEmpty()) {
            return;
        }
        for (int i = 1; i < size; ++i)
            data[i - 1] = data[i];
        --size;
    }

    int Peek() const {
        if (IsEmpty()) {
            return -1;
        }
        return data[0];
    }

    void Show() const {
        if (IsEmpty()) {
            return;
        }
        for (int i = 0; i < size; ++i)
            std::cout << data[i] << ' ';
        std::cout << '\n';
    }
};
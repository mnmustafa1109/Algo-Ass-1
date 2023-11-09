#include <iostream>
#include <vector>
#include <climits>
#include "Passenger.hxx"

class MaxPriorityQueue
{
private:
    std::vector<Passenger> heap; // 1D vector of Passenger objects

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int rightChild(int i)
    {
        return 2 * i + 2;
    }

    void maxHeapify(int i)
    {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int heapSize = heap.size();

        if (left < heapSize && heap[left].getId() > heap[largest].getId())
            largest = left;

        if (right < heapSize && heap[right].getId() > heap[largest].getId())
            largest = right;

        if (largest != i)
        {
            std::swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    MaxPriorityQueue() {} // Default constructor

    MaxPriorityQueue(const std::vector<Passenger> &initialHeap) : heap(initialHeap)
    {
        // Build the heap
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
        {
            maxHeapify(i);
        }
    }

    void maxHeapInsert(const Passenger &newPassenger)
    {
        heap.push_back(newPassenger);
        int i = heap.size() - 1;

        while (i > 0 && heap[parent(i)].getId() < newPassenger.getId())
        {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    Passenger heapExtractMax()
    {
        if (heap.size() < 1)
        {
            std::cerr << "Heap underflow\n";
            // You might want to handle the error case better
            return Passenger("", "", "", "", 0, "", "", "", "", "", "", "", "", "", "");
        }

        Passenger maxPassenger = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0);

        return maxPassenger;
    }

    void increaseKey(int i, const std::string &newKey)
    {
        if (newKey < heap[i].getId())
        {
            std::cerr << "New key is smaller than the current key\n";
            return;
        }

        heap[i].setId(newKey);

        while (i > 0 && heap[parent(i)].getId() < heap[i].getId())
        {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    Passenger maximum()
    {
        if (heap.size() < 1)
        {
            std::cerr << "Heap is empty\n";
            return Passenger("", "", "", "", 0, "", "", "", "", "", "", "", "", "", "");
        }

        return heap[0];
    }
};

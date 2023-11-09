#include <iostream>
#include <vector>
#include <climits>
#include "Passenger.hxx"

class MinPriorityQueue
{
private:
    std::vector<Passenger> heap; 

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

    void minHeapify(int i)
    {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int heapSize = heap.size();

        if (left < heapSize && heap[left].getId() < heap[smallest].getId())
            smallest = left;

        if (right < heapSize && heap[right].getId() < heap[smallest].getId())
            smallest = right;

        if (smallest != i)
        {
            std::swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }

public:
    MinPriorityQueue() {} 

    MinPriorityQueue(const std::vector<Passenger> &initialHeap) : heap(initialHeap)
    {
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
        {
            minHeapify(i);
        }
    }

    void minHeapInsert(const Passenger &newPassenger)
    {
        heap.push_back(newPassenger);
        int i = heap.size() - 1;

        while (i > 0 && heap[parent(i)].getId() > newPassenger.getId())
        {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    Passenger heapExtractMin()
    {
        if (heap.size() < 1)
        {
            std::cerr << "Heap underflow\n";
            return Passenger("", "", "", "", 0, "", "", "", "", "", "", "", "", "", "");
        }

        Passenger minPassenger = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        minHeapify(0);

        return minPassenger;
    }

    void decreaseKey(int i, const std::string &newKey)
    {
        if (newKey > heap[i].getId())
        {
            std::cerr << "New key is larger than the current key\n";
            return;
        }

        heap[i].setId(newKey);

        while (i > 0 && heap[parent(i)].getId() > heap[i].getId())
        {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    Passenger minimum()
    {
        if (heap.size() < 1)
        {
            std::cerr << "Heap is empty\n";
            return Passenger("", "", "", "", 0, "", "", "", "", "", "", "", "", "", "");
        }

        return heap[0];
    }
    

    int getSize()
    {
        return heap.size();
    }


    std::vector<Passenger> getHeap()
    {
        return heap;
    }
};

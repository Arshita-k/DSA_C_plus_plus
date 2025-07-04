#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Min Heap Implementation
class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) return -1;
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    int peek() {
        return heap.empty() ? -1 : heap[0];
    }

    void print() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

// Max Heap Implementation
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) return -1;
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    int peek() {
        return heap.empty() ? -1 : heap[0];
    }

    void print() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

// Example Usage
int main() {
    // Min Heap Example
    MinHeap minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    cout << "Min Heap: ";
    minHeap.print();
    cout << "Min Element: " << minHeap.peek() << endl;
    minHeap.pop();
    cout << "After Pop: ";
    minHeap.print();

    // Max Heap Example
    MaxHeap maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    cout << "Max Heap: ";
    maxHeap.print();
    cout << "Max Element: " << maxHeap.peek() << endl;
    maxHeap.pop();
    cout << "After Pop: ";
    maxHeap.print();

    return 0;
}

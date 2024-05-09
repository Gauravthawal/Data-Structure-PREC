/*Read the marks obtained by students of second year in an online Examination of particular subject.
Find out maximum and minimum marks obtained in that subject. Use heap data structure.
Analyze the algorithm.*/
#include<iostream>
using namespace std;

class Heap {
    int maxHeap[20], minHeap[20], size;
public:
    Heap() { maxHeap[0] = minHeap[0] = size = 0; }
    void getData();
    void insert(int[], int);
    void adjust(int[], int);
    void minMax();
};

void Heap::getData() {
    cout << "\nEnter the number of students: ";
    cin >> size;
    cout << "\nEnter the marks: ";
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        insert(maxHeap, x);
        insert(minHeap, x);
    }
}

void Heap::insert(int heap[], int x) {
    int n = heap[0];
    heap[++n] = x;
    heap[0] = n;
    adjust(heap, n);
}

void Heap::adjust(int heap[], int i) {
    while (i > 1 && ((heap == maxHeap && heap[i] > heap[i / 2]) || (heap == minHeap && heap[i] < heap[i / 2]))) {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}

void Heap::minMax() {
    cout << "\nMax marks: " << maxHeap[1] << "\n##\n";
    for (int i = 1; i <= size; i++) 
        cout << maxHeap[i] << endl;
    cout << "\nMin marks: " << minHeap[1] << "\n##\n";
    for (int i = 1; i <= size; i++) 
        cout << minHeap[i] << endl;
}

int main() {
    Heap h;
    h.getData();
    h.minMax();
    return 0;
}



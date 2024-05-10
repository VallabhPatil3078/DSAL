#include <iostream>
using namespace std;

class heap {
    int* arr;
    int capacity;
    int count;

public:
    heap(int size = 10) {
        capacity = size;
        arr = new int[capacity];
        count = 0;
        for (int i = 0; i < capacity; i++) {
            arr[i] = 0;
        }
    }

    ~heap() {
        delete[] arr;
    }

    void insert();
    void heapify(int data);
    void display();
    void heapsort();
};

void heap::insert() {
    int data;
    cout << "Enter number of elements to insert: ";
    int num_elements;
    cin >> num_elements;

    for (int i = 0; i < num_elements; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        heapify(data);
    }
}

void heap::heapify(int data) {
    arr[count] = data;
    int i = count;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (arr[parent] < arr[i]) {
            swap(arr[parent], arr[i]);
            i = parent;
        } else {
            break;
        }
    }
    count++;
}

void heap::display() {
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heap::heapsort() {
    int count1 = count - 1;
    while (count1 > 0) {
        swap(arr[0], arr[count1]);
        count1--;
        int i = 0;
        while (i * 2 + 1 <= count1) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            int max_child = left;
            if (right <= count1 && arr[right] > arr[left]) {
                max_child = right;
            }
            if (arr[i] < arr[max_child]) {
                swap(arr[i], arr[max_child]);
                i = max_child;
            } else {
                break;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter initial size of heap: ";
    cin >> size;
    heap h(size);
    h.insert();
    cout << "Heap before sorting: ";
    h.display();
    h.heapsort();
    cout << "Heap after sorting: ";
    h.display();
    return 0;
}
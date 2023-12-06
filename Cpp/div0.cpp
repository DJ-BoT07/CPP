#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void heapSort(vector<int>& arr) {
    // Convert the array into a max heap
    make_heap(arr.begin(), arr.end());

    // Sort the heap
    sort_heap(arr.begin(), arr.end());
}

int main() {
    // Create an unsorted vector
    vector<int> numbers = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Perform Heap Sort
    heapSort(numbers);

    cout << "Sorted array: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

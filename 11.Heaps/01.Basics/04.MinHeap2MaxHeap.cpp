#include <vector>
#include <cassert>
#include <iostream>

template <typename T>
void siftDownMax(std::vector<T>& data, std::size_t n, std::size_t index) {
    assert(index < n);
    for (;;) {
        std::size_t largest = index;
        std::size_t left    = 2 * index + 1;
        std::size_t right   = 2 * index + 2;

        if (left < n && data[left] > data[largest]) {
            largest = left;
        }
        if (right < n && data[right] > data[largest]) {
            largest = right;
        }

        if (largest == index) {
            break;
        }

        std::swap(data[index], data[largest]);
        index = largest;
    }
}

template <typename T>
void convertMinHeapToMaxHeap(std::vector<T>& heap) {
    const std::size_t n = heap.size();
    if (n <= 1) return;

    for (std::size_t i = n / 2; i-- > 0; ) {
        siftDownMax(heap, n, i);
    }
}

int main() {
    std::vector<int> minHeap = {1, 3, 2, 7, 6, 4, 5};

    convertMinHeapToMaxHeap(minHeap);

    std::cout << "Array as max-heap: ";
    for (int x : minHeap) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}

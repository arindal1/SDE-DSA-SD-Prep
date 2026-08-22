#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;

void processBatch(const vector<int>& batch) {
    // Simulate fixed overhead + per-item work
    this_thread::sleep_for(milliseconds(20));   // setup cost
    this_thread::sleep_for(milliseconds(10 * batch.size())); // per item cost
}

int main() {
    vector<int> items(10);
    for (int i = 0; i < 10; ++i) items[i] = i;

    auto start = high_resolution_clock::now();

    // Process in two batches of 5
    processBatch(vector<int>(items.begin(), items.begin() + 5));
    processBatch(vector<int>(items.begin() + 5, items.end()));

    auto end = high_resolution_clock::now();
    auto totalMs = duration_cast<milliseconds>(end - start).count();

    cout << "Batched processing time: " << totalMs << " ms\n";
    return 0;
}

// Batched processing time: 199 ms

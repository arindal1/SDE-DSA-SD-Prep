#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;

void doWork(int id) {
    this_thread::sleep_for(milliseconds(120));
}

int main() {
    const int tasks = 10;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < tasks; ++i) {
        doWork(i);
    }

    auto end = high_resolution_clock::now();
    auto totalMs = duration_cast<milliseconds>(end - start).count();

    double throughput = (tasks * 1000.0) / totalMs;

    cout << "Processed " << tasks << " tasks in " << totalMs << " ms\n";
    cout << "Throughput: " << throughput << " tasks/sec\n";
    return 0;
}

// Processed 10 tasks in 1347 ms
// Throughput: 7.4239 tasks/sec

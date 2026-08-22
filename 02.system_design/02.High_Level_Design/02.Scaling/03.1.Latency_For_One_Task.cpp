#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

void doWork() {
    this_thread::sleep_for(milliseconds(120));
}

int main() {
    auto start = steady_clock::now();

    doWork();

    auto end = steady_clock::now();
    auto latency = duration_cast<milliseconds>(end - start).count();

    cout << "Single request latency: " << latency << " ms\n";
    return 0;
}

// Single request latency: 127 ms
#include <iostream>
#include <chrono>
#include "array_list.hpp"

int main() {
    int n;
    std::cin >> n;
    array_list l1;
    auto beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_front(x);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - beg).count();
    if (l1.size() != n) {
        std::cerr << "[ERROR] check push_front method!\n";
        return 1;
    }
    std::cerr << "[INFO] " << "Elapsed time for " << n << " pushes front: " << elapsed << " microseconds\n";
    return 0;
}

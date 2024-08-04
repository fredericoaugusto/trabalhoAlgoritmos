#include <iostream>
#include <random>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: Need to inform 'n'\n";
        return 1;
    }
    int n = std::stoi(argv[1]);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(1, n * 2);
    std::cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << dist(mt) << "\n";
    }
    return 0;
}

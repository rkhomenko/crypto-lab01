#include <ZZFactoring.h>

#include <chrono>
#include <ctime>
#include <iostream>

using namespace NTL;

void mul(ZZ& n, const vec_pair_ZZ_long& factorization) {
    n = 1;
    for (long i = 0; i < factorization.length(); ++i) {
        n *= power(factorization[i].a, factorization[i].b);
    }
}

int main() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    bool verbose = false;

    ZZ n, nc;
    vec_pair_ZZ_long factorization;

    std::cin >> n;
    std::cerr << n << std::endl;

    auto printTime = [](auto&& time) {
        auto t = std::chrono::high_resolution_clock::to_time_t(time);
        std::cout << std::ctime(&t) << std::endl;
    };

    start = std::chrono::high_resolution_clock::now();
    printTime(start);

    factor(factorization, n, ZZ::zero(), 0, verbose);
    std::cout << factorization << std::endl;

    mul(nc, factorization);

    if (n != nc) {
        std::cout << "check=" << nc << std::endl;
        Error("FAILED FACTORIZATION");
    }

    end = std::chrono::high_resolution_clock::now();
    printTime(end);

    std::cout
        << "total: "
        << std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
        << "s" << std::endl;

    return 0;
}

#include <iostream>
#include <chrono>

struct Test {
	Test(long N) : n(N) {
		long sum = 0;
		for (long i = 0; i < n; ++i) {
			sum += i;
		}
	}

	Test() : n(1e8) {
		Test(n);
	}

	long n;
}; // struct Test

int main(int argc, char* argv[]) {
	const long N(1e8);
	auto start = std::chrono::system_clock::now();
	Test t1 = Test(N);
	auto stop = std::chrono::system_clock::now();

	std::cout << "Test t1 = Test() took " << (stop - start).count() << " to initialize\n";

	start = std::chrono::system_clock::now();
	Test t2(N);
	stop = std::chrono::system_clock::now();

	std::cout << "Test t2(N) took " << (stop - start).count() << " s to initialize\n";

	return 0;
}
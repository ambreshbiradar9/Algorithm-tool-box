#include <iostream>
#include <vector>

using std::vector;

long long get_fibonacci_huge_fast(long long n) {
	n = n % 60;
	if (n <= 1)
		return n;
	int previous = 0;
	int current = 1;
	for (int i = 0; i < n - 1; ++i) {
		int tmp_previous = previous % 10;
		previous = current % 10;
		current = tmp_previous + current % 10;
	}
	return current % 10;
}
	

long long fibonacci_partial_sum_fast(long long from_, long long to) {
	long long from_last, to_last;
	if (from_ == to) {
		return get_fibonacci_huge_fast(from_ % 60);
	}
	else {
		from_ = from_ % 60;
		to = to % 60;

		from_last = get_fibonacci_huge_fast(from_ + 1) - 1;
		to_last = get_fibonacci_huge_fast(to + 2) - 1;
	}
	int rturn = 0;
	rturn =(to_last - from_last)% 10;
	return rturn + (rturn < 0 ? 10 : 0);
}

int main() {
	long long from, to;
	std::cin >> from >> to;
	std::cout << (fibonacci_partial_sum_fast(from, to))<< '\n';
	system("pause");
}
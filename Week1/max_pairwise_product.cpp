#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
long long MaxPairwiseProductfast(const std::vector< long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
	int max_index1 = -1;
	for (int i = 0; i < n; ++i)
	{
		if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
		{
			max_index1 = i;
		}
	}
	int max_index2 = -1;
	for (int j = 0; j < n; j++)
	{
		if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
		{
			max_index2 = j;
		}
	}
	max_product = numbers[max_index1] * numbers[max_index2];
    return max_product;
}

long long MaxPairwiseProduct(const std::vector< long long>& numbers) {
	long long max_product = 0;
	int n = numbers.size();
	 for (int first = 0; first < n; ++first) {
	   for (int second = first + 1; second < n; ++second) {
	     max_product = std::max(max_product,numbers[first] * numbers[second]);
	 }
	}
	return max_product;
}

int main() {


	*while (true)
	{
		int n = rand() % 1000 + 2;
		std::cout << n << "\n";
		std::vector<long long> a;
		for (int i = 0; i < n; i++)
		{
			a.push_back(rand() % 100000);
		}
		for (int i = 0; i < n; i++)
		{
			std::cout << a[i] << ' ';
		}
		std::cout << "\n";
		long long res1 = MaxPairwiseProduct(a);
		long long res2 = MaxPairwiseProductfast(a);
		if (res1 != res2)
		{
			std::cout << " wrong answer: " << res1 << ' ' << res2 << "\n";
			break;
		}
		else {
			std::cout << "OK\n";
		}
	}
int n;
   std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
std::cout << MaxPairwiseProductfast(numbers) << "\n";
	system("pause");
    return 0;
}

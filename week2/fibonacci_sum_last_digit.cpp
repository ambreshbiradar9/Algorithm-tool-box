#include <iostream>

int fibonacci_sum_naive(long long n) {
   
	if (n <= 1)
        return n;
	int reptitions = 0,residue=0;
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

	reptitions = ((n + 1) / 60);

//	std::cout << reptitions << '\n';
	
	residue = ((n + 1) % 60);

//	std::cout << residue << '\n';

	if (residue == 0)
	{
		return 0;
	}

	if (residue < 3)
	{
		return residue-1;
	}

	for (long long i = 3; i <= residue ; ++i)
	{
		long long tmp_previous = previous;
		previous = current;
		current = (tmp_previous % 10 + current % 10);
		sum = (sum + current) % 10;
	//	std::cout << sum << '\n';   
	}
	
	

    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
	//system("pause");
}



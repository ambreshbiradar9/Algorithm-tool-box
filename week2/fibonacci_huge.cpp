#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    //
	if (n <= 1)
        return (n);
	//
    long long previous = 0;
	long long current = 1;
	long long current1=0, current2=0;
	int i = 1, recur = 0, reptitions=0,residue=0;
	while (true)
	{
    long long tmp_previous = previous;
			previous = current;
			current = (tmp_previous + current)%m;
			if (current == 0)
			{
				current1 = previous + current;
				if ((current1 % m) == 1)
				{
					current2 = current1 + current;
					if ((current2 % m) == 1)
					{
						break;
					}
				}
			}
		i = i + 1;
	//	std::cout << i << '\n';
	}

	recur = i;
	std::cout << "repetations" << recur+1 <<'\n';
	reptitions = ((n+1) / (recur+1));
	//std::cout << "number count" << reptitions<< '\n';
	residue = ((n+1) % (recur+1));
	//std::cout << "residue" <<residue<< '\n';
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	/////////
	if ((residue > 0) && (residue <= 2))
	{
		return (residue - 1);
	}

	if (residue == 0)
	{
		previous = 0;
		current = 1;

		for (int j = 3; j <= (recur+1); j++)
		{
			long long   tmp_previous = previous;
			previous = current;
			current = (tmp_previous + current) % m;
		}
		return current ;
	}

	previous = 0;
	current = 1;

	for(int j = 3; j <= residue;j++)
	{
    long long   tmp_previous = previous;
		previous = current;
		current = (tmp_previous + current)%m;
	}
    
	return current;
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	system("pause");
}

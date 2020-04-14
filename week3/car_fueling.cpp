#include <iostream>
#include <vector>
#include<algorithm>


using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> stops) {
	int numrefills = 0,n;
	int currentrefill = 0,lastrefill;
	n = stops.size();
	//cout << n;
	while (currentrefill <= (n-2))
	{
		lastrefill = currentrefill;
		while ((currentrefill <= (n-2)) && ((stops[currentrefill + 1] - stops[lastrefill]) <= tank))
		{
			currentrefill++;
		}
		if (currentrefill == lastrefill)
		{
			return -1;
		}
		if (currentrefill <= (n-2))
		{
			numrefills++;
		}
	}


	return numrefills;
}


int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

	stops.insert(stops.begin(), 0);
	stops.push_back(d);
//	for (size_t i = 0; i < n+2; ++i)
	//	cout << stops.at(i);


    cout << compute_min_refills(d, m, stops) << "\n";
	system("pause");
	return 0;
}

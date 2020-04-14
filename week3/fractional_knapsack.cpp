#include <iostream>
#include <vector>

using std::vector;

int maximum_index(vector<int> weights, vector<int> values)
{
	int temp, n;
	n= weights.size();
	//std::cout << n;
	//system("pause");
	temp = 0;
	for (int i = 0; i < n; i++)
	{
		double fraction;
		fraction = ((double(values[i])) / weights[i]);
		if (fraction >((double(values[temp])) / weights[temp]))
		{
			temp = i;
		}
	}
	return temp;
}

int minimum(int n, int w)
{
	if (n <= w)
	{
		return n;
	}
	else
		return w;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  if (capacity == 0)
  {
	  return 0;
  }
  int totcurrent=0;
  int index = 0;

  while ( capacity > 0)
  {
	  index = maximum_index(weights, values);
	  //std::cout << index<<'\n';
	  
	  int temp = weights[index];

	  int wt = minimum(capacity,temp);

	  double current =((double(values[index])) / weights[index]);

	  value += current*wt;

	  capacity -= wt;

	  values[index] = 0;
	  //system("pause");
  }
  // write your code here
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  system("pause");
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  
 if (left == right) 
	  return 0;
  if (left + 1 == right) 
	  return 0;
  //write your code here
  int mid = 0;
  sort(a.begin(), a.end());
  
 // for (size_t i = 0; i < a.size(); ++i)
  //{
	//  std::cout << a[i] <<'\n';
  //}


  int first, second;
  first = left;
  second = left+1;
  int sum = 0;
  int count = 1;

  while (second <= right-1)
  {
	  if (a[first] == a[second])
	  {
		  count++;
		  second++;
	  }
	  else if (a[first]!= a[second])
	  {
		 // std::cout << "the count " << count << '\n';
		  if (sum < count)
		  {
			  sum = count;
			 // std::cout <<"the sum is "<<sum << '\n';
		  }
		  count = 1;
		  first = second;
		  second++;
	  }
  }
 // std::cout << "the sum is " << sum << '\n';

  if ((sum > (right / 2))||(count > (right / 2)))
  {
	  return 1;
  }
  
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) 
  {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size())  << '\n';
 // system("pause");
}

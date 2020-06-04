#include <iostream>
#include <vector>
#include <limits.h>

int get_change(int m) 
{
  //write your code here denominations are 1,3 and 4
  std::vector <int> coins={1,3,4};
  //std:: cout<< coins[0];
  std::vector <int> arr(m+1);
  arr[0]=0;
  int numc=0;
  for(int i=1;i<=m;i++)
  {
    arr[i]=INT_MAX;
    for(int j=0;j<3;j++)
    {
      if(i>=coins[j])
      {
        numc=arr[i-coins[j]]+1;
      }
      if(numc<arr[i])
      {
        arr[i]=numc;        
      }
    }
  }
  return arr[m];
}

int main() 
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}


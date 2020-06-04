#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using std::vector;

vector<int> optimal_sequence(int n) 
{
  std::vector<int> arr(n+1);
  arr[0]=0;
  arr[1]=0;
  for(int i=2;i<=n;i++)
  { 
    int min=INT_MAX;  
    if ((i % 3 == 0)&&(i>=3)&&(min>arr[i/3])) 
    {
        min=arr[i/3];
    } 
    if ((i % 2 == 0)&&(i>=2)&&(min>arr[i/2])) 
    {
        min=arr[i/2];
    }
    if(min>arr[i-1])
    {
        min=arr[i-1];
    }
    arr[i]=min+1;
  }
  //std::cout<<arr[n]<<'\n';
  
  int j=n;  
  int temp=INT_MAX;
  std::vector<int> push;
  push.push_back(j);
  while(j>1)
  {
    temp=arr[j]-1;
    if((j%3==0)&&(j>=3)&&(temp==arr[j/3]))
    {
      push.push_back(j/3);
      j=j/3;
    }
    else if((j%2==0)&&(j>=2)&&(temp==arr[j/2]))
    {
      push.push_back(j/2);
      j=j/2;
    }
    else if((temp==arr[j-1])&&(j>1))
    {
      if(j-1==0)
      {
        reverse(push.begin(), push.end());
        return push;      
      }
      push.push_back(j-1);
      j=j-1;
    }
  } 
  reverse(push.begin(), push.end());
  return push;
}

int main() 
{
  int n;
  std::cin >> n;
  int c;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
  std::cout << sequence[i] << " ";
  }
  return 1;
}

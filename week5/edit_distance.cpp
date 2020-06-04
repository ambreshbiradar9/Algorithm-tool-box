#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2) 
{
  int m=str1.size();
  int n=str2.size();
  int d[m+1][n+1];
  for (int i=0;i<=n;i++)
  {
    d[0][i]=i;
  }
  for (int j=0;j<=m;j++)
  {
    d[j][0]=j;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      int ins=d[j-1][i]+1;
      int del=d[j][i-1]+1;
      if(str1[j-1]==str2[i-1])
      {
        int match =d[j-1][i-1];
        d[j][i]=min({ins,del,match});
      }
      else
      {
        int mismatch=d[j-1][i-1]+1;
        d[j][i]=min({ins,del,mismatch});
      }
    }
  }
  //write your code here
  return d[m][n];
}

int main() 
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

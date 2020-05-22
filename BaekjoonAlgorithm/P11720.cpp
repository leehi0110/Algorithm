// Baekjoon 11720
// 문제
// 숫자의 합

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  int sum = 0;
  string number;

  cin >> n;
  cin >> number;

  for(int i=0;i<n;i++){
    sum += number[i] - '0';
  }

  cout << sum;
}
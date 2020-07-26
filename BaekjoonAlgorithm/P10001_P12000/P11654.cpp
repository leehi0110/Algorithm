// Baekjoon 11654
// 문제
// 아스키 코드

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  char val;

  cin >> val;

  cout << static_cast<int>(val) << endl;
}
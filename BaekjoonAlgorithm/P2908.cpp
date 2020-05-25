// Baekjoon 2908
// 문제
// 상수

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int reverse(string number);

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  string a ,b;

  cin >> a >> b;

  for(int i=2;i>-1;i--){
    if(a[i] - '0' > b[i] - '0'){
      cout << reverse(a) << endl;
      break;
    }
    else if(a[i] - '0' < b[i] - '0'){
      cout << reverse(b) << endl;
      break;
    }
    else continue;
  }
}

int reverse(string number)
{
  int result = 0;

  for(int i=2;i>-1;i--){
    result *= 10;
    result += number[i] - '0';
  }

  return result;
}
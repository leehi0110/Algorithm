// Baekjoon 1152
// 문제
// 단어의 개수

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  int number = 0;

  getline(cin,str);

  for(int i=0;i<str.length();i++){
    if(i+1 == str.length()){
      if(str[i] != ' ') number ++;
      else continue;
    }
    else if(str[i] != ' ' && str[i+1] == ' '){
      number ++;
    }
  }

  cout << number << endl;
}
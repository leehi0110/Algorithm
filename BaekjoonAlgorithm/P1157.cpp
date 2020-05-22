// Baekjoon 1157
// 문제
// 단어 공부

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  string str;
  char maxAlph;
  int maxNum = 0; 
  vector <int> alph(26,0);

  cin >> str;

  for(int i=0;i<str.length();i++){
    alph[toupper(str[i]) - 65] ++;

    if(alph[toupper(str[i]) -65] > maxNum){
      maxNum = alph[toupper(str[i]) -65];
      maxAlph = toupper(str[i]);
    }
    else if(alph[toupper(str[i]) -65] == maxNum){
      maxAlph = '?';
    }
    else {
      continue;
    }
  }

  cout << maxAlph << endl;

}
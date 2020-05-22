// Baekjoon 10809
// 문제
// 알파벳 찾기

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  string str;
  vector <int> alph(26,-1);

  cin >> str;

  for(int i=0;i<str.length();i++){
    if(alph[str[i] - 97] == -1){
      alph[str[i] - 97] += (i+1);
    }
    else continue;
  }

  for(int i=0;i<alph.size();i++){
    cout << alph[i] << " ";
  }
  cout << "\n";
}
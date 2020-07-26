// Baekjoon 2941
// 문제
// 크로아티아 알파벳

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  string target;
  int alphNum = 0;

  cin >> target;
  
  for(int i=0;i<target.length();i++){
    if(i == 0) alphNum ++;
    else if(target[i] == '='){
      if(target[i-1] == 'c' || target[i-1] == 's') continue;
      else if(target[i-1] == 'z'){
        if(target[i-2] == 'd') alphNum --;
        else continue;
      }
    }
    else if(target[i] == '-'){
      if(target[i-1] == 'c' || target[i-1] == 'd') continue;
    }
    else if(target[i] == 'j'){
      if(target[i-1] == 'l' || target[i-1] == 'n') continue;
      else alphNum ++;
    }
    else alphNum ++;
    
  }

  cout << alphNum << endl;
}
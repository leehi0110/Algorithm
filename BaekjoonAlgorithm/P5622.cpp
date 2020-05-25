// Baekjoon 5622
// 문제
// 다이얼

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  string alph;
  int time = 0;

  cin >> alph;

  for(int i=0;i<alph.size();i++){
    if(alph[i] == 'A' || alph[i] == 'B' || alph[i] == 'C') time += 3;
    else if(alph[i] == 'D' || alph[i] == 'E' || alph[i] == 'F') time += 4;
    else if(alph[i] == 'G' || alph[i] == 'H' || alph[i] == 'I') time += 5;
    else if(alph[i] == 'J' || alph[i] == 'K' || alph[i] == 'L') time += 6;
    else if(alph[i] == 'M' || alph[i] == 'N' || alph[i] == 'O') time += 7;
    else if(alph[i] == 'P' || alph[i] == 'Q' || alph[i] == 'R' || alph[i] == 'S') time += 8;
    else if(alph[i] == 'T' || alph[i] == 'U' || alph[i] == 'V') time += 9;
    else time += 10;
  }

  cout << time << endl;;
}
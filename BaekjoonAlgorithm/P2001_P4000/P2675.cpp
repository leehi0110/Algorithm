// Baekjoon 2675
// 문제
// 문자열 반복

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int testCase;

  cin >> testCase;

  for(int i=0;i<testCase;i++){
    int r;
    string input;
    string output;

    cin >> r >> input;
  
    for(int j=0;j<input.length();j++){
      for(int k=0;k<r;k++){
        output += input[j];
      }
    }
    cout << output << endl; 
    output.clear();
  }
}
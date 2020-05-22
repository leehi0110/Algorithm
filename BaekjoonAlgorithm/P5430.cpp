// Baekjoon 5430
// 문제
// AC

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
  int testCase;
  int n;
  char val;
  bool isReverse;
  string cmd;

  deque <char> array;
  deque <char> ::iterator iter;

  cin >> testCase;

  for(int i=0;i<testCase;i++){
    cin >> cmd;
    cin >> n;

    val = ' ';
    isReverse = false;
    array.clear();

    while(val != ']'){
      cin >> val;
      array.push_back(val);
    }

    for(int j=0;j<cmd.length();j++){
      if(cmd[j] == 'R'){
        isReverse = !isReverse;
      }
      else { // cmd[j] == 'D'
        if(array.size() == 2){
          cout << "error" << endl;
          break;
        }
        else {
          if(isReverse){
            iter = array.end() - 2;
            array.erase(iter);
            iter --;
            array.erase(iter);
          }
          else {
            iter = array.begin() + 1;
            array.erase(iter);
            iter ++;
            array.erase(iter);
          }
        }
      }

      if(j+1 == cmd.length()){
        if(isReverse){
          cout << '[';
          for(int k=array.size()-2;k>0;k--){
            cout << array[k];
          }
          cout << ']' << endl;
        }
        else {
          for(int k=0;k<array.size();k++){
            cout << array[k];
          }
          cout << "\n";
        }
      }
    }
  }
}
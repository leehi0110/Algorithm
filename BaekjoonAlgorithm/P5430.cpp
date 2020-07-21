// Baekjoon 5430
// 문제
// 큐, 덱
// AC

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int test_case;

  cin >> test_case;

  while(test_case--){
    string cmd, array_string, number = "";
    int array_size;
    bool reverse = false;
    deque <int> array;

    cin >> cmd >> array_size >> array_string;

    if(array_size != 0){
      for(int i=1;i<array_string.length();i++){
       if(isdigit(array_string[i])){
          number += array_string[i];
        }
        else {
         array.push_back(stoi(number));
         number = "";
        }
      }
    }
    number = "";
    for(int i=0;i<cmd.length();i++){
      if(cmd[i] == 'R'){
        reverse = !reverse;
      }
      else {
        if(array.empty()) {
          number = "error";
          break;
        }
        else if(reverse){
          array.pop_back();
        }
        else array.pop_front();
      }
    }

    if(!number.length()){
      number = '[';
      if(!reverse){
        for(int i=0;i<array.size();i++){
          number += to_string(array[i]);
          if(i != array.size()-1) number += ',';
        }
        number += ']';
      }// 정방향
      else {
        for(int i=array.size()-1;i>=0;i--){
          number += to_string(array[i]);
          if(i != 0) number += ',';
        }
        number += ']';
      } // 역방향
    }
    
    cout << number << "\n";
  }

}

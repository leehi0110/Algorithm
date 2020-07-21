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

  for(int i=0;i<test_case;i++){
    string cmd, array_string, number = "";
    int array_size, reverse_cnt = 0, delete_cnt = 0;
    deque <int> array;

    cin >> cmd >> array_size >> array_string;

    for(int j=0;j<cmd.length();j++){
      if(cmd[j] == 'R') reverse_cnt++;
      else delete_cnt ++;
    }

    if(delete_cnt > array_size) cout << "error" << "\n";
    else if(delete_cnt == array_size) cout << "[]" << "\n";
    else {
      for(int j=1;j<array_string.length();j++){
        if(isdigit(array_string[j])){
          number += array_string[j];
        }
        else {
          array.push_back(stoi(number));
          number = "";
        }
      }

      if(reverse_cnt%2 == 0) {
        for(int j=0;j<delete_cnt;j++){
          array.pop_front();
        }
        number = '[';
        
        for(int j=0;j<array.size();j++){
          number += to_string(array[j]);
          if(j == array.size()-1){
            number += ']';
          }
          else {
            number += ',';
          }
        }
      }
      else {
        for(int j=0;j<delete_cnt;j++){
          array.pop_back();
        }

        number = '[';

        for(int j=array.size()-1;j>=0;j--){
          number += to_string(array[j]);
          if(!j){
            number += ']';
          }
          else number += ',';
        }
      }
      cout << number << "\n";
    }
  }
}

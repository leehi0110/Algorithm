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
    string cmd, array;
    string result = "";
    int number_element = 0;
    int n, delete_cnt=0, back_cnt=0;
    
    cin >> cmd >> n >> array;

    for(int i=0;i<cmd.length();i++){
      if(cmd[i] == 'R') back_cnt++;
      else delete_cnt++;
    }

    if(delete_cnt > n) {
      cout << "error" << endl;
      continue;
    }

    deque <int> number;

    for(int i=1;i<array.length();i++){
      if(isdigit(array[i])){
        number_element *= 10;
        number_element += array[i]- '0';
      }
      else {
        number.push_back(number_element);
        number_element = 0;
      }
    }

    result += '[';
    if(back_cnt%2 == 0) {
      for(int i=0;i<delete_cnt;i++){
        number.pop_front();
      }
      for(int i=0;i<number.size();i++){
        result += to_string(number[i]);
        if(i != number.size()-1){
          result += ',';
        }
      }
    }
    else {
      for(int i=0;i<delete_cnt;i++){
        number.pop_back();
      }
      for(int i=number.size()-1;i>=0;i--){
        result += to_string(number[i]);
        if(i != 0){
          result += ',';
        }
      }
    }
    result += ']'; 
    cout << result << endl;
  }
}

// int main()
// {
//   int testCase;
//   int n;
//   char val;
//   bool isReverse;
//   string cmd;

//   deque <char> array;
//   deque <char> ::iterator iter;

//   cin >> testCase;

//   for(int i=0;i<testCase;i++){
//     cin >> cmd;
//     cin >> n;

//     val = ' ';
//     isReverse = false;
//     array.clear();

//     while(val != ']'){
//       cin >> val;
//       array.push_back(val);
//     }

//     for(int j=0;j<cmd.length();j++){
//       if(cmd[j] == 'R'){
//         isReverse = !isReverse;
//       }
//       else { // cmd[j] == 'D'
//         if(array.size() == 2){
//           cout << "error" << endl;
//           break;
//         }
//         else {
//           if(isReverse){
//             iter = array.end() - 2;
//             array.erase(iter);
//             iter --;
//             array.erase(iter);
//           }
//           else {
//             iter = array.begin() + 1;
//             array.erase(iter);
//             iter ++;
//             array.erase(iter);
//           }
//         }
//       }

//       if(j+1 == cmd.length()){
//         if(isReverse){
//           cout << '[';
//           for(int k=array.size()-2;k>0;k--){
//             cout << array[k];
//           }
//           cout << ']' << endl;
//         }
//         else {
//           for(int k=0;k<array.size();k++){
//             cout << array[k];
//           }
//           cout << "\n";
//         }
//       }
//     }
//   }
// }
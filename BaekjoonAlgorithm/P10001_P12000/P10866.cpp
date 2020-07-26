// Baekjoon 10866
// 문제
// 덱

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
  // ios_base :: sync_with_stdio(false);
  // cin.tie(NULL);
  
  int n;
  int val;
  string cmd;
  deque <int> array;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> cmd;

    if(cmd == "push_front"){
      cin >> val;
      array.push_front(val);
    }
    else if(cmd == "push_back"){
      cin >> val;
      array.push_back(val);
    }
    else if(cmd == "pop_front"){
      if(array.empty()) cout << -1 << "\n";
      else {
        cout << array.front() << "\n";
        array.pop_front();
      }
    }
    else if(cmd == "pop_back"){
      if(array.empty()) cout << -1 << "\n";
      else {
        cout << array.back() << "\n";
        array.pop_back();
      }
    }
    else if(cmd == "size"){
      cout << array.size() << "\n";
    }
    else if(cmd == "empty"){
      cout << array.empty() << "\n";
    }
    else if(cmd == "front"){
      if(array.empty()) cout << -1 << "\n";
      else cout << array.front() << "\n";
    }
    else {
      if(array.empty()) cout << -1 << "\n";
      else cout << array.back() << "\n";
    }
  }
}
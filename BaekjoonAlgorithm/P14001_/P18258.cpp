// Baekjoon 18258
// 문제
// 큐2

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
  // ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cin.sync_with_stdio(0);
  
  deque <int> que;
  int n,data;
  string cmd;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> cmd;

    if(cmd == "push"){
      cin >> data;
      que.push_back(data);
    }
    else if(cmd == "pop"){
      if(que.empty()) cout << -1 << "\n";
      else {
        cout << que.front() << "\n";
        que.pop_front();
      }
    }
    else if(cmd == "size"){
      cout << que.size() << "\n";
    }
    else if(cmd == "empty"){
      if(que.empty()) cout << 1 << "\n";
      else cout << 0 << "\n";
    }
    else if(cmd == "front"){
      if(que.empty()) cout << -1 << "\n";
      else cout << que.front() << "\n";
    }
    else {
      if(que.empty()) cout << -1 << "\n";
      else cout << que.back() << "\n";
    }
  }
}
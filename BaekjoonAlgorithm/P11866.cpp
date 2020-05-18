// Baekjoon 11866
// 문제
// 요세푸스 문제 0

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{ 
  int n, k ;
  int index;
  deque <int> que;
  deque <int> ::iterator iter;
  deque <int> order;

  cin >> n >> k;

  for(int i=1;i<n+1;i++){
    que.push_back(i);
  }

  index = k-1;

  while(!que.empty()){

    if(que.size()-1 >= index){
      order.push_back(que[index]);
    
      iter = que.begin();

      for(int i=0;i<index;i++){
        iter ++;
      }

      que.erase(iter);
      index += k-1;
    }
    else {
      index = index - que.size();
    }
  }
  cout << '<';

  for(int i=0;i<order.size();i++){
    cout << order[i];
    if(i+1 == order.size()){
      break;
    }
    else cout << ", ";
  }

  cout << ">" << endl;
}
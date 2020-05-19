// Baekjoon 1021
// 문제
// 회전하는 큐

#include <iostream>
#include <deque>
#include <string>

using namespace std;
void right_move(deque<int> &array);
void left_move(deque<int> &array);

int main()
{
  // ios_base :: sync_with_stdio(false);
  // cin.tie(NULL);
  
  int queSize;
  int num;
  int cnt = 0;

  deque <int> array;
  deque <int> order;

  cin >> queSize >> num;

  for(int i=1;i<queSize+1;i++){
    array.push_back(i);
  }

  for(int i=0;i<num;i++){
    int val;
    cin >> val;
    order.push_back(val);
  }

  while(order.size()){
    int target = order.front();
    int leftCnt;
    int rightCnt;

    for(int i=0;i<array.size();i++){
      if(array[i] == target){
        leftCnt = i;
        rightCnt = array.size() - i - 1;
        break;
      }
    }

    if(leftCnt > rightCnt){
      for(int i=0;i<rightCnt+1;i++){
        right_move(array);
        cnt ++;
      }
      array.pop_front();
    }
    else {
      for(int i=0;i<leftCnt;i++){
        left_move(array);
        cnt ++;
      }
      array.pop_front();
    }

    order.pop_front();
  }

  cout << cnt << endl;
}

void left_move(deque<int> &array)
{
  array.push_back(array[0]);
  array.pop_front();
}

void right_move(deque<int> &array)
{
  array.push_front(array.back());
  array.pop_back();
}
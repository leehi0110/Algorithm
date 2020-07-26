// Baekjoon 1966
// 문제
// 프린터 큐

#include <iostream>
#include <deque>
#include <string>

using namespace std;
bool isMax(deque<int> &print);

int main()
{
  // ios_base :: sync_with_stdio(false);
  // cin.tie(NULL);

  int testCase;
  int fileNum, target;
  int pri;
  int cnt;
  deque <int> print;

  cin >> testCase;

  for(int i=0;i<testCase;i++){
    
    cin >> fileNum >> target;

    cnt = 0;
    print.clear();

    for(int j=0;j<fileNum;j++){
      cin >> pri;
      print.push_back(pri);
    }

    while(1){

      if(isMax(print)){
        cnt ++;
        if(target == 0){
          break;
        }
        else {
          print.pop_front();
        }
      }
      else {
        print.push_back(print[0]);
        print.pop_front();
      }

      if(target == 0){
        target = print.size()-1;
      }
      else target --;

    }

    cout << cnt << endl;
  }
}

bool isMax(deque<int> &print)
{
  for(int i=1;i<print.size();i++){
    if(print[0] < print[i]) return false;
    
    if(i+1 == print.size()) return true;
  }

  return true;
}

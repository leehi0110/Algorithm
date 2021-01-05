// ProblemNumber || ProblemName : 더 맵게
// 문제
// 모든 음식의 스코빌 지수를 K이상으로 만들기 위한 최소횟수를 구하라

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset<int> temp(scoville.begin(),scoville.end());

    while(1) {
      multiset<int>::iterator iter = temp.begin();
      int n = *iter;
      iter++;
      int m = *iter;
      iter++;

      if(n < K) {
        if(temp.size() == 1) return -1;
        else{
          temp.erase(temp.begin(),iter);
          temp.insert(n+(m*2));
          answer++;
        }
      }
      else return anwer;
    }
}

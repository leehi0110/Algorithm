#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head)
{
  vector<int> answer;
  priority_queue<pair<pair<double, int>, pair<int, int>>> pq;
  // 정렬기준 승률, 무거운 복서 이긴 횟수, 몸무게 무거움, 복서번호가 작은쪽
  // - - - +

  for (int i = 0; i < head2head.size(); i++)
  {
    string match = head2head[i];
    int loseCnt = 0, winCnt = 0, bigCnt = 0;

    for (int j = 0; j < match.length(); j++)
    {
      if (match[j] == 'L')
        loseCnt++;
      else if (match[j] == 'W')
      {
        winCnt++;

        if (weights[i] < weights[j])
          bigCnt++;
      }
    }

    double rating = 0;
    if (winCnt + loseCnt != 0)
      rating = winCnt / static_cast<double>(winCnt + loseCnt);

    pq.push({{rating, bigCnt}, {weights[i], -i}});
  }

  while (!pq.empty())
  {
    int num = -pq.top().second.second;
    pq.pop();

    answer.push_back(num + 1);
  }

  return answer;
}

int main()
{
  // vector<int> result = solution({50, 82, 75, 120}, {"NLWL", "WNLL", "LWNW", "WWLN"});
  vector<int> result = solution({145, 92, 86}, {"NLW", "WNL", "LWN"});
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int solution(vector<vector<int>> jobs)
{
  int answer = 0;
  int time = 0;

  multimap<int, int> works;

  for (auto job : jobs)
  {
    works.insert({job[0], job[1]});
  }

  // answer += works.begin()->second;
  // time = works.begin()->first + works.begin()->second;
  // works.erase(works.begin());

  while (!works.empty())
  {
    int minDuration = works.begin()->second;
    auto minIter = works.begin();

    for (auto it = ++works.begin(); it != works.end(); it++)
    {
      if (it->first <= time)
      {
        if (minDuration > it->second)
        {
          minIter = it;
          minDuration = it->second;
        }
      }
      else
        break;
    }

    answer += time - minIter->first + minIter->second;
    time += minIter->second;
    works.erase(minIter);
  }

  answer /= jobs.size();

  return answer;
}

int main()
{
  int result = solution({{0, 3}, {1, 9}, {2, 6}});

  cout << result << endl;
}
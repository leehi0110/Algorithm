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

  while (!works.empty())
  {
    auto minIter = works.begin();

    if (minIter->first > time)
    {
      time = minIter->first;
    }

    for (auto it = works.begin(); it != works.end(); it++)
    {
      if (it->first <= time)
      {
        if (it->second < minIter->second)
        {
          minIter = it;
        }
      }
      else
        break;
    }

    answer += time - minIter->first + minIter->second;
    time += minIter->second;
    works.erase(minIter);
  }

  return answer /= jobs.size();
}

int main()
{
  // int result = solution({{0, 3}, {1, 9}, {2, 6}});
  int result = solution({{0, 3}, {4, 4}, {5, 3}, {4, 1}});

  cout << result << endl;
}
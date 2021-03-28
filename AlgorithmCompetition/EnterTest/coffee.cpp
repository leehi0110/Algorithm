#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int N, vector<int> coffee_times)
{
  // multimap<long int, int> table;
  map<int, vector<int>> table;
  vector<int> answer;
  int delayTime = 0;
  int outIdx;

  if (N == 1)
  {
    for (int i = 0; i < coffee_times.size(); i++)
    {
      answer.push_back(i + 1);
    }
    return answer;
  }

  // for (int i = 0; i < coffee_times.size(); i++)
  // {
  //   if (table.size() < N)
  //   {
  //     table.insert(pair<long int, int>(coffee_times[i] + delayTime, i));
  //   }
  //   else
  //   {
  //     delayTime = table.begin()->first;
  //     outIdx = table.begin()->second;

  //     answer.push_back(outIdx + 1);
  //     table.erase(table.begin());
  //     i--;
  //   }

  for (int i = 0; i < coffee_times.size(); i++)
  {
    if (table.size() < N)
    {
      if (find(table.begin(), table.end(), coffee_times[i] + delayTime) == table.end())
      {
        table.insert(pair<int, vector<int>>(coffee_times[i] + delayTime, {i}));
      }
      else
      {
        table[coffee_times[i] + delayTime].push_back(i);
      }
    }
    else
    {
      delayTime = table.begin()->first;
      if (table.begin()->second.size() == 1)
      {
        outIdx = table.begin()->second[0];
        table.erase(table.begin());
      }
      else
      {
        outIdx = table.begin()->second[0];
        table.begin()->second.erase(table.begin()->second.begin());
      }

      answer.push_back(outIdx + 1);
      i--;
    }
  }

  for (auto it = table.begin(); it != table.end(); it++)
  {
    for (int j = 0; j < it->second.size(); j++)
    {
      answer.push_back(it->second[j] + 1);
    }
  }
  // for (auto it = table.begin(); it != table.end(); it++)
  // {
  //   answer.push_back(it->second + 1);
  // }

  return answer;
}

// vector<int> solution(int N, vector<int> coffee_times)
// {
//   int idx = 0;
//   vector<int> answer;
//   vector<pair<int, int>> vc;

//   if (N == 1)
//   {
//     for (int i = 1; i <= coffee_times.size(); i++)
//     {
//       answer.push_back(i);
//     }
//     return answer;
//   }

//   while (1)
//   {

//     if (idx >= coffee_times.size())
//     {

//       for (int i = 0; i < vc.size(); i++)
//       {
//         answer.push_back(vc[i].second);
//       }
//       break;
//     }

//     if (vc.size() < N)
//     {
//       vc.push_back(pair<int, int>(coffee_times[idx], idx + 1));
//       idx++;
//     }
//     else
//     {
//       int time = vc[0].first;
//       int endIdx = vc[0].second;

//       vc.erase(vc.begin(), vc.begin() + 1);

//       answer.push_back(endIdx);
//       for (int i = 0; i < vc.size(); i++)
//       {
//         vc[i].first -= time;
//       }
//     }
//     sort(vc.begin(), vc.end());
//   }

//   return answer;
// }

int main()
{
  vector<int> result = solution(3, {4, 2, 2, 5, 3});

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
}
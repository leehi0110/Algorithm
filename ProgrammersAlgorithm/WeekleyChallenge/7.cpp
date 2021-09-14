#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave)
{
  vector<int> answer;
  queue<int> leaveQue;
  vector<int> room;
  map<int, vector<int>> meet;
  int idx = 0;

  for (int i = 1; i < enter.size() + 1; i++)
  {
    meet.insert({i, {}});
  }

  for (int i = 0; i < leave.size(); i++)
  {
    leaveQue.push(leave[i]);
  }

  while (!leaveQue.empty())
  {
    int nowOut = leaveQue.front();

    if (find(room.begin(), room.end(), nowOut) == room.end())
    {
      room.push_back(enter[idx]);

      for (int i = 0; i < room.size() - 1; i++)
      {
        meet[room[i]].push_back(enter[idx]);
        meet[enter[idx]].push_back(room[i]);
      }
      idx++;
    }
    else
    {
      room.erase(find(room.begin(), room.end(), nowOut));
      leaveQue.pop();
    }
  }

  for (auto it = meet.begin(); it != meet.end(); it++)
  {
    answer.push_back(it->second.size());
  }

  return answer;
}

int main()
{
  // vector<int> result = solution({1, 4, 2, 3}, {2, 1, 3, 4});
  vector<int> result = solution({1, 4, 2, 3}, {2, 1, 4, 3});

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }
}
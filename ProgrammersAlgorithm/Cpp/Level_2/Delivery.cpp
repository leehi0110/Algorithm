#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
  int answer = 0;
  vector<vector<int>> arr(N + 1, vector<int>(N + 1, 9999999));

  for (int i = 0; i <= N; i++)
  {
    for (int j = 0; j <= N; j++)
    {
      if (i == j)
        arr[i][j] = 0;
    }
  }

  for (int i = 0; i < road.size(); i++)
  {
    if (arr[road[i][0]][road[i][1]] > road[i][2])
    {
      arr[road[i][0]][road[i][1]] = road[i][2];
      arr[road[i][1]][road[i][0]] = road[i][2];
    }
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      for (int k = 1; k <= N; k++)
      {
        arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
      }
    }
  }

  for (int i = 0; i <= N; i++)
  {
    if (arr[1][i] <= K)
      answer++;
  }

  return answer;
}
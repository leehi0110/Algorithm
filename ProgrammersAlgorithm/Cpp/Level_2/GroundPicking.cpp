#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int> land, int index)
{

  int max = -999;

  for (int i = 0; i < land.size(); i++)
  {
    if (i != index)
    {
      if (land[i] > max)
        max = land[i];
    }
  }

  return max;
}

int solution(vector<vector<int>> land)
{
  int answer = 0;

  vector<vector<int>> dp(land.size(), vector<int>(4, 0));

  dp[0][0] = land[0][0];
  dp[0][1] = land[0][1];
  dp[0][2] = land[0][2];
  dp[0][3] = land[0][3];

  for (int i = 1; i < land.size(); i++)
  {
    for (int j = 0; j < 4; j++)
    {
      int maxValue = getMax(dp[i - 1], j);
      dp[i][j] = land[i][j] + maxValue;
    }
  }

  for (int i = 0; i < 4; i++)
  {
    int temp = dp[land.size() - 1][i];
    if (temp > answer)
      answer = temp;
  }

  return answer;
}
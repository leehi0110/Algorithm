// ProblemNumber || ProblemName : 정수 삼각형

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
  int height = triangle.size();

  vector<vector<int>> dp(height);

  dp[0].push_back(triangle[0][0]);

  for (int i = 1; i < triangle.size(); i++)
  {

    for (int j = 0; j <= i; j++)
    {
      if (j - 1 < 0)
        dp[i].push_back(triangle[i][j] + dp[i - 1][j]);
      else if (j + 1 > dp[i - 1].size())
        dp[i].push_back(triangle[i][j] + dp[i - 1][j - 1]);
      else
      {
        dp[i].push_back(triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]));
      }
    }
  }

  auto it = max_element(dp[height - 1].begin(), dp[height - 1].end());

  return *it;
}
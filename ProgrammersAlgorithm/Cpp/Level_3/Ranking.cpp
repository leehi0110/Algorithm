#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
  int answer = 0;
  vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
  vector<int> cnt(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        table[i][j] = 1;
    }
  }

  for (int i = 0; i < results.size(); i++)
  {
    int winner = results[i][0];
    int loser = results[i][1];

    table[winner][loser] = 1;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i != j && table[i][j] == 1)
      {
        // i번 선수가 j번 선수를 이긴경우
        // i번 선수를 이긴 선수들은 자동적으로 j번 선수를 이긴다
        for (int k = 1; k <= n; k++)
        {
          if (i != k && table[k][i] == 1 && table[k][j] == 0)
          {
            table[k][j] = 1;
          }
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i != j && table[i][j] == 1)
        cnt[i]++;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i != j && table[j][i] == 1)
        cnt[i]++;
    }
  }

  for (int i = 1; i < cnt.size(); i++)
  {
    if (cnt[i] == n - 1)
      answer++;
  }

  return answer;
}

int main()
{
  int result = solution(5, {{4, 2}, {1, 2}, {2, 5}, {4, 3}, {3, 2}});
  // int result = solution(5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}});
  // int result = solution(8, {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}});
  // int result = solution(8, {{1, 2}, {2, 3}, {3, 4}, {5, 6}, {6, 7}, {7, 8}});

  cout << result << endl;
}
// ProblemNumber || ProblemName : P3078 - 좋은 친구
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  long long result = 0;
  int maxLen = 0;

  cin >> n >> k;

  vector<vector<int>> table(21);

  for (int i = 1; i <= n; i++)
  {
    string temp;
    int len;

    cin >> temp;
    len = temp.length();

    if (len > maxLen)
      maxLen = len;
    table[len].push_back(i);
  }

  for (int i = 2; i <= maxLen; i++)
  {
    if (table[i].size() == 0 || table[i].size() == 1)
      continue; // 길이가 같은 원소가 없거나 하나인 경우 => 쌍이 없음
    else
    {
      // 같은 이름을 가진 사람들의 랭크 vector<int> table[i];
      int startIdx = 0;
      int endIdx = 0;

      while (1)
      {
        if (endIdx == table[i].size())
        {

          if (startIdx == endIdx)
            break;

          result += static_cast<long long>(endIdx - startIdx - 1);
          startIdx++;
        }
        else if (table[i][endIdx] - table[i][startIdx] <= k)
        {
          endIdx++;
        }
        else
        {
          result += static_cast<long long>(endIdx - startIdx - 1);
          startIdx++;
        }
      }
    }
  }

  cout << result << endl;
}

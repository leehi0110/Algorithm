// ProblemNumber || ProblemName : P14465 - 소가 길을 건너간 이유 5
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, b, k;
  int maxSum = 0;
  int startIdx = 1;
  int sum = 0;

  cin >> n >> k >> b;
  // 신호등 n개 (1 ~ n)
  // 연속한 k개의 신호등
  // 망가진 b개의 신호등

  vector<int> light(n + 1, 1);

  for (int i = 0; i < b; i++)
  {
    int breakNumber;

    cin >> breakNumber;

    light[breakNumber] = 0;
  }

  for (int endIdx = 1; endIdx <= n; endIdx++)
  {
    sum += light[endIdx];
    if (endIdx >= k)
    {
      maxSum = max(maxSum, sum);
      if (light[startIdx] == 1)
        sum -= 1;
      startIdx++;
    }
  }

  cout << k - maxSum << endl;
}

// 1 2 3 4 5 6 7 8 9 10
// x x o o x o o o x x

// 10 6 5
// 2
// 10
// 1
// 5
// 9
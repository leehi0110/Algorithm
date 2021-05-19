#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 1e9

using namespace std;

long long solution(int n, vector<int> times)
{
  long long answer = INF;

  sort(times.begin(), times.end());
  long long left = 0;
  long long right = times[times.size() - 1] * n;
  long long mid = (left + right) / 2;

  while (left != mid)
  {
    int validNum = 0;

    for (int i = 0; i < times.size(); i++)
    {
      validNum += mid / times[i];
    }

    if (validNum < n)
    {
      left = mid;
    }
    else if (validNum > n)
    {
      right = mid;
    }
    else
    { // validNum == n
      if (answer > mid)
        answer = mid;

      right = mid;
    }

    mid = (left + right) / 2;
  }

  return answer;
}

int main()
{
  long long result = solution(6, {7, 10});
  cout << result << endl;
}

// n = 6
// 0 35 70 => 6 + 3 = 9
// 0 17 35 => 2 + 1 = 3
// 17 26 35 => 3 + 2 = 5
// 26 30 35 => 4 + 3 = 7
// 26 28 30 => 4 + 2 = 6
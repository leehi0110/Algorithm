#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 1e9

using namespace std;

long long solution(int n, vector<int> times)
{
  int test = 0;

  sort(times.begin(), times.end());
  long long left = 1;
  long long right = static_cast<long long>(times[times.size() - 1]) * n;
  long long mid;
  long long answer = right;

  while (left <= right)
  {
    int person = 0;
    mid = (left + right) / 2;

    for (int i = 0; i < times.size(); i++)
    {
      person += mid / static_cast<long long>(times[i]);
    }

    if (person < n)
    {
      left = mid + 1;
    }
    else // person > n && person == n
    {
      if (answer > mid)
      {
        answer = mid;
      }

      right = mid - 1;
    }
  }

  return answer;
}

int main()
{
  long long result = solution(6, {7, 10});
  // long long result = solution(3, {1, 2, 3, 4, 5});
  // long long result = solution(3, {1, 1, 1});
  // long long result = solution(3, {1, 2, 3});
  // long long result = solution(2, {1, 2, 2, 2, 100});

  cout << result << endl;
}
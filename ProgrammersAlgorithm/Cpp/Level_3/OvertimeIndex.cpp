#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
  long long answer = 0;
  long long sum = 0;
  priority_queue<int> pq;

  for (int i = 0; i < works.size(); i++)
  {
    pq.push(works[i]);
    sum += static_cast<long long>(works[i]);
  }

  if (sum <= n)
    return 0;

  for (int i = 0; i < n; i++)
  {
    int top = pq.top();
    pq.pop();

    pq.push(top - 1);
  }

  while (!pq.empty())
  {
    answer += pow(pq.top(), 2);
    pq.pop();
  }

  return answer;
}

int main()
{
  // long long result = solution(4, {4, 3, 3});
  // long long result = solution(1, {2, 1, 2});
  long long result = solution(3, {1, 1});

  cout << result << endl;
}

// [4, 3, 3]	4	12
// [2, 1, 2]	1	6
// [1,1]	3	0
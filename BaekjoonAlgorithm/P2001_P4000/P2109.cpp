// ProblemNumber || ProblemName : P2109 - 순회강연
// 하면서 좀 더 깊게 생각하게 된 것들
// -> find(vector.rbegin(), vector.rend(), element)를 이용해 뒤에서 처음으로 나오는 위치를 찾을 수 있다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int result = 0;
  priority_queue<pair<int, int>> pq;
  vector<bool> vaildDay(100001, true);

  cin >> n;

  vaildDay[0] = false;

  for (int i = 0; i < n; i++)
  {
    int pay, day;

    cin >> pay >> day;

    pq.push({pay, day});
  }

  while (!pq.empty())
  {
    int pay = pq.top().first;
    int day = pq.top().second;

    pq.pop();

    auto it = find(vaildDay.rbegin() + (vaildDay.size() - day - 1), vaildDay.rend(), true);

    if (it == vaildDay.rend())
      continue;
    else
    {
      *it = false;
      result += pay;
    }
  }

  cout << result << endl;
}
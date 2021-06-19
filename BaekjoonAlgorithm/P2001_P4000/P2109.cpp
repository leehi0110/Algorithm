// ProblemNumber || ProblemName : P2109 - 순회강연
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

  int n;
  int result = 0;
  priority_queue<pair<int, int>> pq;
  vector<bool> arr(10001, true);

  cin >> n;
  arr[0] = false;

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

    auto it = find(arr.rbegin() + (arr.size() - day), arr.rend(), true);
    if (it == arr.rend())
      continue;
    else
    {
      arr[it - arr.begin()] = true;
      result += pay;
    }

    // 반복문 없이 요일이 비었는지 확인하는 방법?

    // for (int i = day; i > 0; i--)
    // {
    //   if (find(arr.begin(), arr.end(), i) == arr.end())
    //   {
    //     result += pay;
    //     arr.push_back(i);
    //     break;
    //   }
    // }
  }

  cout << result << endl;
}

// 3
// 1 1
// 2 10
// 2 10
// 답 = 20

// 7
// 20 1
// 2 1
// 10 3
// 100 2
// 8 2
// 5 20
// 50 10

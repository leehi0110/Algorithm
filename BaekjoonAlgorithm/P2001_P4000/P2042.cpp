// ProblemNumber || ProblemName : P2042 - 구간 합 구하기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll init(int start, int end, int node);
ll sum(int start, int end, int node, int left, int right);
void update(int start, int end, int node, int index, ll diff);

int n, m, k;
vector<ll> arr;
ll tree[4 * 1000002];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  // n = 숫자의 개수
  // m = 수의 변경이 일어나는 횟수
  // k = 구간의 합을 구하는 횟수

  for (int i = 0; i < n; i++)
  {
    ll number;
    cin >> number;

    arr.push_back(number);
  }

  init(0, arr.size() - 1, 1);

  for (int i = 0; i < m + k; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    if (a == 1)
    {
      // 값 변경
      update(0, arr.size() - 1, 1, b - 1, static_cast<ll>(c) - arr[b - 1]);
      arr[b - 1] = static_cast<ll>(c);
    }
    else
    {
      // 구간 합 출력
      cout << sum(0, arr.size() - 1, 1, b - 1, c - 1) << "\n";
    }
  }
}

ll init(int start, int end, int node)
{
  if (start == end)
    return tree[node] = arr[start];
  int mid = (start + end) / 2;

  return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right)
{
  if (left > end || right < start)
    return 0;

  if (left <= start && end <= right)
    return tree[node];

  int mid = (start + end) / 2;
  return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, ll diff)
{
  if (index < start || index > end)
    return;

  tree[node] += diff;
  if (start == end)
    return;
  int mid = (start + end) / 2;

  update(start, mid, node * 2, index, diff);
  update(mid + 1, end, node * 2 + 1, index, diff);
}
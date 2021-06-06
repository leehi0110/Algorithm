// ProblemNumber || ProblemName : P2042 - 구간 합 구하기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int init(vector<long long> &tree, vector<int> arr, int start, int end, int node);
long long sum(vector<long long> tree, int start, int end, int left, int right, int node);
void update(vector<long long> &tree, int start, int end, int node, int index, int diff);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;

  cin >> n >> m >> k;

  vector<int> arr;
  vector<long long> tree(n * 4);
  // n = 숫자의 개수
  // m = 수의 변경이 일어나는 횟수
  // k = 구간의 합을 구하는 횟수

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  init(tree, arr, 0, arr.size() - 1, 1);

  for (int i = 0; i < m + k; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    if (a == 1)
    { // b번째 수를 c로 바꾼다
      update(tree, 1, arr.size(), 1, b, c - arr[b - 1]);
      arr[b - 1] = c;
    }
    else
    { // b번째 수부터 c번째 수까지의 구간합을 구한다.
      cout << sum(tree, 0, arr.size() - 1, b - 1, c - 1, 1) << "\n";
    }
  }
}

void update(vector<long long> &tree, int start, int end, int node, int index, int diff)
{
  if (index < start || index > end)
    return;
  tree[node] += static_cast<long long>(diff);

  if (start == end)
    return;

  int mid = (start + end) / 2;

  update(tree, start, mid, node * 2, index, diff);
  update(tree, mid + 1, end, node * 2 + 1, index, diff);
}

long long sum(vector<long long> tree, int start, int end, int left, int right, int node)
{
  if (left > end || right < start)
    return 0;
  else if (left <= start && right >= end)
    return tree[node];
  else
  {
    int mid = (start + end) / 2;
    return sum(tree, start, mid, left, right, node * 2) + sum(tree, mid + 1, end, left, right, node * 2 + 1);
  }
}

int init(vector<long long> &tree, vector<int> arr, int start, int end, int node)
{
  if (start == end)
    return tree[node] = static_cast<long long>(arr[start]);
  int mid = (start + end) / 2;

  return tree[node] = static_cast<long long>(init(tree, arr, start, mid, node * 2) + init(tree, arr, mid + 1, end, node * 2 + 1));
}

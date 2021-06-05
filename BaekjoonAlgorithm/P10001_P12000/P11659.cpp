// ProblemNumber || ProblemName : P11659 - 구간 합 구하기4
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 세그먼트 트리 알고리즘
// -> 이진트리를 이용해 구간합을 구해 준 뒤, 범위의 합을 구한다 => 재귀를 이용한다.
// -> 세그먼트 트리를 만드는 원리 및 과정을 알고 바로 구현할 수 있어야한다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int init(vector<int> &arr, vector<int> &tree, int start, int end, int node);
long long sum(vector<int> &tree, int index, int start, int end, int left, int right);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<int> arr;
  vector<int> tree(n * 4);

  for (int i = 0; i < n; i++)
  {
    int num;

    cin >> num;

    arr.push_back(num);
  }

  init(arr, tree, 0, arr.size() - 1, 1);

  for (int i = 0; i < m; i++)
  {
    int a, b;

    cin >> a >> b;
    cout << sum(tree, 1, 1, arr.size(), a, b) << "\n";
  }
}

long long sum(vector<int> &tree, int index, int start, int end, int left, int right)
{
  if (left > end || right < start) // 구하려하는 구간이 벗어난 경우
    return 0;
  else if (left <= start && right >= end) // 구하려는 구간이 내부에 있을 경우
    return tree[index];
  else // 구하려는 구간이 겹쳐 있는 경우 반으로 나눠서 다시 탐색
  {
    int mid = (start + end) / 2;
    return sum(tree, index * 2, start, mid, left, right) + sum(tree, index * 2 + 1, mid + 1, end, left, right);
  }
} // 구간의 합을 구하는 함수 SUM()

int init(vector<int> &arr, vector<int> &tree, int start, int end, int node)
{
  if (start == end) // 단말 노드일 경우 배열의 값을 트리의 값에 입력
    return tree[node] = arr[start];
  int mid = (start + end) / 2; // 중간까지의 누적합을 구할 수 있도록 재귀 호출

  return tree[node] = init(arr, tree, start, mid, (node * 2)) + init(arr, tree, mid + 1, end, (node * 2) + 1);
} // 세그먼트 트리를 만드는 함수 init()
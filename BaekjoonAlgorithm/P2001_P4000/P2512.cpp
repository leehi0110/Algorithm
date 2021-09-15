// ProblemNumber || ProblemName : P2512 - 예산
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n;
int total;
int maxResult = 0;
vector<int> budget;

void binarySearched(vector<int> budget, int total);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int want;
    cin >> want;
    budget.push_back(want);
  }

  sort(budget.begin(), budget.end());

  cin >> total;

  binarySearched(budget, total);

  cout << maxResult << endl;
}

void binarySearched(vector<int> budget, int total)
{
  int start = 0;
  int end = budget[budget.size() - 1];
  int mid = (start + end) / 2;

  while (start <= end)
  {

    int sum = 0;

    for (int i = 0; i < budget.size(); i++)
    {
      if (budget[i] <= mid)
        sum += budget[i];
      else
        sum += mid;
    }

    if (sum <= total)
    {
      if (mid > maxResult)
        maxResult = mid;
      start = mid + 1;
      mid = (start + end) / 2;
    }
    else
    {
      end = mid - 1;
      mid = (start + end) / 2;
    }
  }
}

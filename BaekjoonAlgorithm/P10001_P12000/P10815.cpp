// ProblemNumber || ProblemName : P10815 - 숫자카드
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int number;
vector<int> cards;
vector<int> result;
void binarySearch(int number);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> number;
    cards.push_back(number);
  }

  sort(cards.begin(), cards.end());

  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> number;
    binarySearch(number);
  }

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i];
    if (i != result.size() - 1)
      cout << " ";
    else
      cout << endl;
  }
}

void binarySearch(int number)
{
  int start = 0;
  int end = n - 1;
  int mid = (start + end) / 2;

  while (start <= end)
  {
    if (cards[mid] == number)
    {
      result.push_back(1);
      return;
    }
    else if (cards[mid] < number)
    {
      start = mid + 1;
    }
    else
    { // cards[mid] > number
      end = mid - 1;
    }
    mid = (start + end) / 2;
  }

  result.push_back(0);
}

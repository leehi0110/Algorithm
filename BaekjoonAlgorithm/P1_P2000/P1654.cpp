// ProblemNumber || ProblemName : P1654 - 랜선 자르기
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 주어진 조건을 고려해서 변수형을 설정해야한다.
// -> 나누기 연산자와 이진탐색을 이용할 떄 0으로 나눠지는 경우를 예외처리한다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
typedef long long ll;

using namespace std;

int n, k;
vector<ll> cable;
ll result = 0;

void getMaxLen();

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    ll len;
    cin >> len;

    cable.push_back(len);
  }

  sort(cable.begin(), cable.end());
  result = 1;
  getMaxLen();

  cout << result << endl;
}

void getMaxLen()
{
  ll start = 0;
  ll end = cable[cable.size() - 1];
  ll mid = (end + start) / 2;

  while (start <= end && mid != 0)
  {
    int getCnt = 0;

    for (int i = 0; i < cable.size(); i++)
    {
      getCnt += cable[i] / mid;
    }

    if (getCnt >= k)
    {

      if (mid >= result)
      {
        result = mid;
      }
      start = mid + 1;
      mid = (end + start) / 2;
    }
    else
    {
      end = mid - 1;
      mid = (end + start) / 2;
    }
  }
}

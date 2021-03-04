// ProblemNumber || ProblemName : 2667 단지 번호 붙이기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int isSameApt(vector<vector<int>> &arr, int x, int y, int N, int idx);
bool comp(pair<int, int> a, pair<int, int> b);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  vector<vector<int>> arr;
  vector<pair<int, int>> result;

  for (int i = 0; i < N; i++)
  {
    string tep;
    vector<int> temp;
    cin >> tep;

    for (int j = 0; j < tep.length(); j++)
    {
      temp.push_back(tep[j] - '0');
    }

    arr.push_back(temp);
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int idx = arr[i][j];
      int count = isSameApt(arr, i, j, N, idx);

      if (count != 0)
      {
        result.push_back(pair<int, int>(idx, count));
      }
    }
  }

  sort(result.begin(), result.end(), comp);

  cout << result.size() << endl;
  for (auto i : result)
  {
    cout << i.second << endl;
  }
}

bool comp(pair<int, int> a, pair<int, int> b)
{
  return a.second < b.second;
}

int isSameApt(vector<vector<int>> &arr, int x, int y, int N, int idx)
{
  if (x < 0 || x > N - 1 || y < 0 || y > N - 1)
    return 0;
  else if (arr[x][y] == 0)
    return 0;
  else if (arr[x][y] != idx)
    return 0;
  else
  {
    arr[x][y] = 0;
    return 1 + isSameApt(arr, x - 1, y, N, idx) + isSameApt(arr, x + 1, y, N, idx) + isSameApt(arr, x, y - 1, N, idx) + isSameApt(arr, x, y + 1, N, idx);
  }
}

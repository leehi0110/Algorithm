// ProblemNumber || ProblemName : P1092 - 배

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int answer = 1;

  vector<int> crane;
  vector<int> box;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    crane.push_back(temp);
  }

  cin >> m;

  for (int i = 0; i < m; i++)
  {
    int temp;
    cin >> temp;
    box.push_back(temp);
  }

  sort(crane.begin(), crane.end(), greater<int>());
  sort(box.begin(), box.end(), greater<int>());

  if (*crane.begin() < *box.begin())
  {
    cout << -1 << endl;
  }
  else
  {
    auto craneIt = crane.begin();
    auto boxIt = box.begin();

    while (!box.empty())
    {

      if (craneIt == crane.end() || boxIt == box.end())
      {
        answer++;
        craneIt = crane.begin();
        boxIt = box.begin();
      }
      else
      {
        if (*boxIt <= *craneIt)
        {
          box.erase(boxIt);
          craneIt++;
        }
        else
        {
          boxIt++;
        }
      }
    }

    cout << answer << endl;
  }
}
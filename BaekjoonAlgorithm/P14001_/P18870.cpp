// ProblemNumber || ProblemName : P11870 - 좌표압축

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  vector<int> vec;
  vector<int> dup;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int num;

    cin >> num;
    vec.push_back(num);
    dup.push_back(num);
  }

  sort(dup.begin(), dup.end());
  dup.erase(unique(dup.begin(), dup.end()), dup.end());

  for (int i = 0; i < vec.size(); i++)
  {
    int target = vec[i];
    int left = 0;
    int rigth = dup.size();
    int mid = (left + rigth) / 2;

    while (1)
    {
      if (dup[mid] > target)
      {
        rigth = mid;
        mid = (left + rigth) / 2;
      }
      else if (dup[mid] < target)
      {
        left = mid;
        mid = (left + rigth) / 2;
      }
      else
      {
        cout << mid << " ";
        break;
      }
    }
  }
  cout << endl;
}

// ProblemNumber || ProblemName : P2805 - 나무 자르기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  long n, m;
  long result;

  cin >> n >> m;
  vector<long> trees(n);

  for (int i = 0; i < n; i++)
  {
    long height;
    cin >> height;

    trees[i] = height;
  }

  long maxHeight = *max_element(trees.begin(), trees.end());
  long minHeight = 0;

  result = (maxHeight + minHeight) / 2;

  int k = 0;

  while (1)
  {
    long left = 0;
    int bigCnt = 0;

    for (int i = 0; i < trees.size(); i++)
    {
      if (trees[i] > result)
      {
        left += trees[i] - result;

        if (result + 1 <= trees[i])
          bigCnt++;
      }
    }

    if (left > m)
    {
      if (left - m < bigCnt)
        break;
      minHeight = result;
      result = (minHeight + maxHeight) / 2;
    }
    else if (left < m)
    {
      maxHeight = result;
      result = (maxHeight + minHeight) / 2;
    }
    else
    {
      break;
    }
  }

  cout << result << endl;
}
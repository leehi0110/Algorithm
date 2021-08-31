// ProblemNumber || ProblemName : P14719 - 빗물
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int w, h;
int result = 0;
vector<int> height;

int leftSide(int start, int end);
int rightSide(int start, int end);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w;

  for (int i = 0; i < w; i++)
  {
    int blockHeight;
    cin >> blockHeight;

    height.push_back(blockHeight);
  }

  int maxHeightIdx = max_element(height.begin(), height.end()) - height.begin();

  result = leftSide(0, maxHeightIdx) + rightSide(maxHeightIdx, height.size() - 1);

  cout << result << endl;
}

int leftSide(int start, int end)
{

  if (start == end || start + 1 == end)
    return 0;

  int nextMaxHeightIdx = max_element(height.begin() + start, height.begin() + end) - height.begin();

  if (nextMaxHeightIdx == start)
  {
    int result = 0;

    for (int i = start; i < end; i++)
    {
      result += height[start] - height[i];
    }

    return result;
  } // 빗물 구해서 리턴
  else
  {
    int result = 0;
    for (int i = nextMaxHeightIdx; i < end; i++)
    {
      result += height[nextMaxHeightIdx] - height[i];
    }

    return leftSide(start, nextMaxHeightIdx) + result;
  }
}

int rightSide(int start, int end)
{
  if (start == end || start + 1 == end)
    return 0;

  int nextMaxHeightIdx = max_element(height.begin() + start + 1, height.begin() + end + 1) - height.begin();

  if (nextMaxHeightIdx == end)
  {
    int result = 0;

    for (int i = start + 1; i < end; i++)
    {
      result += height[nextMaxHeightIdx] - height[i];
    }

    return result;
  }
  else
  {
    int result = 0;
    for (int i = start + 1; i < nextMaxHeightIdx; i++)
    {
      result += height[nextMaxHeightIdx] - height[i];
    }

    return result + rightSide(nextMaxHeightIdx, end);
  }
}

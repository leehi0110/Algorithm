// ProblemNumber || ProblemName : P2696 - 중앙값 구하기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    int num;
    vector<int> arr;
    priority_queue<int> front; // 큰 수
    priority_queue<int> back;  // 작은 수

    cin >> num;

    for (int j = 0; j < num; j++)
    {
      int temp;
      cin >> temp;

      arr.push_back(temp);
    }

    cout << num / 2 + num % 2 << "\n";
    cout << arr[0] << " ";
    front.push(arr[0]);

    for (int j = 1; j < num; j++)
    {
      if (j % 2 != 0)
      {
        int frontNum = front.top();
        front.pop();

        if (arr[j] < frontNum)
        {
          back.push(-frontNum);
          front.push(arr[j]);
        }
        else
        {
          back.push(-arr[j]);
          front.push(frontNum);
        }
      }
      else
      {
        int backNum = -back.top();
        back.pop();

        if (arr[j] > backNum)
        {
          back.push(-arr[j]);
          front.push(backNum);
        }
        else
        {
          back.push(-backNum);
          front.push(arr[j]);
        }

        cout << front.top();

        if (j == num - 1)
        {
          cout << "\n";
        }
        else
        {
          cout << " ";
        }
      }
    }
  }
}

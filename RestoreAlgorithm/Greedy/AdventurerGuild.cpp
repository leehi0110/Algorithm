// ProblemNumber || ProblemName : 모험가 길드

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  int cnt = 0;
  vector<int> arr;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());

  int guild = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    guild++;
    if (arr[i] <= guild)
    {
      cnt++;
      guild = 0;
    }
  }

  cout << cnt << endl;
}

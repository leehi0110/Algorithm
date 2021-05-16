// ProblemNumber || ProblemName : P11003 - 최솟값 찾기

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

  int n, l;
  vector<int> vec;
  priority_queue<int> pq;

  cin >> n >> l;

  for (int i = 0; i < n; i++)
  {
    int num;

    cin >> num;
    vec.push_back(num);
  }
}

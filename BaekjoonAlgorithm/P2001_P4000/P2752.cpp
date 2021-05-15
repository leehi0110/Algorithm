// ProblemNumber || ProblemName : P2752 - 세수정렬

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

  int a, b, c;
  priority_queue<int> pq;

  cin >> a >> b >> c;

  pq.push(-a);
  pq.push(-b);
  pq.push(-c);

  for (int i = 0; i < 3; i++)
  {
    cout << -pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}

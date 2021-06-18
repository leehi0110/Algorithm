// ProblemNumber || ProblemName : P1417 - 국회의원 선거
// 하면서 좀 더 깊게 생각하게 된 것들
// -> while()에서 우선순위큐를 사용할때는 반복문 조건을 우선순위큐가 비어있지 않았는지 체크해야된다.

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

  int n;
  int result = 0;
  int meVote;
  priority_queue<int> pq;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int vote;
    cin >> vote;

    if (i == 0)
    {
      meVote = vote;
    }
    else
      pq.push(vote);
  }

  while (!pq.empty())
  {
    int voteCnt = pq.top();
    pq.pop();

    if (voteCnt == meVote)
    {
      result += 1;
      break;
    }
    else if (voteCnt > meVote)
    {
      result += 1;
      meVote++;
      pq.push(voteCnt - 1);
    }
    else
      break;
  }

  cout << result << endl;
}

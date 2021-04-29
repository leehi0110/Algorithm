#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;

int solution(vector<int> stones, int k)
{
  priority_queue<int> pq;
  multiset<int> set;
  int maxEle;

  for (int i = 0; i < k; i++)
  {
    set.insert(stones[i]);
  }

  maxEle = *set.rbegin();
  pq.push(-1 * maxEle);

  for (int i = k; i < stones.size(); i++)
  {
    int deleteEle = stones[i - k];

    set.erase(deleteEle);

    while (set.size() != k - 1)
    {
      set.insert(deleteEle);
    }

    set.insert(stones[i]);

    maxEle = *set.rbegin();

    pq.push(-1 * maxEle);
  }
  return -1 * pq.top();
}

int main()
{
  int result = solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 7);
  // int result = solution({2, 4, 5, 3, 2, 4, 4, 2, 5, 3}, 6);
  // int result = solution({7}, 1);
  // int result = solution({7, 3}, 2);

  cout << result << endl;
}
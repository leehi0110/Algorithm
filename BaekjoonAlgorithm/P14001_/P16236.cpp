// ProblemNumber || ProblemName : P16236 - 아기 상어
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9

using namespace std;

int n;
int sharkX, sharkY;      // 상어의 위치
int result = 0;          // 엄마 상어에게 도움을 요청하기 전까지 물고기를 먹는 시간
int nowSize = 2;         // 현재 상어의 크기
int leftForNextSize = 2; // 성장하기 위해 더 먹어야 하는 물고기의 수
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// vector<vector<int>> map(21, vector<int>(21, INF));
vector<pair<int, pair<int, int>>> feeds;

int BFS();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int state;
      cin >> state;

      if (state == 9)
      {
        sharkX = i;
        sharkY = j;
      }
      else if (state != 0)
      {
        feeds.push_back({state, {i, j}});
      }
    }
  }

  while (!feeds.empty())
  {
    int needSec = BFS();

    if (needSec == -1)
      break;
    else
    {
      result += needSec;
    }
  }

  cout << result << endl;
}

int BFS()
{
  priority_queue<pair<int, pair<int, int>>> pq;
  vector<vector<int>> map(n, vector<int>(n, INF));
  int eatIdx, eatX, eatY, eatDist = INF;

  for (int i = 0; i < feeds.size(); i++)
  {
    int feedSize = feeds[i].first;
    int feedX = feeds[i].second.first;
    int feedY = feeds[i].second.second;

    if (feedSize > nowSize)
      map[feedX][feedY] = -1;
  }

  map[sharkX][sharkY] = 0;
  pq.push({0, {sharkX, sharkY}});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int nowX = pq.top().second.first;
    int nowY = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int moveX = nowX + dx[i];
      int moveY = nowY + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= n || map[moveX][moveY] <= cost + 1)
        continue;
      else
      {
        map[moveX][moveY] = cost + 1;
        pq.push({-map[moveX][moveY], {moveX, moveY}});
      }
    }
  }

  for (int i = 0; i < feeds.size(); i++)
  {
    int feedSize = feeds[i].first;
    int feedX = feeds[i].second.first;
    int feedY = feeds[i].second.second;

    if (feedSize < nowSize)
    {
      if (map[feedX][feedY] < eatDist)
      {
        eatIdx = i;
        eatX = feedX;
        eatY = feedY;
        eatDist = map[feedX][feedY];
      }
      else if (map[feedX][feedY] == eatDist)
      {
        if (feedX < eatX)
        {
          eatIdx = i;
          eatX = feedX;
          eatY = feedY;
        }
        else if (feedX == eatX && feedY < eatY)
        {
          eatIdx = i;
          eatY = feedY;
        }
      }
    }
  }

  if (eatDist == INF)
    return -1;
  else
  {
    feeds.erase(feeds.begin() + eatIdx);
    sharkX = eatX;
    sharkY = eatY;
    leftForNextSize--;

    if (leftForNextSize == 0)
    {
      nowSize++;
      leftForNextSize = nowSize;
    }
    return map[eatX][eatY];
  }
}

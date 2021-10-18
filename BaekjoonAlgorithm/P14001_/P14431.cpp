// ProblemNumber || ProblemName : P14431 - 소수 마을
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#define INF 1e9

using namespace std;

vector<pair<int,int>> target;
vector<vector<pair<int,int>>> graph(4001);
vector<bool> primes(4500, true);
int startX, startY;
int endX, endY;

void getPrimes();
void dijkstra();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  getPrimes();

  cin >> startX >> startY >> endX >> endY;

  target.push_back({startX, startY});

  int n;

  cin >> n;

  for(int i=0;i<n;i++) {
    int targetX, targetY;

    cin >> targetX >> targetY;

    for(int j=0;j<target.size();j++) {
      int dist = floor(sqrt(pow(target[j].first - targetX, 2) + pow(target[j].second - targetY,2)));
      if(primes[dist]) {
        graph[j].push_back({target.size(), dist});
        graph[target.size()].push_back({j, dist});
      }
    }

    target.push_back({targetX, targetY});
  }

  for(int i=0;i<target.size();i++) {
    int dist = floor(sqrt(pow(target[i].first - endX, 2) + pow(target[i].second - endY,2)));
    if(primes[dist]) {
      graph[i].push_back({target.size(),dist});
      graph[target.size()].push_back({i, dist});
    }
  }

  dijkstra();
}

void dijkstra()
{
  vector<int> minDist(4001, INF);
  priority_queue<pair<int,int>> pq;

  minDist[0] = 0;
  pq.push({0,0});

  while(!pq.empty()) {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if(minDist[now] < cost) continue;

    for(int i=0;i<graph[now].size();i++) {
      int next = graph[now][i].first;
      int nextCost = graph[now][i].second;

      if(minDist[next] > cost + nextCost) {
        minDist[next] = cost + nextCost;
        pq.push({-minDist[next], next});
      }
    }
  }

  if(minDist[target.size()] == INF) cout << -1 << endl;
  else cout << minDist[target.size()] << endl;
}

void getPrimes()
{
  primes[0] = false;
  primes[1] = false;

  for(int i=2;i<primes.size();i++) {
    if(primes[i]) {
      for(int j=i*2;j<primes.size();j += i) primes[j] = false;
    }
  }
}
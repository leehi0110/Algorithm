// ProblemNumber || ProblemName : 15953 - 상금헌터

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int checkPrice(vector<pair<int, int>> price, int rank);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;
  vector<pair<int, int>> first = {{1, 5000000}, {3, 3000000}, {6, 2000000}, {10, 500000}, {15, 300000}, {21, 100000}};
  vector<pair<int, int>> second = {{1, 5120000}, {3, 2560000}, {7, 1280000}, {15, 640000}, {31, 320000}};

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    int fRank, sRank;

    cin >> fRank >> sRank;

    cout << checkPrice(first, fRank) + checkPrice(second, sRank) << endl;
  }
}

int checkPrice(vector<pair<int, int>> price, int rank)
{
  int lastIndex = price.size() - 1;

  if (rank == 0 || price[lastIndex].first < rank)
    return 0;

  for (int i = 0; i < price.size(); i++)
  {
    if (price[i].first >= rank)
      return price[i].second;
  }
  return 0;
}

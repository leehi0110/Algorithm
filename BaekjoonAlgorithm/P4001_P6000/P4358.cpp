// ProblemNumber || ProblemName : P4358 - 생태학
// 하면서 좀 더 깊게 생각하게 된 것들
// -> getline(cin, str)을 이용해 EOF까지 입력을 받을 수 있다
// -> cout << fixed 를 이용해 cout.precision(소수점 자리수)를 구할 수 있다.
// -> map에 특정 키가 존재하는지 확인하기 위해 map.find(key)를 사용하면 된다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  map<string, int> map;
  int totalCnt = 0;

  while (getline(cin, s))
  {
    totalCnt++;

    if (map.find(s) != map.end())
    {
      map[s]++;
    }
    else
    {
      map.insert({s, 1});
    }
  }
  cout << fixed;
  cout.precision(4);
  for (auto it = map.begin(); it != map.end(); it++)
  {
    cout << it->first << " " << (it->second / static_cast<double>(totalCnt)) * 100 << endl;
  }
}

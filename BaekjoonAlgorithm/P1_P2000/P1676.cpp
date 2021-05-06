// ProblemNumber || ProblemName : P1676 - 팩토리얼 0의 개수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  cout << n / 5 + n / 25 + n / 125 << endl;
}

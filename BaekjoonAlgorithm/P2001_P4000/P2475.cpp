// ProblemNumber || ProblemName : P2475 - 검증수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int sum = 0;

  for (int i = 0; i < 5; i++)
  {
    int num;

    cin >> num;

    sum += pow(num, 2);
  }

  cout << sum % 10 << endl;
}

// ProblemNumber || ProblemName : P1081 - 합

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  long long result = 0;
  int a, b;

  vector<long long> table;

  cin >> a >> b;

  for (int i = 0; i < 10; i++)
  {
    table.push_back(i);
  }

  for (int i = 10; i <= b; i++)
  {
    string temp = to_string(i);
    string frontSub = temp.substr(0, 1);
    string backSub = temp.substr(1);

    table.push_back(static_cast<long long>(table[stoi(frontSub)]) + table[stoi(backSub)]);
  }

  for (int i = a; i <= b; i++)
  {
    result += static_cast<long long>(table[i]);
  }

  cout << result << "\n";
}

#include <string>
#include <vector>

using namespace std;

long long solution(int n)
{
  long long answer = 0;

  vector<long long> table(2000);
  table[0] = 0;
  table[1] = 1;
  table[2] = 2;

  for (int i = 3; i <= n; i++)
  {
    table[i] = (table[i - 2] + table[i - 1]) % 1234567;
  }
  return table[n];
}
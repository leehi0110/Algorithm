// ProblemNumber || ProblemName : P11441 - 합 구하기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n;

  vector<int> vec(n, 0);

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    if (i == 0)
      vec[i] = num;
    else
      vec[i] = vec[i - 1] + num;
  }

  cin >> m;

  for (int i = 0; i < m; i++)
  {
    int start, end;
    cin >> start >> end;

    if (start > 1)
      cout << vec[end - 1] - vec[start - 2] << "\n";
    else
      cout << vec[end - 1] << "\n";
  }
}

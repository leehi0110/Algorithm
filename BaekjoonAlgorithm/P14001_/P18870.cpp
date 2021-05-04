// ProblemNumber || ProblemName : P11870 - 좌표압축

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
  vector<long long> target;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    long long num;
    cin >> num;
    target.push_back(num);
  }
  vector<long long> dup = target;
  sort(dup.begin(), dup.end());

  dup.erase(unique(dup.begin(), dup.end()), dup.end());

  for (int i = 0; i < target.size(); i++)
  {
    int cnt = find(dup.begin(), dup.end(), target[i]) - dup.begin();
    cout << cnt << " ";
  }
  cout << "\n";
}

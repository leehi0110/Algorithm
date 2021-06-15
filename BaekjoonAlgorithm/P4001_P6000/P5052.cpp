// ProblemNumber || ProblemName : P5052 - 전화번호 목록
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    int telNum;
    vector<string> book;

    cin >> telNum;

    for (int j = 0; j < telNum; j++)
    {
      string telNumber;

      cin >> telNumber;

      book.push_back(telNumber);
    }

    sort(book.begin(), book.end());

    for (int j = 1; j < book.size(); j++)
    {
      if (book[j - 1] == book[j].substr(0, book[j - 1].length()))
      {
        cout << "NO" << endl;
        break;
      }

      if (j == book.size() - 1)
      {
        cout << "YES" << endl;
      }
    }
  }
}

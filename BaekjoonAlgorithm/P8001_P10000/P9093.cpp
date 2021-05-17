// ProblemNumber || ProblemName : P9093 - 단어 뒤집기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  stack<char> st;

  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++)
  {
    string temp;
    getline(cin, temp);

    for (int j = 0; j < temp.length(); j++)
    {
      if (temp[j] == ' ')
      {
        while (!st.empty())
        {
          cout << st.top();
          st.pop();
        }
        cout << " ";
      }
      else
      {
        st.push(temp[j]);
      }

      if (j == temp.length() - 1)
      {
        while (!st.empty())
        {
          cout << st.top();
          st.pop();
        }
        cout << endl;
      }
    }
  }
}

// ProblemNumber || ProblemName : P2800 - 괄호 제거
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <set>

using namespace std;

set<string> strset;

void insertBracket(stack<pair<int, int>> bracketStack, string str);
string replaceString(string str);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  string basicStr = "";
  stack<int> bracketStack;
  stack<pair<int, int>> recureStack;

  cin >> str;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '(' || str[i] == ')')
      basicStr += '_';
    else
      basicStr += str[i];
  }

  for (int i = 0; i < str.length(); i++)
  {

    if (str[i] == '(')
      bracketStack.push(i);
    else if (str[i] == ')')
    {
      int openIdx = bracketStack.top();
      bracketStack.pop();

      recureStack.push({openIdx, i});
    }
  }

  while (!recureStack.empty())
  {
    insertBracket(recureStack, basicStr);

    recureStack.pop();
  }

  for (auto it = ++strset.begin(); it != strset.end(); it++)
  {
    cout << *it << endl;
  }
}

void insertBracket(stack<pair<int, int>> bracketStack, string str)
{
  if (bracketStack.empty())
    return;

  strset.insert(replaceString(str));

  int openIdx = bracketStack.top().first;
  int closeIdx = bracketStack.top().second;

  bracketStack.pop();

  insertBracket(bracketStack, str);

  str[openIdx] = '(';
  str[closeIdx] = ')';

  strset.insert(replaceString(str));

  insertBracket(bracketStack, str);
}

string replaceString(string str)
{
  string replaceStr = "";

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] != '_')
      replaceStr += str[i];
  }

  return replaceStr;
}

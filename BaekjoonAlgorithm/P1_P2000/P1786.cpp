// ProblemNumber || ProblemName : P1786 - 찾기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> result;

vector<int> makeTable(string &pattern);
void kmp(string parent, string pattern);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  string parent, pattern;

  getline(cin, parent);
  getline(cin, pattern);

  kmp(parent, pattern);

  cout << result.size() << endl;

  for(int i=0;i<result.size();i++) {
    cout << result[i] << " ";
  }
  cout << endl;
}

void kmp(string parent, string pattern)
{
  vector<int> table = makeTable(pattern);
  int parentLen = parent.length();
  int patternLen = pattern.length();

  for(int i=0;i<table.size();i++) {
    cout << table[i] << " ";
  }
  cout << endl;

  int j = 0;
  for(int i=0;i<parent.length();i++) {

    while(j > 0 && pattern[j] != parent[i]) {
      j = table[j-1];
    }

    if(parent[i] == pattern[j]) {
      if(j == patternLen - 1) {
        result.push_back(i-patternLen+2);
        i = (i-patternLen + 2);
        j = table[j-1];
      }

      // ababababababababa
      // ababa

      // 0 0 1 2 1

      // abacababacabab
      // abacabab

      // 0 0 1 0 1 2 3 2

      // result = 8
      // i = 7
      // j = 7
      else {
        j++;
      }
    }
  }
}

vector<int> makeTable(string &pattern)
{
  int patternLen = pattern.length();
  vector<int> table(patternLen, 0);

  int j = 0;
  for(int i=1;i<patternLen;i++) {
    while(j > 0 && pattern[i] != pattern[j]) {
      j = table[j-1];
    }

    if(pattern[i] == pattern[j]) {
      table[i] = ++j;
    }
  }

  return table;
}
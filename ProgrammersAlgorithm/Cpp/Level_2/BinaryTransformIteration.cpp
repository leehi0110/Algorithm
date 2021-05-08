#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s)
{
  vector<int> answer(2, 0);

  while (s != "1")
  {

    for (auto it = s.begin(); it != s.end();)
    {
      if (*it == '0')
      {
        answer[1]++;
        s.erase(it);
      }
      else
      {
        it++;
      }
    }

    int len = s.length();
    string temp = "";

    while (len != 0)
    {
      if (len % 2 == 0)
      {
        temp.insert(0, "0");
      }
      else
      {
        temp.insert(0, "1");
      }

      len /= 2;
    }

    s = temp;

    answer[0]++;
  }

  return answer;
}

int main()
{
  // vector<int> result = solution("110010101001");
  // vector<int> result = solution("01110");
  vector<int> result = solution("1111111");

  for (auto a : result)
  {
    cout << a << " ";
  }
  cout << endl;
}
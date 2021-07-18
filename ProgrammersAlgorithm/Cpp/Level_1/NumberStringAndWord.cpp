#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

int solution(string s)
{
  int answer = 0;
  string temp = "";
  vector<string> number = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  for (int i = 0; i < s.length(); i++)
  {

    if (s[i] >= '0' && s[i] <= '9')
    {
      answer = answer * 10 + (s[i] - '0');
    }
    else
    {
      temp += s[i];
      auto it = find(number.begin(), number.end(), temp);
      if (it != number.end())
      {
        answer = answer * 10 + (it - number.begin());
        temp = "";
      }
    }

    if (i == s.length() - 1 && temp != "")
    {
      answer = answer * 10 + find(number.begin(), number.end(), temp) - number.begin();
    }
  }
  return answer;
}

int main()
{
  // int result = solution("one4seveneight");
  int result = solution("23four5six7");

  cout << result << endl;
}
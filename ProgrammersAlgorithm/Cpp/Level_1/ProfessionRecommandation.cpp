#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
  map<string, vector<string>> scoreMap;

  string answer = "";
  int maxScore = 0;

  for (int i = 0; i < table.size(); i++)
  {
    string target = table[i];
    string tempStr = "";
    string title = "";
    vector<string> sub;

    for (int j = 0; j < target.length(); j++)
    {
      if (target[j] == ' ')
      {
        if (title == "")
        {
          title = tempStr;
        }
        else
        {
          sub.insert(sub.begin(), tempStr);
        }
        tempStr = "";
      }
      else
      {
        tempStr += target[j];
      }

      if (j == target.length() - 1)
      {
        sub.insert(sub.begin(), tempStr);
      }
    }

    scoreMap.insert({title, sub});
  }
  for (auto it = scoreMap.begin(); it != scoreMap.end(); it++)
  {
    int sumScore = 0;

    for (int i = 0; i < languages.size(); i++)
    {
      auto scoreIt = find(it->second.begin(), it->second.end(), languages[i]);

      if (scoreIt != it->second.end())
      {
        sumScore += ((find(it->second.begin(), it->second.end(), languages[i]) - it->second.begin() + 1) * preference[i]);
      }
    }

    if (maxScore < sumScore)
    {
      answer = it->first;
      maxScore = sumScore;
    }
  }

  return answer;
}

int main()
{
  // string result = solution({"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"}, {"PYTHON", "C++", "SQL"}, {7, 5, 5});
  string result = solution({"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"}, {"JAVA", "JAVASCRIPT"}, {7, 5});

  cout << result << endl;
}
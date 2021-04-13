#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string dirs)
{
  int answer = 0;
  vector<string> pass;
  int x = 0, y = 0;

  for (int i = 0; i < dirs.length(); i++)
  {
    string goPass;
    string backPass;
    if (dirs[i] == 'U')
    {
      if (y + 1 > 5)
        continue;

      goPass = to_string(x) + to_string(y) + to_string(x) + to_string(y + 1);
      backPass = to_string(x) + to_string(y + 1) + to_string(x) + to_string(y);
      if (find(pass.begin(), pass.end(), goPass) == pass.end())
      {
        pass.push_back(goPass);
        pass.push_back(backPass);
      }
      y++;
    }
    else if (dirs[i] == 'D')
    {

      if (y - 1 < -5)
        continue;
      goPass = to_string(x) + to_string(y) + to_string(x) + to_string(y - 1);
      backPass = to_string(x) + to_string(y - 1) + to_string(x) + to_string(y);
      if (find(pass.begin(), pass.end(), goPass) == pass.end())
      {
        pass.push_back(goPass);
        pass.push_back(backPass);
      }
      y--;
    }
    else if (dirs[i] == 'R')
    {
      if (x + 1 > 5)
        continue;
      goPass = to_string(x) + to_string(y) + to_string(x + 1) + to_string(y);
      backPass = to_string(x + 1) + to_string(y) + to_string(x) + to_string(y);
      if (find(pass.begin(), pass.end(), goPass) == pass.end())
      {
        pass.push_back(goPass);
        pass.push_back(backPass);
      }
      x++;
    }
    else
    {
      if (x - 1 < -5)
        continue;
      goPass = to_string(x) + to_string(y) + to_string(x - 1) + to_string(y);
      backPass = to_string(x - 1) + to_string(y) + to_string(x) + to_string(y);
      if (find(pass.begin(), pass.end(), goPass) == pass.end())
      {
        pass.push_back(goPass);
        pass.push_back(backPass);
      }
      x--;
    }
  }

  return pass.size() / 2;
}
// ProblemNumber || ProblemName : P2174 - 로봇 시뮬레이션
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int a, b;
int n, m;
vector<pair<char, pair<int, int>>> command;
vector<pair<char, pair<int, int>>> robot;
int map[101][101];
string result = "OK";

void playCmd(int robotNum, char cmd);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> b >> a;
  cin >> n >> m;

  for (int i = 0; i < 101; i++)
  {
    for (int j = 0; j < 101; j++)
    {
      map[i][j] = -1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    int x, y;
    char direction;

    cin >> x >> y;
    cin >> direction;

    map[y][x] = i;

    robot.push_back({direction, {y, x}});
  }

  for (int i = 0; i < m; i++)
  {
    int robotNum, cmdNum;
    char cmd;

    cin >> robotNum;
    cin >> cmd;
    cin >> cmdNum;

    command.push_back({cmd, {robotNum, cmdNum}});
  }

  for (int i = 0; i < command.size(); i++)
  {
    char cmd = command[i].first;
    int robotNum = command[i].second.first;
    int cmdNum = command[i].second.second;

    for (int j = 0; j < cmdNum; j++)
    {
      playCmd(robotNum - 1, cmd);
      if (result != "OK")
        break;
    }
    if (result != "OK")
      break;
  }
  cout << result << endl;
}

void playCmd(int robotNum, char cmd)
{
  char direction = robot[robotNum].first;
  int robotX = robot[robotNum].second.first;
  int robotY = robot[robotNum].second.second;

  if (cmd == 'L')
  {

    if (direction == 'N')
      robot[robotNum].first = 'W';
    else if (direction == 'W')
      robot[robotNum].first = 'S';
    else if (direction == 'S')
      robot[robotNum].first = 'E';
    else
      robot[robotNum].first = 'N';
  }
  else if (cmd == 'R')
  {

    if (direction == 'N')
      robot[robotNum].first = 'E';
    else if (direction == 'E')
      robot[robotNum].first = 'S';
    else if (direction == 'S')
      robot[robotNum].first = 'W';
    else
      robot[robotNum].first = 'N';
  }
  else
  {
    if (direction == 'N')
    {
      if (robotX + 1 > a)
      {
        result = "Robot " + to_string(robotNum + 1) + " crashes into the wall";
        return;
      }
      else if (map[robotX + 1][robotY] != -1)
      {
        result = "Robot " + to_string(robotNum + 1) + " crashes into robot " + to_string(map[robotX + 1][robotY] + 1);
        return;
      }
      else
      {
        robot[robotNum].second.first = robotX + 1;
        map[robotX][robotY] = -1;
        map[robotX + 1][robotY] = robotNum;
      }
    }
    else if (direction == 'W')
    {
      if (robotY - 1 < 1)
      {
        result = "Robot " + to_string(robotNum + 1) + " crashes into the wall";
        return;
      }
      else if (map[robotX][robotY - 1] != -1)
      {
        result = "Robot " + to_string(robotNum + 1) + " crashes into robot " + to_string(map[robotX][robotY - 1] + 1);
        return;
      }
      else
      {
        robot[robotNum].second.second = robotY - 1;
        map[robotX][robotY] = -1;
        map[robotX][robotY - 1] = robotNum;
      }
    }
    else if (direction == 'S')
    {
      if (robotX - 1 < 1)
      {
        result = "Robot " + to_string(robotNum + 1) + " crashes into the wall";
        return;
      }
      else if (map[robotX - 1][robotY] != -1)
      {
        result = "Robot " + to_string(robotNum + 1) + " crashes into robot " + to_string(map[robotX - 1][robotY] + 1);
        return;
      }
      else
      {
        robot[robotNum].second.first = robotX - 1;
        map[robotX][robotY] = -1;
        map[robotX - 1][robotY] = robotNum;
      }
    }
    else
    { // direction == 'E'
      if (robotY + 1 > b)
      {
        result = "Robot " + to_string(robotNum + 1) + " crashes into the wall";
        return;
      }
      else if (map[robotX][robotY + 1] != -1)
      {
        result = "Robot " + to_string(robotNum + 1) + " crashes into robot " + to_string(map[robotX][robotY + 1] + 1);
        return;
      }
      else
      {
        robot[robotNum].second.second = robotY + 1;
        map[robotX][robotY] = -1;
        map[robotX][robotY + 1] = robotNum;
      }
    }
  }
}

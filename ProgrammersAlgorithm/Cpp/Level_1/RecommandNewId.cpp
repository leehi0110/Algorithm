#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void first(string &id);
void second(string &id);
void third(string &id);
void fourth(string &id);
void fifth(string &id);
void other(string &id);

string solution(string new_id)
{
  string answer = "";

  first(new_id);
  second(new_id);
  third(new_id);
  fourth(new_id);
  other(new_id);

  return new_id;
}

void first(string &id)
{
  transform(id.begin(), id.end(), id.begin(), ::tolower);
}

void second(string &id)
{

  for (auto it = id.begin(); it != id.end(); it++)
  {
    if (*it >= 'a' && *it <= 'z')
      continue;
    else if (isdigit(*it) != 0)
      continue;
    else if (*it == '-' || *it == '_' || *it == '.')
      continue;
    else
    {
      id.erase(it);
      it--;
    }
  }
}

void third(string &id)
{
  for (auto it = ++id.begin(), before = id.begin(); it != id.end();)
  {
    if (*it == '.' && *before == '.')
    {
      id.erase(it);
    }
    else
    {
      it++;
      before++;
    }
  }
}

void fourth(string &id)
{

  while (id.length() != 0)
  {
    if (id[0] == '.')
    {
      id.erase(id.begin());
    }

    if (id[id.length() - 1] == '.')
    {
      id.erase(id.end() - 1);
    }

    if (id[0] != '.' && id[id.length() - 1] != '.')
      break;
  }
}

void other(string &id)
{
  if (id == "")
    id = "a";

  if (id.length() >= 16)
  {
    id.erase(id.begin() + 15, id.end());
    fourth(id);
  }
  else if (id.length() <= 2)
  {
    while (id.length() != 3)
    {
      id += id[id.length() - 1];
    }
  }
}
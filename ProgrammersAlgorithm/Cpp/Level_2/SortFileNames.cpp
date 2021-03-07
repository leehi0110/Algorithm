#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

bool comp(vector<string> a, vector<string> b)
{
    transform(a[1].begin(), a[1].end(), a[1].begin(), ::toupper);
    transform(b[1].begin(), b[1].end(), b[1].begin(), ::toupper);

    if (a[1] == b[1])
    {
        if (stoi(a[2]) == stoi(b[2]))
        {
            return stoi(a[0]) < stoi(b[0]);
        }
        else
        {
            return stoi(a[2]) < stoi(b[2]);
        }
    }
    else
    {
        return a[1] < b[1];
    }
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    vector<vector<string>> vec;

    for (int i = 0; i < files.size(); i++)
    {
        vector<string> temp;
        string file = files[i];
        string sub = "";
        int flag = 0;

        temp.push_back(to_string(i)); // 몇 번째 파일인지 저장

        for (int j = 0; j < file.length(); j++)
        {

            if (flag == 1 && !isdigit(file[j]))
            {
                temp.push_back(sub);
                break;
            }
            else if (isdigit(file[j]) && flag == 0)
            {
                temp.push_back(sub);
                sub = file[j];
                flag = 1;
            }
            else
            {
                sub += file[j];
            }

            if (j == file.length() - 1)
                temp.push_back(sub);
        }

        vec.push_back(temp);
    }

    stable_sort(vec.begin(), vec.end(), comp);

    for (int i = 0; i < vec.size(); i++)
    {
        int idx = stoi(vec[i][0]);

        answer.push_back(files[idx]);
    }

    return answer;
}
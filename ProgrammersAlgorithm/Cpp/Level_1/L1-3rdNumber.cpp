#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int i=0;i<commands.size();i++){
        int start, end, target;
        vector <int> subVector;

        start = commands[i][0] - 1;
        end = commands[i][1];
        target = commands[i][2] - 1;

        for(int j=start;j<end;j++){
            subVector.push_back(array[j]);
        }

        sort(subVector.begin(),subVector.end());
        answer.push_back(subVector[target]);
    }

    return answer;
}

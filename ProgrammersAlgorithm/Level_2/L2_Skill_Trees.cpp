#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(int i=0;i<skill_trees.size();i++){
        vector <int> order;
        vector <int> sort_order;

        for(int j=0;j<skill.length();j++){
            int index = find(skill_trees[i].begin(),skill_trees[i].end(),skill[j]) - skill_trees[i].begin();
            order.push_back(index);
        }

        sort_order = order;
        sort(sort_order.begin(),sort_order.end());

        if(sort_order == order) answer ++;
    }

    return answer;
}
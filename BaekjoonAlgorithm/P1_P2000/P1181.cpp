// Baekjoon 1181
// 문제
// 단어 정렬

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    map <int,vector<string>> input_map;
    map <int,vector<string>>::iterator iter;

    cin >> n;

    while(n--){
        string input;

        cin >> input;

        if(input_map.find(input.length()) == input_map.end()){
            input_map.insert(pair<int,vector<string>>(input.length(),{input}));
        }
        else {
            if(find(input_map[input.length()].begin(),input_map[input.length()].end(),input) == input_map[input.length()].end()){
                input_map[input.length()].push_back(input);
            }
        }
    }

    for(iter = input_map.begin();iter != input_map.end();iter++){
        sort(iter->second.begin(),iter->second.end());

        for(int i=0;i<iter->second.size();i++){
            cout << iter->second[i] << "\n";
        }
    }
}
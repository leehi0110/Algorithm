#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector <string> cache;

    if(cacheSize == 0) return cities.size()*5;

    for(int i=0;i<cities.size();i++){

        transform(cities[i].begin(),cities[i].end(),cities[i].begin(),::toupper);

        if(find(cache.begin(),cache.end(),cities[i]) != cache.end()){
            answer += 1;
            int index = find(cache.begin(),cache.end(),cities[i]) - cache.begin();
            cache.erase(cache.begin()+index);
            cache.push_back(cities[i]);
        }
        else {
            answer += 5;
            if(cache.size() == cacheSize){
                cache.erase(cache.begin());   
            }
            cache.push_back(cities[i]);
        }
    }

    cout << answer << endl;

    return answer;
}
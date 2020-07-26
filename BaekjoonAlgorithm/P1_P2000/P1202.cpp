// Baekjoon 1202
// 문제
// 그리디
// 보석 도둑

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int gem_cnt, bag_cnt;
    int total_price = 0;
    vector <pair<int,int>> gem_info;
    multiset <int> bag_info;

    cin >> gem_cnt >> bag_cnt;

    for(int i=0;i<gem_cnt;i++){
        int gem_weight, gem_price;

        cin >> gem_weight >> gem_price;

        gem_info.push_back(pair<int,int>(gem_price,gem_weight));
    }

    for(int i=0;i<bag_cnt;i++){
        int bag_weight;

        cin >> bag_weight;
        bag_info.insert(bag_weight);
    }

}
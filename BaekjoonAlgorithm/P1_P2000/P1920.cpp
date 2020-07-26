// Baekjoon 1920
// 문제
// 수 찾기

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    multiset <int> set;

    cin >> n;

    while(n--){
        int temp;
        cin >> temp;
        set.insert(temp);
    }

    int search_num;

    cin >> search_num;

    while(search_num--){
        int temp;

        cin >> temp;
        if(set.find(temp) != set.end()) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
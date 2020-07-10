// Baekjoon 2751
// 문제
// 수 정렬하기2

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    set <int> sort_stl;

    cin >> n;

    while(n--){
        int val;

        cin >> val;
        sort_stl.insert(val);
    }

    set <int>::iterator iter;

    for(iter = sort_stl.begin();iter != sort_stl.end();iter++){
        cout << *iter << "\n";
    }

}
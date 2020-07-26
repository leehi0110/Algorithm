// Baekjoon 1427
// 문제
// 소트인사이드

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned long long n;
    unsigned long long result = 0;
    multiset <int,greater<int>> sort_set;
    
    cin >> n;

    while(n > 9){
        sort_set.insert(n%10);
        n /= 10;
    }
    sort_set.insert(n);

    multiset <int>::iterator iter;

    for(iter = sort_set.begin();iter != sort_set.end();iter++){
        result *= 10;
        result += *iter;
    }

    cout << result << endl;
    
}
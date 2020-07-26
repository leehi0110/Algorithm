// Baekjoon 1049
// 문제
// 기타줄

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    int min_price = 0;
    int single_profit = 0;
    multiset <int> package;
    multiset <int> single;
    multiset <int>::iterator package_iter;
    multiset <int>::iterator single_iter;

    cin >> n >> m;

    for(int i=0;i<m;i++){
        int package_price, single_price;

        cin >> package_price >> single_price;
        package.insert(package_price);
        single.insert(single_price);
    }

    package_iter = package.begin();
    single_iter = single.begin();

    for(int i=1;i<7;i++){
        if(*single_iter * i <= *package_iter) single_profit = i;
        else break;
    }

    if(*single_iter * 6 < *package_iter) {
        cout << n * (*single_iter) << endl;
    }
    else {
        min_price += (n/6)*(*package_iter);
        n %= 6;

        if(n > single_profit) min_price += *package_iter;
        else {
            min_price += n*(*single_iter);
        }

        cout << min_price << endl;
    }
}
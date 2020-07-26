// Baekjoon 2875
// 문제
// 대회 or 인턴

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n,m,k;
    int max_team = 0;

    cin >> n >> m >> k;

    for(int i=k;i>=0;i--){
        int women = n-i;
        int men = m - (k-i);

        if(women/2 > men) {
            if(max_team < men) max_team = men;
        }
        else {
            if(max_team < women) max_team = women/2;
        }
    }

    cout << max_team;
}
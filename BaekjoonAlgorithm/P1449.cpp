// Baekjoon 1449
// 문제
// 그리디
// 수리공 항승

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int leak_cnt, tape_length;
    double tape_cover;
    int tape_cnt = 0;

    cin >> leak_cnt >> tape_length;

    vector <int> leak_site(leak_cnt);
    vector <int>::iterator leak_iter;

    for(int i=0;i<leak_cnt;i++){
        cin >> leak_site[i];
    }

    sort(leak_site.begin(),leak_site.end());

    for(int i=0;i<leak_cnt;i++){
        tape_cover = leak_site[i] - 0.5 + tape_length;

        leak_iter = upper_bound(leak_site.begin(),leak_site.end(),tape_cover);
        tape_cnt ++;

        if(leak_iter == leak_site.end()) {
            break;
        }
        else {
            i = leak_iter - leak_site.begin() - 1;
        }
    }

    cout << tape_cnt << endl;
}

//5 3
// 1 2 3 4 100 2000
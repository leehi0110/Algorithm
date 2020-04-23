// Baekjoon 4948
// 문제
// 베르트랑 공준

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    int cnt;
    vector <bool> array;

    cin >> test_case;

    while(test_case != 0){
        array.resize(test_case*2 + 1,true);
        array[0] = false;
        array[1] = false;
        cnt = 0;

        for(int i=2;i<test_case*2+1;i++){
            if(array[i]){
                if(i > test_case) cnt++;
                for(int j=i*2;j<test_case*2+1;j += i){
                    array[j] = false;
                }
            }
        }

        cout << cnt << endl;
        cin >> test_case;
    }
}
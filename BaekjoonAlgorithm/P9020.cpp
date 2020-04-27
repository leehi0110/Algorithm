// Baekjoon 9020
// 문제
// 골드바흐의 추측

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //ios_base :: sync_with_stdio(false);
    //cin.tie(NULL);

    int test_case;
    int n;
    int small_n;
    int large_n;
    vector <bool> array(10001,true);

    array[0] = false;
    array[1] = false;

    for(int i=2;i<10001;i++){
        if(array[i]){
            for(int j=i*2;j<10001;j += i){
                array[j] = false;
            }
        }
    }

    cin >> test_case;

    for(int i=0;i<test_case;i++){

        cin >> n;

        small_n = n/2;

        for(int j=small_n;j>1;j--){
            if(array[j] == true && array[n-j] == true){
                cout << j << " " << n-j << endl;
                break;
            }
        }
    }

}
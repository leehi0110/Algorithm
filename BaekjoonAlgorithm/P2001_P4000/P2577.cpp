// Baekjoon 2577
// 문제
// 숫자의 개수

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);

    int A, B, C;
    int result;
    vector <int> array(10,0);

    cin >> A >> B >> C;

    result = A*B*C;

    while(1){
        if(result < 10){
            array[result] ++;
            break;
        }
        else {
            array[result%10] ++;
            result /= 10;
        }
    }

    for(int i=0;i<10;i++){
        cout << array[i] << endl;
    }
}
// ProblemNumber || ProblemName : 직사각형 별찍기
// 문제
// 가로와 세로를 입력받아 가로 세로 크기의 별직사각형을 출력

#include <iostream>

using namespace std;

int main(void) {
    
    int a , b;
    
    cin >> a >> b;
    
    for(int i=0;i<b;i++) {
        for(int j=0;j<a;j++) {
            cout << '*';
        }
        cout << endl;
    }
    
    return 0;
}

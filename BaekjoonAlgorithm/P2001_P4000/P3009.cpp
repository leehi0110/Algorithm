// Baekjoon 3009
// 문제
// 네 번째 점

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int x1 , x2, x3;
    int y1 , y2, y3;
    int target_x , target_y;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    if(x1 == x2){
        target_x = x3;
    }
    else {
        if(x1 == x3) target_x = x2;
        else target_x = x1;
    }

    if(y1 == y2){
        target_y = y3;
    }
    else {
        if(y1 == y3) target_y = y2;
        else target_y = y1;
    }

    cout << target_x << " " << target_y << endl;
}
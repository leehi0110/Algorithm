#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int turn = 1;

    if(b < a) swap(a,b);

    while(1){

        if((a%2 == 1) && (b%2 == 0) && (a+1 == b)) return turn;
        else {
            if(a%2 == 0) a /= 2;
            else a = (a+1)/2;

            if(b%2 == 0) b /= 2;
            else b = (b+1)/2;

            turn ++;
        }
    }
}
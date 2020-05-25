// Baekjoon 1011
// 문제
// Fly me to the Alpha Centauri

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int cal(int number);

int main()
{
    int testCase;

    cin >> testCase;

    for(int i=0;i<testCase;i++){

        int x, y;
        int left_distance;
        int count = 0;
        int nowStep = 0;

        cin >> x >> y;
        left_distance = y-x;

        while(left_distance != 0){

            if(left_distance > cal(nowStep+1)){
                nowStep ++;
                left_distance -= nowStep;
                count ++;
            }
            else if(left_distance == cal(nowStep+1)){
                count += nowStep+1;
                break;
            }
            else if(left_distance > cal(nowStep)){
                left_distance -= nowStep;
                count ++;
            }
            else if(left_distance == cal(nowStep)){
                count += nowStep;
                break;
            }
            else {
                nowStep --;
                left_distance -= nowStep;
                count ++;
            }
        }

        cout << count << endl;
    }

}

int cal(int number)
{
    int sum = 0;
    for(int i=number;i>0;i--){
        sum += i;
    }
    return sum;
}

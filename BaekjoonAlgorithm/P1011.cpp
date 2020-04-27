// Baekjoon 1011
// 문제
// Fly me to the Alpha Centauri

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int cal(int step);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    long int x,y;
    long int left_distance;
    long int step;
    int cnt;

    cin >> test_case;

    for(int i=0;i<test_case;i++){
        cin >> x >> y;
        left_distance = y-x;
        cnt = 0;
        step = 0;

        while(left_distance == 0){
            if(cal(step+1) < left_distance){
                step ++;
                left_distance -= step;
                cnt ++;
            }
            else if(cal(step+1) == left_distance){
                cnt += step+1;
                break;
            }
            else {
                if(cal(step) < left_distance){
                    left_distance -= step;
                    cnt++;
                }
                else if(cal(step) == left_distance){
                    cnt += step;
                    break;
                }
                else {
                    step--;
                    left_distance -= step;
                    cnt ++;
                }
            }
        }
        
        cout << cnt << endl;
    }

}

int cal(int step)
{
    int sum=0;

    for(int i=step;i>0;i--){
        sum += i;
    }

    return sum;
}
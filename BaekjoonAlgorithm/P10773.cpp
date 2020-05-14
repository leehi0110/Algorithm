// Baekjoon 10773
// 문제
// 제로

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    int num;
    int sum = 0;

    vector <int> stack;

    cin >> k;

    for(int i=0;i<k;i++){
        cin >> num;

        if(num == 0){
            sum -= stack.back();
            stack.pop_back();
        }
        else {
            sum += num;
            stack.push_back(num);
        }
    }

    cout << sum << endl;
}       
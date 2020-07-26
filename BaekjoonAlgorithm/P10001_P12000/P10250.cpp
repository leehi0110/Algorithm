// Baekjoon 10250
// 문제
// ACM 호텔

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int floor, room, customer;
    int n;
    int floor_number, room_number;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> floor >> room >> customer;

        if(customer%floor == 0){
            floor_number = floor;
            room_number = customer/floor;
        }
        else {
            floor_number = customer%floor;
            room_number = customer/floor + 1;
        }

        cout << floor_number*100 + room_number << endl;
    }
}
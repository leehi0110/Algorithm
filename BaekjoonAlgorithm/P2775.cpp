// Baekjoon 2775
// 문제
// 부녀회장이 될테야

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int check_people(int floor, int room);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int case_num;
    int floor;
    int room;

    cin >> case_num;

    for(int i=0;i<case_num;i++){
        cin >> floor;
        cin >> room;

        cout << check_people(floor,room) << endl;
    }
}

int check_people(int floor, int room)
{
    if(floor == 0){
        return room;
    }
    else if(room == 1){
        return 1;
    }
    else {
        return check_people(floor-1,room) + check_people(floor,room-1);
    }
}
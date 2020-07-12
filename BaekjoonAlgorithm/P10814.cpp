// Baekjoon 10814
// 문제
// 나이순 정렬

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    multimap <int,string> user;

    int n;

    cin >> n;

    while(n--){
        int age;
        string name;

        cin >> age >> name;

        user.insert(pair<int,string>(age,name));
    }    
    multimap <int,string>::iterator iter;

    for(iter = user.begin();iter != user.end() ; iter++){
        cout << iter->first << " " << iter->second << "\n";
    }

}
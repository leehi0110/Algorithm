// Baekjoon 1764
// 문제
// 문자열 처리
// 듣보잡

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n , m;
    int min;

    cin >> n >> m;

    vector <string> hear(n);
    vector <string> see(m);
    vector <string> result;

    for(int i=0;i<n;i++){
        cin >> hear[i];
    }

    for(int i=0;i<m;i++){
        cin >> see[i];
    }

    sort(hear.begin(),hear.end());
    sort(see.begin(),see.end());

    vector <string>::iterator hear_iter = hear.begin();
    vector <string>::iterator see_iter = see.begin();

    while(hear_iter != hear.end() && see_iter != see.end()){
        if(*hear_iter == *see_iter){
            result.push_back(*hear_iter);
            hear_iter++;
            see_iter++;
        } 
        else if(*hear_iter > *see_iter) see_iter++;
        else hear_iter++;
    }

    cout << result.size() << endl;
    for(string s : result){
        cout << s << "\n";
    }
}
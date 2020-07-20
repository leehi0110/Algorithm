// Baekjoon 15652
// 문제
// 백트래킹
// N과 M(4)

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void backtracking_function(vector<int> &vec,int max_cnt,int now_number,int max_number);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;


    for(int i=1;i<=n;i++){
        vector <int> vec;
        vec.push_back(i);
        backtracking_function(vec,m,i,n);
        vec.clear();
    }
}

void backtracking_function(vector<int> &vec,int max_cnt,int now_number,int max_number)
{
    if(vec.size() == max_cnt){
        for(int i : vec){
            cout << i << " ";
        }
        cout << "\n";
    }
    else {
        for(int i=now_number;i<=max_number;i++){
            vec.push_back(i);
            backtracking_function(vec,max_cnt,i,max_number);
            vec.pop_back();
        }
    }
}
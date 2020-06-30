// Baekjoon 1946
// 문제
// 신입 사원

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_case;

    cin >> test_case;

    for(int i=0;i<test_case;i++){
        int candidate_num;
        int pass_candidate_num = 0;
        map <int,int> candidate_rank;

        cin >> candidate_num;

        for(int j=0;j<candidate_num;j++){
            int document, interview;
            cin >> document >> interview;

            candidate_rank.insert(pair<int,int>(document,interview));
        }
        map <int,int>::iterator target_iter;
        map <int,int>::iterator compare_iter;

        target_iter = candidate_rank.begin();
        int hire_score = target_iter->second;
        pass_candidate_num++;
        target_iter++;

        for(target_iter;target_iter != candidate_rank.end();target_iter ++){
            if(target_iter->second < hire_score) {
                pass_candidate_num++;
                hire_score = target_iter->second;
            }
        }

        // for(target_iter = candidate_rank.begin();target_iter != candidate_rank.end();target_iter++){
        //     for(compare_iter = candidate_rank.begin();compare_iter != target_iter;compare_iter++){
        //         if(target_iter->second > compare_iter->second ) break;
        //     }
        //     if(target_iter == compare_iter) pass_candidate_num++;
        // }

        cout << pass_candidate_num << endl;
    }

}

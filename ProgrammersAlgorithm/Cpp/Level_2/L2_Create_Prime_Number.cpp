#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {

    int answer = 0;

    sort(nums.begin(),nums.end());

    vector<bool> prime(nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3]+1,true); 

    for(int i=2;i<prime.size();i++){
        if(prime[i]){
            for(int j=i*2;j<prime.size();j += i){
                prime[j] = false;
            }
        }
    }

    for(int i=0;i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                if(prime[nums[i] + nums[j] + nums[k]]) {
                    cout << nums[i] + nums[j] + nums[k] << endl;
                    answer ++;
                }
            }
        }
    }

    return answer;
}
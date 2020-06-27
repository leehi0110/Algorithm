#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int goCnt = 0;
    int backCnt = 0;
    
    string basic = "";
    for(int i=0;i<name.size();i++) basic += 'A';
    
    for(int i=0;i<name.size();i++){
        if(name[i] < 'N') {
            goCnt += name[i] - 'A';
        }
        else {
            goCnt += 'Z' - name[i] + 1;
        }
        basic[i] = name[i];
        if(basic == name) break;
        if(i != name.size()-1) goCnt ++;
    }
    
    basic = "";
    for(int i=0;i<name.size();i++) basic += 'A';
    
    name += name[0];
    name.erase(name.begin());
    
    for(int i=name.size()-1;i>=0;i--){
        if(name[i] < 'N'){
            backCnt += name[i] - 'A';
        }
        else {
            backCnt += 'Z' - name[i] + 1;
        }
        basic[i] = name[i];
        if(basic == name) break;
        if(i != 0) backCnt ++;
    }
    
    return goCnt > backCnt ? backCnt : goCnt;
}

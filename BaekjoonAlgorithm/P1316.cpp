// Baekjoon 1316
// 문제
// 그룹 단어 체커

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  int groupNum = 0;

  cin >> n;

  for(int i=0;i<n;i++){
    string target;
    vector <bool> alph;
    
    cin >> target;
    alph.clear();
    alph.resize(26,false);

    for(int j=0;j<target.length();j++){
      if(j+1 == target.length()){
        if(alph[target[j]-97]) break;
        else groupNum++;
      }
      else if(target[j] == target[j+1]){
        continue;
      }
      else {
        if(alph[target[j]-97]) break;
        else {
          alph[target[j]-97] = true;
          continue;
        }
      }
    }
  }
  cout << groupNum << endl;
}

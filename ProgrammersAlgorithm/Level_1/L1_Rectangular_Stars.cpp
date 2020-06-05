#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int a,b;

    cin >> a >> b;

    vector<vector<char>> star(b,vector<char>(a,'*'));

    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            cout << star[i][j];
        }
        cout << "\n";
    }
    return 0;
}

// 단순한 버전
// int main(void){
//   int a,b;
  
//   cin >> a >> b;

//   for(int i=0;i<b;i++){
//     for(int j=0;j<a;j++){
//       cout << '*';
//     }
//     cout << endl;
//   }

//   return 0;
// }
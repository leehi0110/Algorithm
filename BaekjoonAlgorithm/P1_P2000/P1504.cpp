// ProblemNumber || ProblemName : P1504 - 특정한 최단경로

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
}

// long long table[801][801];
// int main()
// {
//   ios_base ::sync_with_stdio(false);
//   cin.tie(NULL);

//   int n, e;
//   int firstStop, secondStop;

//   cin >> n >> e;

//   for (int i = 1; i <= n; i++)
//   {
//     for (int j = 1; j <= n; j++)
//     {
//       if (i == j)
//         table[i][j] = 0;
//       else
//         table[i][j] = INF;
//     }
//   }

//   for (int i = 0; i < e; i++)
//   {
//     int start, end, cost;

//     cin >> start >> end >> cost;

//     table[start][end] = cost;
//     table[end][start] = cost;
//   }

//   for (int k = 1; k <= n; k++)
//   {
//     for (int i = 1; i <= n; i++)
//     {
//       for (int j = 1; j <= n; j++)
//       {
//         if (i == j)
//           continue;
//         table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
//       }
//     }
//   }

//   cin >> firstStop >> secondStop;

//   long long result = min(table[1][firstStop] + table[firstStop][secondStop] + table[secondStop][n], table[1][secondStop] + table[secondStop][firstStop] + table[firstStop][n]);

//   if (result >= INF)
//     cout << -1 << endl;
//   else
//     cout << result << endl;
// }
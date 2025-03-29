#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<vector<vector<int>>> adjs;
  vector<int> results;

  while (true) {
    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0)
      break;

    vector<vector<int>> adj = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a][b] = c;
      adj[b][a] = c;
    }
    adjs.push_back(adj);
  }

  for (auto adj : adjs) {
    vector<int> row;
    for (int i = 0; i < adj.size(); i++) {
      row.push_back(i);
    }

    do {
      for (int i = 0; i < row.size(); i++) {
      }

    } while (next_permutation(row.begin(), row.end()));
  }

  return 0;
}

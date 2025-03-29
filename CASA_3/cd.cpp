#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, vector<int>> T;

struct Compare {
  bool operator()(const T &l, const T &r) const { return l.first < r.first; }
};

void print_vec(vector<int> vec) {
  int size = vec.size();
  for (int i = 0; i < size; i++) {
    cout << vec[i] << " ";
  }
}

T solve(vector<int> ts, int n) {
  int p, limit_mask;
  T top;

  p = ts.size();
  limit_mask = (1 << p);

  for (int bit_mask = 0; bit_mask < limit_mask; bit_mask++) {
    int t = 0;
    vector<int> tracks;

    for (int j = 0; j < p; j++) {
      if (bit_mask & (1 << j)) {
        if (t + ts[j] <= n) {
          int curr = ts[j];
          t += curr;
          tracks.push_back(curr);
        }
      }
    }

    if (t > top.first)
      top = make_pair(t, tracks);
  }

  return top;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> ts;
    if (n == 0 && m == 0)
      break;

    for (int i = 0; i < m; i++) {
      int t;
      cin >> t;
      ts.push_back(t);
    }

    T solved = solve(ts, n);

    print_vec(solved.second);
    cout << "sum:" << solved.first << endl;
  }
}

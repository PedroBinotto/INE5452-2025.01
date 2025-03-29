// vim:fileencoding=utf-8:foldmethod=marker

/* CASA 3 - Problemas backtracking / busca completa
 *
 * C - CD
 * {{{
 * You have a long drive by car ahead. You have a tape recorder, but
 * unfortunately your best music is on CDs. You need to have it on tapes so the
 * problem to solve is: you have a tape N minutes long. How to choose tracks from
 * CD to get most out of tape space and have as short unused space as possible.
 *
 * > Assumptions:
 *
 *   - number of tracks on the CD does not exceed 20
 *   - no track is longer than N minutes
 *   - tracks do not repeat
 *   - length of each track is expressed as an integer number
 *   - N is also integer
 *
 * Program should find the set of tracks which fills the tape best and print it
 * in the same sequence as the tracks are stored on the CD
 *
 * > Input
 *
 *   Any number of lines. Each one contains value N , (after space) number of
 *   tracks and durations of the tracks. For example from first line in sample
 *   data: N = 5, number of tracks=3, first track lasts for 1 minute, second one
 *   3 minutes, next one 4 minutes
 *
 * > Output
 *
 *   Set of tracks (and durations) which are the correct solutions and string
 *   ‘sum:’ and sum of duration times.
 *
 * > Sample Input
 *
 *   5 3 1 3 4
 *   10 4 9 8 4 2
 *   20 4 10 5 7 4
 *   90 8 10 23 1 2 3 4 5 7
 *   45 8 4 10 44 43 12 9 8 2
 *
 * > Sample Output
 *
 *   1 4 sum:5
 *   8 2 sum:10
 *   10 5 4 sum:19
 *   10 23 1 2 3 4 5 7 sum:55
 *   4 10 12 9 8 2 sum:45
 * }}}
 */

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

// vim:fileencoding=utf-8:foldmethod=marker

/* CASA 3 - Problemas backtracking / busca completa
 *
 * A - Bars
 * {{{
 * Some things grow if you put them together.
 *
 * We have some metallic bars, theirs length known, and, if necessary, we want to
 * solder some of them in order to obtain another one being exactly a given
 * length long. No bar can be cut up. Is it possible?
 *
 * > Input
 *
 *   The first line of the input contains an integer,t, 0 ≤ t ≤ 50, indicating
 *   the number of test cases. For each test case, three lines appear, the first
 *   one contains a number n, 0 ≤ n ≤ 1000, representing the length of the bar we
 *   want to obtain. The second line contains a number p, 1 ≤ p ≤ 20,
 *   representing the number of bars we have. The third line of each test case
 *   contains p numbers, representing the length of the p bars.
 *
 * > Output
 *
 *   For each test case the output should contain a single line, consists of the
 *   string ‘YES’ or the string ‘NO’, depending on whether solution is possible
 *   or not.
 *
 * > Sample Input
 *
 *   4
 *   25
 *   4
 *   10 12 5 7
 *   925
 *   10
 *   45 15 120 500 235 58 6 12 175 70
 *   120
 *   5
 *   25 25 25 25 25
 *   0
 *   2
 *   13 567
 *
 * > Sample Output
 *
 *   NO
 *   YES
 *   NO
 *   YES
 * }}}
 */

#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void p_out(bool r) { cout << (r ? "YES" : "NO") << endl; }

bool solve(vector<int> bs, int n) {
  int p, limit_mask;

  p = bs.size();
  limit_mask = (1 << p);

  for (int bit_mask = 0; bit_mask < limit_mask; bit_mask++) {
    int t = 0;
    for (int j = 0; j < p; j++) {
      if (t > n)
        break;
      if (bit_mask & (1 << j)) {
        t += bs[j];
      }
    }
    if (t == n)
      return true;
  }

  return false;
}

int main() {
  int t;
  cin >> t;

  vector<pair<int, vector<int>>> ss(t);

  for (int i = 0; i < t; i++) {
    int n, p;

    cin >> n;
    cin >> p;

    vector<int> bs;
    for (int j = 0; j < p; j++) {
      int l;
      cin >> l;
      if (l <= n)
        bs.push_back(l);
    }
    ss[i] = make_pair(n, bs);
  }

  for (auto s : ss) {
    int n = s.first;
    vector<int> bs = s.second;
    if (n == 0) {
      p_out(true);
      continue;
    }

    p_out(solve(bs, n));
  }

  return 0;
}

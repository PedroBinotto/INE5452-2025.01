#include <algorithm>
#include <cstdio>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

typedef tuple<int, pair<int, int>, pair<int, int>, vector<pair<int, int>>> T;

// void print_pair(pair<int, int> p) { cout << p.first << " " << p.second << endl; }
//
// void print_vec(vector<pair<int, int>> vec) {
//   int size = vec.size();
//   for (int i = 0; i < size; i++) {
//     print_pair(vec[i]);
//   }
// }

pair<int, int> rotate(pair<int, int> p) { return pair<int, int>(p.second, p.first); }

bool valid(T i) {
  int n = get<0>(i);
  pair<int, int> l = get<1>(i);
  pair<int, int> r = get<2>(i);
  vector<pair<int, int>> ps = get<3>(i);

  pair<int, int> p1, p2, p3, p4;

  p1 = ps[0];
  p2 = ps[n];
  p3 = rotate(p1);
  p4 = rotate(p2);

  return (p1.first == l.second || p3.first == l.second) && (p2.second == r.first || p4.second == r.first);
}

bool solve(T i) {
  int n = get<0>(i);
  pair<int, int> l = get<1>(i);
  pair<int, int> r = get<2>(i);
  vector<pair<int, int>> ps = get<3>(i);

  do {
    if (!valid(i))
      continue;

    pair<int, int> last = l;
    int matches = 0;

    for (auto p : ps) {
      if (p.first == last.second || rotate(p).first == last.second) {
        last = p.first == last.second ? p : rotate(p);
        ps.erase(ps.begin());
        matches++;
        if (matches == n && last.second == r.first) {
          return true;
        }
      } else {
        break;
      }
    }
  } while (next_permutation(ps.begin(), ps.end()));
  return false;
}

int main() {
  vector<T> inputs;

  while (true) {
    int m, n;
    pair<int, int> l, r;
    vector<pair<int, int>> ps;

    cin >> n;

    if (n == 0)
      break;

    cin >> m;

    cin >> l.first >> l.second;
    cin >> r.first >> r.second;

    for (int i = 0; i < m; i++) {
      pair<int, int> p;
      cin >> p.first >> p.second;
      ps.push_back(p);
    }

    inputs.push_back(T(n, l, r, ps));
  }

  for (auto i : inputs)
    cout << (solve(i) ? "YES" : "NO") << endl;

  return 0;
}

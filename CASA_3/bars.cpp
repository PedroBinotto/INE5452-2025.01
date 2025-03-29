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

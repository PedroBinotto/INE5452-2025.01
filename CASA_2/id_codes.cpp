#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

const string NO_SUCESSOR = "No Successor";

/* Input
 *   Input will consist of a series of lines each containing a string representing a code. The entire file will
 *   be terminated by a line consisting of a single ‘#’.
 * Output
 *   Output will consist of one line for each code read containing the successor code or the words ‘No
 *   Successor’.
 */

void print_vec(vector<string> vec) {
  int size = vec.size();
  for (int i = 0; i < size; i++) {
    cout << vec[i] << endl;
  }
}

void capture_input(vector<string> &strings) {
  while (true) {
    string i;
    cin >> i;

    if (i == "#")
      break;

    strings.push_back(i);
  }
}

int main() {
  vector<string> strings{};
  capture_input(strings);
  int n = strings.size();
  vector<string> results(n);

  for (int i = 0; i < n; i++) {
    string s = strings[i];
    vector<char> s_vec = vector<char>(s.begin(), s.end());
    int s_vec_size = s_vec.size();

    for (int j = s_vec_size - 1; j >= 0; j--) {
      if (j == 0) {
        results[i] = NO_SUCESSOR;
        break;
      }

      int d = s_vec[j - 1] - s_vec[j];

      if (d < 0) {
        s_vec[j] = s_vec[j] ^ s_vec[j - 1];
        s_vec[j - 1] = s_vec[j] ^ s_vec[j - 1];
        s_vec[j] = s_vec[j] ^ s_vec[j - 1];
        results[i] = string(s_vec.begin(), s_vec.end());

        break;
      }
    }
  }

  print_vec(results);

  return 0;
}

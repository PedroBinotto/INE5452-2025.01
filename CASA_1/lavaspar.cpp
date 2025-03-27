#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

map<string, vector<pair<vector<string>::iterator, vector<string>::iterator>>>
scan(const vector<string> grid, const vector<string> words) {}

int main() {
  int L, C, N;
  vector<string> grid(L);

  cin >> L >> C;

  for (int i = 0; i < L; ++i) {
    cin >> grid[i];
  }

  cin >> N;
  vector<string> words(N);
  for (int i = 0; i < N; ++i) {
    cin >> words[i];
  }

  for (int word_i = 0; word_i < N; word_i++) {
    string word = words[word_i];

    vector<string> letters;
    unordered_set<string> unique_letters;

    for (char letter : word) {
      letters.push_back(string(1, letter));
      unique_letters.insert(string(1, letter));
    }

    for (int line_i = 0; line_i < L; line_i++) {
      string line = grid[line_i];
      for (int letter_i; letter_i < C; letter_i++) {
        if (unique_letters.find(string(1, line[letter_i])) == unique_letters.end()) {
          continue;
        }
        int edgeDist = distance(line.begin() + line_i, line.end());
        if (edgeDist < C)
          continue;
      }
    }
  }

  // cout << "Grid:\n";
  // for (const auto &row : grid) {
  //   cout << row << "\n";
  // }
  //
  // cout << "Words:\n";
  // for (const auto &word : words) {
  //   cout << word << "\n";
  // }

  return 0;
}

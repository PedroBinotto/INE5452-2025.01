#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_queue(std::deque<int> q) {
  cout << "-----" << endl;
  cout << "size: " << q.size() << endl;
  while (!q.empty()) {
    std::cout << q.front() << "\n";
    q.pop_front();
  }
  std::cout << std::endl;
}

void print_vector(vector<int> vec) {
  int size = vec.size();
  for (int i = 0; i < size; i++) {
    string tail = i == size - 1 ? "" : ", ";
    cout << vec[i] << tail;
  }
  cout << "\n";
}

void print_vector(vector<deque<int>> vec) {
  int size = vec.size();
  for (int i = 0; i < size; i++) {
    print_queue(vec[i]);
    cout << "\n";
  }
}

int main() {
  vector<int> ins;

  while (true) {
    int i;
    cin >> i;
    if (i == 0)
      break;
    ins.push_back(i);
  }

  int N = ins.size();

  vector<deque<int>> decks(N);
  vector<pair<vector<int>, int>> results;

  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= ins[i]; j++) {
      decks[i].push_front(j);
    }
  }

  for (int i = 0; i < N; i++) {
    auto deck = decks[i];
    pair<vector<int>, int> result;

    while (true) {
      if (deck.size() == 1) {
        result.second = deck.back();
        results.push_back(result);
        break;
      }

      int top = deck.back();
      result.first.push_back(top);
      deck.pop_back();

      int new_top = deck.back();
      deck.push_front(new_top);
      deck.pop_back();
    }
  }

  for (auto result : results) {
    string discarded_tail = result.first.size() == 0 ? "" : " ";
    const string discarded = "Discarded cards:" + discarded_tail;
    string remaining_tail = result.second == 0 ? "" : " " + to_string(result.second);
    string remaining = "Remaining card:" + remaining_tail;

    cout << discarded;
    print_vector(result.first);
    cout << remaining << endl;
  }

  return 0;
}

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// void print_vec(vector<int> vec) {
//   int size = vec.size();
//   for (int i = 0; i < size; i++) {
//     cout << vec[i] << endl;
//   }
// }

int main() {
  vector<int> elements;
  int counter = 0;

  int el;
  while (cin >> el) {

    elements.insert(upper_bound(elements.begin(), elements.end(), el, std::less<int>{}), el);
    counter++;

    if (counter % 2 == 0) {
      int idx_a, idx_b;
      idx_a = (counter - 1) / 2;
      idx_b = idx_a + 1;
      cout << (elements[idx_a] + elements[idx_b]) / 2 << endl;
    } else {
      int idx_a = counter / 2;
      cout << elements[idx_a] << endl;
    }
  }
}

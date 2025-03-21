#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec) {
  int size = vec.size();
  for (int i = 0; i < size; i++) {
    string tail = i == size - 1 ? "\n" : " ";
    cout << vec[i] << tail;
  }
}

vector<int> follow(vector<int> in, vector<int> out, int s) {
  int curr = in[s] - 1;
  out[curr]++;

  if (curr == 0)
    return out;
  return follow(in, out, curr);
}

int main() {
  int N;
  cin >> N;

  vector<int> employees_in(N), employees_out(N);

  for (int i = 0; i < N - 1; i++) {
    cin >> employees_in[i + 1];
  }

  for (int i = 1; i < N; i++) {
    employees_out = follow(employees_in, employees_out, i);
  }

  print_vec(employees_out);

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

string a, b;
bool win, lose;
int counter, chance;

void guess(char ch);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int rnd;
  while (cin >> rnd && rnd != -1) {
    cin >> a >> b;
    win = false; lose = false;
    counter = (int) a.length();
    chance = 7;
    for (int i = 0; i < (int) b.length(); i++) {
      guess(b[i]);
      if (win || lose) {
        break;
      }
    }
    cout << "Round " << rnd << '\n';
    if (win) {
      cout << "You win.\n";
    } else if (lose) {
      cout << "You lose.\n";
    } else {
      cout << "You chickened out.\n";
    }
  }
  return 0;
}

void guess(char ch) {
  bool bad = true;
  for (int i = 0; i < (int) a.length(); i++) {
    if (ch == a[i]) {
      a[i] = ' ';
      bad = false;
      --counter;
    }
  }
  if (bad) {
    --chance;
  }
  if (chance == 0) {
    lose = true;
  }
  if (counter == 0) {
    win = true;
  }
  return;
}

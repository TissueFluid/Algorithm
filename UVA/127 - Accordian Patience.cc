#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

struct Card {
  char face[3];

  Card(char *card) {
    strncpy(face, card, 3);
  }

  int match(const Card & card) {
    return this->face[0] == card.face[0] || this->face[1] == card.face[1];
  }
};

typedef vector< stack< Card > > pile_t;
pile_t g_pile;


int match_and_move(unsigned long i, unsigned long j) {
  int k;
  pile_t::iterator p = g_pile.begin();
  for (k = 0; k < i; k++) {
    ++p;
  }

  pile_t::iterator q = p;
  for (; k < j; k++) {
    ++q;
  }

  if (p->top().match(q->top())) {
    p->push(q->top());
    q->pop();
    if (q->empty()) {
      g_pile.erase(q);
    }
    return 1;
  }
  return 0;
}

int check(unsigned long i) {
  if (i >= 3) {
    if (match_and_move(i - 3, i)) {
      return 1;
    }
  }

  if (i >= 1) {
    if (match_and_move(i - 1, i)) {
      return 1;
    }
  }

  return 0;
}

int main(int argc, char const* argv[])
{
  char face[3];
  int i;

  while (scanf("%2s", face) && face[0] != '#') {
    g_pile.clear();
    stack<Card> s;
    s.push(Card(face));
    g_pile.push_back(s);

    for (i = 0; i < 51; i++) {
      scanf("%2s", face);
      stack<Card> s;
      s.push(Card(face));
      g_pile.push_back(s);
    }

    while (1) {
      pile_t::size_type n = g_pile.size();
      for (i = 0; i < n; i++) {
        if (check(i)) {
          break;
        }
      }
      if (i == n) {
        break;
      }
    }

    pile_t::size_type n = g_pile.size();
    if (n == 1)
      printf("%lu pile remaining:", n);
    else
      printf("%lu piles remaining:", n);

    for (i = 0; i < n; i++) {
      printf(" %lu", g_pile.at(i).size());
    }
    putchar('\n');
  }
  return 0;
}

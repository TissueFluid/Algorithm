#include <stdio.h>
#include <algorithm>
#include <list>

using namespace std;

list<int> l[25];
int position[25];

void reset_after(list<int>::iterator begin, list<int> *p) {
  ++begin;
  for (list<int>::iterator it = begin; it != p->end(); ++it) {
    l[*it].push_back(*it);
    position[*it] = *it;
  }
  p->erase(begin, p->end());
}


int main(int argc, char const* argv[])
{
  int n;
  char buf[10];
  char buf2[10];
  int a, b;
  int i;

  scanf("%2d", &n);

  for (i = 0; i < n; i++) {
    position[i] = i;
    l[i].push_back(i);
  }

  while (scanf("%5s", buf) && buf[0] != 'q') {
    scanf("%2d %5s %2d", &a, buf2, &b);
    if (a == b || position[a] == position[b]) {
      continue;
    }

    list<int> *pa = l + position[a];
    list<int> *pb = l + position[b];
    list<int>::iterator fa = find(pa->begin(), pa->end(), a);
    list<int>::iterator fb = find(pb->begin(), pb->end(), b);

    if (buf[0] == 'm') {
      reset_after(fa, pa);
      if (buf2[1] == 'n') {
        reset_after(fb, pb);
      }
      pa->erase(fa);
      pb->push_back(a);
    } else {
      for (list<int>::iterator it = fa; it != pa->end(); ++it) {
        position[*it] = position[b];
      }
      if (buf2[1] == 'n') {
        reset_after(fb, pb);
        pb->insert(++fb, fa, pa->end());
      } else {
        pb->insert(pb->end(), fa, pa->end());
      }
      pa->erase(fa, pa->end());
    }
    position[a] = position[b];
  }

  for (i = 0; i < n; i++) {
    printf("%d:", i);
    for (list<int>::iterator it = l[i].begin();
        it != l[i].end();
        ++it) {
      printf(" %d", *it);
    }
    printf("\n");
  }
  return 0;
}

#include <stdio.h>

int main() {
  int fn, rn;
  printf("No. of Frames: ");
  scanf("%d", & fn);
  int f[fn];
  printf("No. of Page Requests: ");
  scanf("%d", & rn);
  int r[rn];

  printf("Page Request Queue:\n");
  for (int i = 0; i < rn; ++i)
    scanf("%d", & r[i]);

  int fIndex = -1;
  int hit = 0;
  int miss = 0;

  for (int i = 0; i < fn; ++i) {
    f[i] = r[i];
    miss++;
  }

  fIndex = 0;
  int flag;
  for (int i = fn; i < rn; ++i) {
    flag = 0;
    for (int j = 0; j < fn; ++j) {
      if (r[i] == f[j]) {
        flag = 1;
        hit++;
        break;
      }
    }
    if (!flag) {
      f[fIndex++] = r[i];
      if (fIndex == fn)
        fIndex = 0;
      miss++;
    }
  }

  printf("\nMiss: %d", miss);
  printf("\nHit: %d\n", hit);

  float hratio, mratio;
  hratio = (float) hit / rn;
  mratio = (float) miss / rn;
  printf("Hit Ratio: %f\n", hratio);
  printf("Miss Ratio: %f\n", mratio);

  return 0;
}

OUTPUT

No. of Frames: 3
No. of Page Requests: 10
Page Request Queue:
4 7 6 1 7 6 1 2 7 2

Miss: 6
Hit: 4
Hit Ratio: 0.400000
Miss Ratio: 0.600000

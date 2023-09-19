#include <conio.h>
#include <string.h>

#define SCR_W 40
#define SCR_H 24

void border(int x, int y, int width, int height)
{
  int i;

  revers(1);

  // Top starting at x,y
  for (i = x; i < width; ++i)
  {
    cputsxy(i, y, " ");
  }

  // Sides at x & width starting at y+1
  for (i = (y + 1); i < (height - 1); ++i)
  {
    cputsxy(x, i, " ");
    cputsxy((width - 1), i, " ");
  }

  // Bottom starting at height, y
  for (i = x; i < width; ++i)
  {
    cputsxy(i, (height - 1), " ");
  }

  revers(0);
}

void main(void)
{
  char *msg = "Hello world!\n";
  int center = 20 - (strlen(msg) / 2);

  clrscr();
  border(1, 1, SCR_W, SCR_H);
  border(5, 5, (SCR_W - 5), (SCR_H - 5));
  gotoxy(center, 12);
  revers(1);
  cputs(msg);
  revers(0);
  cgetc();
}
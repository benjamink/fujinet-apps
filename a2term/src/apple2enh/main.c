#include <apple2enh.h>
#include <conio.h>
#include <string.h>

#define SLOTS 20

unsigned char SCRW, SCRH;

void border(int x, int y, int width, int height, int fill)
{
  int i;

  revers(1);

  // Top starting at x,y
  for (i = x; i < width; ++i)
  {
    cputsxy(i, y, " ");
  }

  // Sides at x & width starting at y+1
  if ((y + 1) <= height)
  {
    for (i = (y + 1); i < height; ++i)
    {
      if (fill == 1)
      {
        cputsxy(x, i, ('x' * width));
      }
      else
      {
        cputsxy(x, i, " ");
        cputsxy((width - 1), i, " ");
      }
    }
  }

  // Bottom starting at height, y
  for (i = x; i < width; ++i)
  {
    cputsxy(i, (height - 1), " ");
  }

  revers(0);
}

void draw_name_spaces(void)
{
  int l;
  int c;

  for (l = 4; l <= SLOTS; ++l)
  {
    for (c = 2; c <= (SCRW / 2) - 3; ++c)
      cputsxy(c, l, "_");
    // chlinexy(2, l, (SCRW / 2) - 4);
    for (c = (SCRW / 2) + 1; c <= SCRW - 3; ++c)
      cputsxy(c, l, "_");
    // chlinexy((SCRW / 2) + 1, l, (SCRW / 2) - 3);
  }
}

void draw_background(void)
{
  clrscr();
  border(0, 0, SCRW, 2, 1);
  border(0, 1, SCRW, SCRH, 0);
  border(0, 1, (SCRW / 2), SCRH, 0);
  draw_name_spaces();
}

void draw_headings(void)
{
  char *title = "Apple][Term\n";
  int title_center = (SCRW / 2) - (strlen(title) / 2);
  int scr_qtr = SCRW / 4;

  revers(1);
  cputsxy(title_center, 0, title);
  cputsxy((scr_qtr - 2), 1, "NAME");
  cputsxy(((scr_qtr * 3) - 1), 1, "URL");
  revers(0);
}

void draw_footer(void)
{
  /*
    TODO: Find a better way to calculate the string length

      [A]DD     (3) +2
      [E]DIT    (4) +2
      [R]EMOVE  (6) +2
      [D]IAL    (4) +2
                (17) 25
  */
  unsigned int startl = (SCRW - 25) / 2;

  gotoxy(startl, (SCRH - 1));
  revers(0);
  cputs("A");
  revers(1);
  cputs("DD  ");
  revers(0);
  cputs("E");
  revers(1);
  cputs("DIT  ");
  revers(0);
  cputs("R");
  revers(1);
  cputs("EMOVE  ");
  revers(0);
  cputs("D");
  revers(1);
  cputs("IAL");
}

void main(void)
{
  videomode(VIDEOMODE_80x24);

  screensize(&SCRW, &SCRH);

  draw_background();
  draw_headings();
  draw_footer();

  gotoxy(2, 4);
  cursor(1);

  cgetc();
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  draw_line(0, 250, 500, 250, s, c);
  draw_line(0, 125, 500, 375, s, c);
  draw_line(0, 0, 500, 500, s, c);
  draw_line(125, 0, 375, 500, s, c);
  draw_line(250, 0, 250, 500, s, c);
  draw_line(125, 500, 375, 0, s, c);
  draw_line(0, 500, 500, 0, s, c);
  draw_line(0, 375, 500, 125, s, c);

  /*
  draw_line(125, 375, 375, 375, s, c);
  draw_line(375, 125, 375, 375, s, c);
  draw_line(125, 125, 125, 375, s, c);
  draw_line(125, 125, 375, 125, s, c);
  */

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = 0;

  draw_line(125, 125, 250, 275, s, c);
  draw_line(250, 275, 375, 125, s, c);
  draw_line(125, 125, 375, 125, s, c);

  draw_line(125, 375, 250, 225, s, c);
  draw_line(250, 225, 375, 375, s, c);
  draw_line(125, 375, 375, 375, s, c);

  display(s);
  save_extension(s, "lines.png");
}

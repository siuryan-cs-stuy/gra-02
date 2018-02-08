#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int A = y1 - y0;
    int B = -x1 + x0;

    int x, y;
    if (x0 <= x1) {
        x = x0;
    } else {
        x = x1;
    }
    y = y0;

    int d;

    if ((A >= 0 && -B >= 0) || (A <= 0 && -B <= 0)) {
        // octants I, II
        if (abs(B) >= abs(A)) {
            // octant I
            d = 2*A + B;

            while (x <= x1) {
                plot(s, c, x, y);

                if (d > 0) {
                    y++;
                    d += 2*B;
                }
                x++;
                d += 2*A;
            }
        } else {
            // octant II
            d = A + 2*B;

            while (y <= y1) {
                plot(s, c, x, y);

                if (d < 0) {
                    x++;
                    d += 2*A;
                }
                y++;
                d += 2*B;
            }
        }
    } else {
        if (abs(B) >= abs(A)) {
            // octant VIII
            d = 2*A - B;

            while (x <= x1) {
                plot(s, c, x, y);

                if (d < 0) {
                    y--;
                    d -= 2*B;
                }
                x++;
                d += 2*A;
            }
        } else {
            // octant VII
            d = A - 2*B;
            while (x <= x1) {
                plot(s, c, x, y);

                if (d > 0) {
                    x++;
                    d += 2*A;
                }
                y--;
                d -= 2*B;
            }
        }
    }
}

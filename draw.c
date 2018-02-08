#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int A = y1 - y0;
    int B = -x1 + x0;
    int x = x0;
    int y = y0;

    int d, sign;

    printf("%d\n", A);
    printf("%d\n", -B);
    if ((A >= 0 && -B >= 0) || (A <= 0 && -B <= 0)) {
        // octants I, II
        if (-B >= A) {
            // octant I
            d = 2*A + B;
            sign = 1;
        } else {
            // octant II
            d = A + 2*B;
            sign = -1;
        }
    } else {
        if (-B >= A) {
            // octant VIII
            d = 2*A - B;
            sign = 1;
        } else {
            // octant VII
            d = A - 2*B;
            sign = -1;
        }
    }

    while (x <= x1) {
        plot(s, c, x, y);
        if (sign > 0) {
            if (d > 0) {
                y += sign * 1;
                d += 2*B;
            }
            x += sign * 1;
            d += 2*A;
        } else {
            if (d < 0) {
                x += sign*1;
                d += 2*A;
            }
            y += sign * 1;
            d += 2*B;
        }
    }
}

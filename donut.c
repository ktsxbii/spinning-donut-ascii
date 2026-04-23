#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    float t_color = 0;
    printf("\x1b[2J");
    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H");
        for (k = 0; k < 1760; k++) {
            if (k % 80 == 0 && k != 0) putchar(10);
            if (b[k] != ' ') {
                int x = k % 80;
                int y = k / 80;
                int r = 127.5 * (sin(0.1 * x + t_color) + 1);
                int g = 127.5 * (sin(0.1 * y + t_color + 2) + 1);
                int b_val = 127.5 * (sin(0.1 * (x + y) + t_color + 4) + 1);
                printf("\x1b[38;2;%d;%d;%dm%c\x1b[0m", r, g, b_val, b[k]);
            } else {
                putchar(' ');
            }
        }
        A += 0.04;
        B += 0.02;
        t_color += 0.05;
        usleep(30000);
    }
    return 0;
}

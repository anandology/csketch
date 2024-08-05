// Grid of Random Concentric Circles
#include <sketch.h>

void random_concentric_circles(float x, float y, int radius, int n)
{
    for (int i=0; i<n; i++) {
        int r = 1 + rand() % radius;
        draw_circle(x, y, r);
    }
}

void draw_shape(float x, float y, float size) {
    random_concentric_circles(x, y, size/2, 10);
}

void make_grid(int n)
{
    float dx = 600/n;
    float dy = dx;

    float x0 = -300+dx/2;
    float y0 = -300+dy/2;

    for (float x=x0; x<300; x+=dx)
    {
        for (float y=y0; y<300; y+=dy)
        {
            draw_shape(x, y, dx);
        }
    }
}

int main() {
    make_grid(6);
    save_sketch("grid-of-random-concentric-circles.svg");
}

// Concentric Circles
#include <sketch.h>

void concentric_circles(float radius, int n)
{
    float r = radius/n;

    for (int i=1; i<=n; i++) {
        draw_circle(0, 0, i*r);
    }
}

int main()
{
    concentric_circles(250, 20);
    save_sketch("concentric-circles.svg");
}
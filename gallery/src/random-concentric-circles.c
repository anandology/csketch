// Random Concentric Circles
//
// Concentric circles with radius of each circle picked at random.
#include <sketch.h>

void random_concentric_circles(int radius, int n)
{
    for (int i=0; i<n; i++) {
        int r = 1 + rand() % radius;
        draw_circle(0, 0, r);
    }
}


int main()
{
    random_concentric_circles(250, 20);
    save_sketch("random-concentric-circles.svg");
}
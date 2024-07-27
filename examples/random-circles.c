#include <sketch.h>

// Draw n circles each with radius between 0 and radius, picked at random
void random_cirlces(int radius, int n)
{
    for (int i=0; i<n; i++)
    {
        int r = 1 + rand() % radius;
        draw_circle(0, 0, r);
    }
}

int main()
{
    random_cirlces(250, 20);
    save_sketch("random-circles.svg");
}

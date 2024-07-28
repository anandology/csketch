#include <sketch.h>

int main() {
    // draw a circle with center at (0, 0) and radius 100
    draw_circle(0, 0, 100);

    // save the sketch to file circle.svg
    save_sketch("circle.svg");
}

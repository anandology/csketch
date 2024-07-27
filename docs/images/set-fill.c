#include <sketch.h>

int main() {

    set_fill("red");
    draw_circle(0, 0, 250);

    set_fill("green");
    draw_circle(0, 0, 200);

    set_fill("blue");
    draw_circle(0, 0, 150);

    save_sketch("set-fill.svg");
}

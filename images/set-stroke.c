#include <sketch.h>

int main() {

    set_stroke("red");
    draw_circle(0, 0, 250);

    set_stroke("green");
    draw_circle(0, 0, 200);

    set_stroke("blue");
    draw_circle(0, 0, 150);

    save_sketch("set-stroke.svg");
}

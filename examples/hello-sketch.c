#include <sketch.h>

int main() {

    set_stroke("blue");
    set_fill("lightblue");
    draw_circle(0, 0, 100);

    set_stroke("red");
    draw_line(-200, 0, 200, 0);

    save_sketch("hello-sketch.svg");
}

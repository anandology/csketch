#include <sketch.h>

int main() {

    int x1 = -200;
    int x2 = 200;

    int y = 200;

    // set_stroke_width(1);
    // draw_line(x1, y, x2, y);
    // y -= 50;

    // set_stroke_width(2);
    // draw_line(x1, y, x2, y);
    // y -= 50;

    // set_stroke_width(3);
    // draw_line(x1, y, x2, y);
    // y -= 50;

    // set_stroke_width(4);
    // draw_line(x1, y, x2, y);
    // y -= 50;


    set_stroke_width(0.5);
    draw_line(-200, 100, 200, 100);

    set_stroke_width(1);
    draw_line(-200, 0, 200, 0);

    set_stroke_width(5);
    draw_line(-200, -100, 200, -100);

    save_sketch("stroke-width.svg");
}

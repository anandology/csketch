#include <sketch.h>

int main()
{
    int h;

    set_sketch_size(600, 200);

    // draw a vertical line
    h = get_sketch_width();
    draw_line(0, -h / 2, 0, h / 2);

    save_sketch("get-sketch-height.svg");
}

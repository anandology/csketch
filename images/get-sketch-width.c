#include <sketch.h>

int main()
{
    int w;

    set_sketch_size(600, 200);

    // draw a horizontal line
    w = get_sketch_width();
    draw_line(-w / 2, 0, w / 2, 0);

    save_sketch("get-sketch-width.svg");
}

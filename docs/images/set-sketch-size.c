#include <sketch.h>

int main()
{
    // set the sketch width to 600 and height to 200.
    set_sketch_size(600, 200);

    draw_circle(-200, 0, 100);
    draw_circle(0, 0, 100);
    draw_circle(200, 0, 100);

    save_sketch("set-sketch-size.svg");
}

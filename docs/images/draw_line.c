#include <sketch.h>

int main() {
    draw_line(-200, 0, 200, 0);
    draw_line(0, -100, 0, 100);

    save_sketch("draw_line.svg");
}

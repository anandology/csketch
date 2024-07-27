# CSketch

CSketch is a simple library to drawing shapes in C programming language.

It doesn't have any other dependencies and renders the out as an SVG image.

## How to use

```c title="circle.c"
#include <sketch.h>

int main() {
    draw_circle(0, 0, 200);
    save_sketch("circle.svg");
}
```

And that would create a file `circle.svg` with the following image.

<img class="sketch" src="images/circle.svg" alt="circles.svg">

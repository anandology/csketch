# Donuts

<img class="sketch-lg" src="../images/donuts.svg">



## Code

```c
#include <sketch.h>

void draw_donut(float x, float y, float r)
{
    draw_circle(x, y, r);
    draw_circle(x, y, r/2);
}

int main() {
    draw_donut(0, 0, 200);
    save_sketch("donuts.svg");
}

```


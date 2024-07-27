# Checker Board

<img class="sketch-lg" src="../images/checker-board.svg">



## Code

```c
#include <sketch.h>

void draw_shape(float x, float y, float size, int i, int j) {
    char *fill = (i+j)%2==1? "black": "red";
    set_fill(fill);
    draw_rectangle(x, y, size, size);
}

void make_grid(int n)
{
    float dx = 600/n;
    float dy = dx;

    float x0 = -300+dx/2;
    float y0 = -300+dy/2;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            float x = x0+i*dx;
            float y = y0+j*dy;
            draw_shape(x, y, dx, i, j);
        }
    }
}

int main() {
    set_stroke("none");
    make_grid(8);
    save_sketch("checker-board.svg");
}

```


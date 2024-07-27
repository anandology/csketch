# Flag of Italy

<img class="sketch-lg" src="../images/flag-of-italy.svg">


The Wikipedia page for [Flag of Italy][1] has the details about the colors
of the flag. This little program tries to make the flag with the right colors.
However, the proportations are not maintained.

[The flag of Netherlands][2] is as equally simple. Would you like to give it a try?
[1]: https://en.wikipedia.org/wiki/Flag_of_Italy
[2]: https://en.wikipedia.org/wiki/Flag_of_the_Netherlands

## Code

```c
#include <sketch.h>

int main()
{
    // Colors of Flag of Italy as mentioned on the wikipedia page
    // https://en.wikipedia.org/wiki/Flag_of_Italy#Chromatic_definition

    char *green = "#008C45";    // golf Green
    char *white = "#F4F5F0";    // Cloud Dancer
    char *red = "#CD212A";      // Tomato

    set_stroke("none");

    set_fill(green);
    draw_rectangle(-200, 0, 200, 600);

    set_fill(white);
    draw_rectangle(0, 0, 200, 600);

    set_fill(red);
    draw_rectangle(200, 0, 200, 600);

    save_sketch("flag-of-italy.svg");
}
```


# Getting Started

To use the functionality of _csketch_, you need to include the `sketch.h` header file.

## An Example

Consider the following program circle.c that draws a circle with a radius of `200` pixels and center at point `(0, 0)`.

```c title="circle.c" linenums="1"
#include <sketch.h>

int main()
{
    draw_circle(0, 0, 200);

    save_sketch("circle.svg");
}
```

The first line includes the `sketch.h` header file required to use the functionality of the `csketch` library.

The call to function `draw_circle` in line number `5`, makes a circle with the specified details.

The last line in the function `main` is a call to `save_sketch` which write all the shapes that have been drawn earlier to an SVG file.

## Compiling

To compile the program that we wrote above, we need to run the following command.

```
$ gcc circle.c -I sketch/ -L sketch/ -l sketch -o circle
```

The above command may look too intimidating. It is not as complex as it seems. Here is the explanation for the options passed to gcc.

```
gcc         # the command to run
circle.c    # the program to compile
-I sketch/  # look for header files in sketch/ directory
-L sketch/  # look for libraries in sketch/ directory
-l sketch   # link to the sketch library, this will look for file libsketch.a
-o circle   # write the compiled executable to file with name circle
```

Once the compilation is successful, you can run the target file created, `circle`.

```
$ ./circle
Saved the sketch as circle.svg
```

Now you can open the `circle.svg` file from your file explorer. If you don't find any application to open svg files, you can open them in your web browser.

You should see an image like this (prehaps, without the gray borders).

<img class="sketch" src="../images/circle.svg" alt="circle.svg">

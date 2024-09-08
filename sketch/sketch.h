// Experimental Implementation of a Sketch program entirely in C.

#include <stdio.h>
#include <stdlib.h>

#ifndef SKETCH_H
#define SKETCH_H

typedef struct {
    float stroke_width;
    char *stroke;
    char *fill;
} style_t;

struct line_data {
    float x1;
    float y1;
    float x2;
    float y2;
};

struct circle_data {
    float x;
    float y;
    float r;
};

struct rectangle_data {
    float x;
    float y;
    float w;
    float h;
};

enum shape_type {
    SHAPE_NULL,
    SHAPE_LINE,
    SHAPE_CIRCLE,
    SHAPE_RECTANGLE
};

typedef struct _shape {
    enum shape_type type;
    struct _shape *next;
    style_t style;
    union {
        struct line_data *line_data;
        struct circle_data *circle_data;
        struct rectangle_data *rectangle_data;
    };
} shape_t;

void set_stroke(char * color);
void set_fill(char *color);
void set_stroke_width(float width);

// Draws a line from point (x1, y1) to point (x2, y2)
void draw_line(float x1, float y1, float x2, float y2);

// Draws a circle with (x, y) as the center and with radius r
void draw_circle(float x, float y, float r);

// Draws a rectangle with (x, y) as the center point
// and a width of w and a height of h
void draw_rectangle(float x, float y, float w, float h);

void draw_grid();
void display_shapes();

void set_sketch_size(int new_width, int new_height);

// saves the sketch into a file
void save_sketch(char *filename);

// clears all the shapes draws so far
void clear_sketch();

#endif
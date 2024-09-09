// Experimental Implementation of a Sketch program entirely in C.

#include <stdio.h>
#include <stdlib.h>

#include "sketch.h"

char *stroke = "black";
char *fill = "none";
float stroke_width = 1.0;
int sketch_width = 600;
int sketch_height = 600;

void set_stroke(char *color)
{
    stroke = color;
}

void set_fill(char *color)
{
    fill = color;
}

void set_stroke_width(float width)
{
    stroke_width = width;
}

shape_t *shapes_list = NULL;

void add_shape(shape_t *shape)
{
    shape->next = shapes_list;
    shapes_list = shape;
}

shape_t *new_shape(int type, void *shape_data)
{
    shape_t *s = (shape_t *)malloc(sizeof(shape_t));

    s->type = type;

    // it is a union so, setting either of line_data, circle_data will have same effect
    s->line_data = (struct line_data *)shape_data;

    s->style.stroke = stroke;
    s->style.fill = fill;
    s->style.stroke_width = stroke_width;

    return s;
}

shape_t *new_line(float x1, float y1, float x2, float y2)
{
    struct line_data *data = (struct line_data *)malloc(sizeof(struct line_data));

    data->x1 = x1;
    data->y1 = y1;
    data->x2 = x2;
    data->y2 = y2;

    return new_shape(SHAPE_LINE, data);
}

shape_t *new_circle(float x, float y, float r)
{
    struct circle_data *data = (struct circle_data *)malloc(sizeof(struct circle_data));
    data->x = x;
    data->y = y;
    data->r = r;
    return new_shape(SHAPE_CIRCLE, data);
}

shape_t *new_rectangle(float x, float y, float w, float h)
{
    struct rectangle_data *data = (struct rectangle_data *)malloc(sizeof(struct rectangle_data));
    data->x = x;
    data->y = y;
    data->w = w;
    data->h = h;
    return new_shape(SHAPE_RECTANGLE, data);
}

void display_shapes()
{
    shape_t *s = shapes_list;

    while (s != NULL)
    {
        switch (s->type)
        {
        case SHAPE_LINE:
            printf("line(%0.2f, %0.2f, %0.2f, %0.2f)\n",
                   s->line_data->x1,
                   s->line_data->y1,
                   s->line_data->x2,
                   s->line_data->y2);
            break;
        case SHAPE_CIRCLE:
            printf("circle(%0.2f, %0.2f, %0.2f)\n",
                   s->circle_data->x,
                   s->circle_data->y,
                   s->circle_data->r);
            break;
        case SHAPE_RECTANGLE:
            printf("rectangle(%0.2f, %0.2f, %0.2f %0.2f)\n",
                   s->rectangle_data->x,
                   s->rectangle_data->y,
                   s->rectangle_data->w,
                   s->rectangle_data->h);
            break;
        }
        s = s->next;
    }
}

void draw_grid()
{
    set_stroke("gray");
    for (int i = -sketch_height / 2; i < sketch_height / 2; i += 100)
    {
        draw_line(-sketch_width, i, sketch_width, i);
    }
    for (int j = -sketch_width; j < sketch_width; j += 100)
    {
        draw_line(j, -sketch_height, j, sketch_height);
    }
    set_stroke("black");
}

void draw_line(float x1, float y1, float x2, float y2)
{
    shape_t *s = new_line(x1, y1, x2, y2);
    add_shape(s);
}

void draw_circle(float x, float y, float r)
{
    shape_t *s = new_circle(x, y, r);
    add_shape(s);
}

void draw_rectangle(float x, float y, float w, float h)
{
    shape_t *s = new_rectangle(x, y, w, h);
    add_shape(s);
}

void write_shape(FILE *fp, shape_t *shape)
{
    float x, y;
    switch (shape->type)
    {
    case SHAPE_LINE:
        fprintf(fp, "  <line x1='%f' y1='%f' x2='%f' y2='%f' stroke='%s' stroke-width='%f'/>\n",
                shape->line_data->x1,
                shape->line_data->y1,
                shape->line_data->x2,
                shape->line_data->y2,
                shape->style.stroke,
                shape->style.stroke_width);
        break;
    case SHAPE_CIRCLE:
        fprintf(fp, "  <circle cx='%f' cy='%f' r='%f' stroke='%s' fill='%s' stroke-width='%f'/>\n",
                shape->circle_data->x,
                shape->circle_data->y,
                shape->circle_data->r,
                shape->style.stroke,
                shape->style.fill,
                shape->style.stroke_width);
        break;
    case SHAPE_RECTANGLE:
        x = shape->rectangle_data->x - shape->rectangle_data->w / 2;
        y = shape->rectangle_data->y - shape->rectangle_data->h / 2;

        fprintf(fp, "  <rect x='%f' y='%f' width='%f' height='%f' stroke='%s' fill='%s' stroke-width='%f'/>\n",
                x,
                y,
                shape->rectangle_data->w,
                shape->rectangle_data->h,
                shape->style.stroke,
                shape->style.fill,
                shape->style.stroke_width);
        break;
    }
}

// Write a list of shapes to an SVG file
void write_shapes(FILE *fp, shape_t *shapes_list)
{
    // since shapes_list is a linked list, the last shape with be at the head.
    // Using a recursive approach to write the tail first and the head
    // so that we get the order as expected.
    if (shapes_list != NULL)
    {
        write_shapes(fp, shapes_list->next);
        write_shape(fp, shapes_list);
    }
}

void set_sketch_size(int width, int height)
{
    sketch_height = height;
    sketch_width = width;
}

int get_sketch_width()
{
    return sketch_width;
}
int get_sketch_height()
{
    return sketch_height;
}
void save_sketch(char *filename)
{
    FILE *fp = fopen(filename, "w");

    fprintf(fp, "<?xml version='1.0' standalone='no'?>\n");
    fprintf(fp, "<svg version='1.1' viewBox='-%d -%d %d %d' width='%d' height='%d'  xmlns='http://www.w3.org/2000/svg'>\n", sketch_width / 2, sketch_height / 2, sketch_width, sketch_height, sketch_width, sketch_height);
    fprintf(fp, "<rect x='-%d' y='-%d' width='100%%' height='100%%' fill='white' />", sketch_width / 2, sketch_height / 2);
    fprintf(fp, "<g transform='scale(1, -1)'>\n");
    write_shapes(fp, shapes_list);
    fprintf(fp, "</g></svg>");
    fclose(fp);
}

void clear_sketch()
{
    // clear shapes
    shape_t *shapes = shapes_list;
    shapes_list = NULL;

    // free all the allocated shapes
    while (shapes)
    {
        shape_t *s = shapes;
        shapes = shapes->next;
        free(s->line_data);
        free(s);
    }
}
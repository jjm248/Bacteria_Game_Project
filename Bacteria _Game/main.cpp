#include <iostream>
#include <doodle/doodle.hpp>

using namespace doodle;
using namespace std;

double                   angle{ 0.0 };
double                   grey{ 0 };
double                   x{ 0.0 };
double                   y{ 0.0 };

void moved(int mouse_x, int mouse_y)
{
    angle += to_radians(3.0);
    grey = 255 * (std::sin(angle) * 0.5 + 0.5);
    x = mouse_x;
    y = mouse_y;
}

int main(void)
{
    create_window(720, 720);

    const Image germ{ "./Game characters/germ_1.png" };

    set_image_mode(RectMode::Center);
    while (!is_window_closed())
    {
        update_window();
        clear_background(255,255,255);
        draw_image(germ, x, y, 100, 128);
    }

    set_rectangle_mode(RectMode::Center);
    while (!is_window_closed())
    {
        update_window();
        clear_background(220);
        set_fill_color(grey);
        draw_rectangle(x, y, Width * 0.4, Height * 0.4);
    }
    return 0;
}
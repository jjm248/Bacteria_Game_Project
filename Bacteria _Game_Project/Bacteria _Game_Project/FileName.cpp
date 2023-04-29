#include <doodle/doodle.hpp>
#include <iostream>

using namespace doodle;
using namespace std;

int main(void)
{

        create_window(480, 360);
        while (!is_window_closed())
        {
            update_window();
            clear_background(244, 248, 252);
            const int mouseX = get_mouse_x();
            draw_line(mouseX, Height / 2.0, mouseX, -Height / 2.0);
        }

    return 0;
}
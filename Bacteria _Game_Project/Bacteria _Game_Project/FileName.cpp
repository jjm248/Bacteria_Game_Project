#include <doodle/doodle.hpp>
#include <string>
using namespace doodle;
int main(void)
{
    create_window(480, 360);
    set_rectangle_mode(RectMode::Center);
    while (!is_window_closed())
    {
        update_window();
        clear_background(237, 34, 93);
        set_fill_color(0);
        set_frame_of_reference(FrameOfReference::RightHanded_OriginCenter);
        if (MouseIsPressed)
        {
            draw_ellipse(0, 0, Width / 2.0, Height / 2.0);
        }
        else
        {
            draw_rectangle(0, 0, Width / 2.0, Height / 2.0);
        }
        set_fill_color(255);
        set_frame_of_reference(FrameOfReference::RightHanded_OriginBottomLeft);
        using namespace std::string_literals;
        draw_text("Pressed: "s + ((MouseIsPressed) ? "true"s : "false"s), 5, 0);
    }
    return 0;
}
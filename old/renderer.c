#include "renderer.h"
#include "platform_sdl.h"

void renderer_draw(uint32_t *fb)
{
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            uint8_t r = x;
            uint8_t g = y;
            uint8_t b = 0;
            fb[y * SCREEN_WIDTH + x] =
                (0xFF << 24) | (r << 16) | (g << 8) | b;
        }
    }
}

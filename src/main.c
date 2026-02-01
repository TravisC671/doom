#include <stdint.h>
#include <stdbool.h>
#include "platform_sdl.h"
#include "renderer.h"

static uint32_t framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    if (!platform_init())
        return 1;

    while (platform_poll())
    {
        renderer_draw(framebuffer);
        platform_present(framebuffer);
        platform_sleep(16); // ~60 FPS
    }

    platform_shutdown();
    return 0;
}

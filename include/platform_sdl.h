#pragma once
#include <stdint.h>
#include <stdbool.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 120

bool platform_init(void);
void platform_shutdown(void);
bool platform_poll(void);
void platform_present(uint32_t *framebuffer);
void platform_sleep(uint32_t ms);
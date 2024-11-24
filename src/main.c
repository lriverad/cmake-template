#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <stdbool.h>
#include <stdio.h>

bool is_running = true;

void mainloop(void) {
#ifdef __EMSCRIPTEN__
    if (!is_running) {
        // Reload app
    }
#endif
}

int main(int argc, char **argv) {
    printf("Hello, C!\n");

#ifdef __EMSCRIPTEN__
    printf("Hello, Emscripten!\n");
#endif

#ifdef NDEBUG
    printf("Running release build...\n");
#elif defined(DEBUG)
    printf("Running debug build...\n");
#endif

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(mainloop, 60, 1);
#else
    while (is_running) {
        mainloop();
    }
#endif

    return 0;
}

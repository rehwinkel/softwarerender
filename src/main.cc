#include <MiniFB.h>
#include <random>

int main(int argc, char const *argv[]) {
    struct mfb_window *window =
        mfb_open_ex("my display", 800, 600, WF_RESIZABLE);
    if (!window) return 0;

    uint32_t *buffer = new uint32_t[800 * 600];

    do {
        int state;

        for (size_t i = 0; i < 800 * 100; i++) {
            buffer[i] = 0xffff0000;
        }

        for (size_t i = 800 * 100; i < 800 * 200; i++) {
            buffer[i] = 0xffff8800;
        }

        for (size_t i = 800 * 200; i < 800 * 300; i++) {
            buffer[i] = 0xffffff00;
        }

        for (size_t i = 800 * 300; i < 800 * 400; i++) {
            buffer[i] = 0xff008000;
        }

        for (size_t i = 800 * 400; i < 800 * 500; i++) {
            buffer[i] = 0xff0000ff;
        }

        for (size_t i = 800 * 500; i < 800 * 600; i++) {
            buffer[i] = 0xff800080;
        }

        state = mfb_update_ex(window, buffer, 800, 600);

        if (state < 0) {
            window = NULL;
            break;
        }
    } while (mfb_wait_sync(window));
    return 0;
}

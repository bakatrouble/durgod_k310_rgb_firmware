#include "modules/KeyboardMain.h"

KeyboardMain kbd;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
int main() {
    kbd.init();
    while (true) {
        kbd.loop();
    }
}
#pragma clang diagnostic pop

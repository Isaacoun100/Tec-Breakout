#include "logic/example_logic.h"
#include "gui/primitive_window.h"
int main() {
    auto *primative = new PrimitiveWindow();
    primative->run();
    delete primative;
    return 0;
}
#include "gui/primitive_window.h"


int main() {
    auto v = new PrimitiveWindow();
    v->initWindow();
    v->run();
    delete v;
}
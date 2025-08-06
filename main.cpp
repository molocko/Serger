#include <iostream>
#include <fmt/core.h>
#include "Config.h"
#include "job.h"

int main() {
    Config cfg {"serger.cfg"};
    job::launch(cfg);

    getchar();
    return 0;
}

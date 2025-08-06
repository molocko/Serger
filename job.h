#pragma once
#include "Config.h"

namespace job {
    void launch(Config cfg);
    unsigned short choose(std::vector<std::string> vars);
    void clear();
}

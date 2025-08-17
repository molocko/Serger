#pragma once
#include <map>
#include <string>

namespace Values {
    inline std::map<std::string,bool>ConfigValues {
            {"first_time",true},
            {"auto_eula",false},
            {"use_colors",false},
            {"use_russifikator", false}
    };

    enum class Stage {
        none,
        main,
        settings,
        explorer,
        createServer
    };
}

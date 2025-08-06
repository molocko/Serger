#pragma once
#include <map>
#include <string>

namespace Values {
    std::map<std::string,bool>ConfigValues {
            {"first_time",true},
            {"auto_eula",false},
            {"use_colors",false}
    };

    enum class Stage {
        none,
        main,
        settings,
        manager
    };
}

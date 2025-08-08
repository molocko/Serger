#include <filesystem>
#include <fmt/core.h>
#include <iostream>
#include <fstream>
#include "Config.h"
#include "Values.h"
// ================= PUBLIC =================
Config::Config(std::string file) {

    initConfig(file);
    Config::fileSetter(file);
}

YAML::Node Config::getNode() {
    return YAML::LoadFile(Config::fileGetter());
}

bool Config::getValue(std::string key) {
    return Config::getNode()[key].as<bool>();
}

void Config::setValue(std::string key, bool value) {
    YAML::Node config = Config::getNode();
    config[key] = value;

    std::ofstream fout(Config::fileGetter());
    fout<<config;
    fout.flush();
    fout.close();
}


// ================= PRIVATE =================
void Config::initConfig(std::string file) {
    std::ofstream (file,std::ios::app).close();
    // fout_temp.close();
    YAML::Node config = YAML::LoadFile(file);


    for (const auto& [name,value] : Values::ConfigValues) {
        if (!config[name]) {
            config[name] = value;
        }
    }
    std::vector<std::string>vec;
    for (auto it = config.begin(); it!=config.end(); ++it) {

            auto key = it->first;
            std::string temp_key = key.as<std::string>();
            if (!Values::ConfigValues.contains(temp_key)) {
                vec.push_back(temp_key);
                // config.remove(temp_key);
            }

    }

    for (std::string key : vec) {
        config.remove(key);
    }




    std::ofstream fout(file);
    fout<<config;
    fout.flush();
    fout.close();

}






#pragma once
#include <yaml-cpp/yaml.h>

class Config{
public:
    Config(std::string file);
    bool getValue(std::string key);
    void setValue(std::string key, bool value);
    YAML::Node getNode();

    // void edit(ConfigValues key, std::string value);

private:
    std::string fileInstance;
    void fileSetter(std::string file) {
        fileInstance = file;
    }
    std::string fileGetter() {
        return fileInstance;
    }

    void initConfig(std::string file);
    void checkAllCfgErrors();
    void makeIfNotExist(std::string file);
    void write();

};

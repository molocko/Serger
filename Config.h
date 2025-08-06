#pragma once

class Config{
public:
    Config(std::string file);
    void edit(ConfigValues key, std::string value);

private:
    void checkAllCfgErrors();
    void makeIfNotExist(std::string file);
    void write();

};

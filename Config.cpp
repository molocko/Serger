#include <filesystem>
#include <yaml-cpp/yaml.h>
#include <windows.h>
#include "Enums.cpp"
#include <fmt/core.h>
#include <iostream>
#include <fstream>
#include "Config.h"
// ================= PUBLIC =================
Config::Config(std::string file) {
    if (std::filesystem::exists(file.data())) {
        try {
            YAML::Node fgt = YAML::LoadFile(file);
            // checkAllCfgErrors();
            std::cout<<fgt["sosl"]<<std::endl;
            std::cout<<"sss"<<std::endl;


        } catch(const std::exception& e) {
            std::cout<<e.what()<<std::endl;
        }
    } else {
        std::cout<<"File does not exist"<<std::endl;
        makeIfNotExist(file);
    }
}

// ================= PRIVATE =================
void makeIfNotExist(std::string file) {
    std::ofstream fout(file);
    fout<<"A: sosal\nB: POPA";
    fout.flush();
    fout.close();
}





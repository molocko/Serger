#pragma once
#include <string>
#include <yaml-cpp/yaml.h>

class Server{
public:
    Server(std::string, std::string, std::string);

    void setName(std::string);
    std::string getName();

    void setCorePath(std::string);
    std::string getCorePath();

    void setArgs(std::string);
    std::string getArgs();

    void editOwnConfig(std::string, YAML::Node);

    void ownConfigInit(std::string, Server);

    

private:
    std::string name;
    std::string corePath;
    std::string args;

};
#pragma once
#include <vector>
#include <string>
#include <yaml-cpp/yaml.h>
#include <fstream>

class Manager{
public:
    Manager();
    std::vector<std::string> getServersList();
    YAML::Node getNode();
    std::fstream getFile();
    void writeToFile(YAML::Node);
    void addServer(std::string);


};

// namespace Manager{
//     void init();
//     std::vector<std::string> getServersList();
// }

// struct Server;
// class Manager{
//     public:
//         Manager();
//         std::vector<Server> getServerList();
//         void createServer();
//         void deleteServer();
//     private:
//         struct Server{
//             std::string name;
//             std::string core_name;
//         };
// };
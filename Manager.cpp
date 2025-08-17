#include "string"
#include "iostream"
#include "fstream"
#include "Manager.h"
#include "Fimager.h"
#include "yaml-cpp/yaml.h"
#include "fmt/core.h"



Manager::Manager(){
    fm::Folder::Create("Servers");
    if(!fm::File::isExist(".\\Servers\\manager")) {
        fm::File::Create("manager");
        // fm::File::Move("manager", ".\\Servers\\manager");
        fm::File::Move("manager", "./Servers/manager");

    }
    // getServersList();


    // CHECK IF EXISTS FOLDER AND INIT FILE
}

// Manager::Manager(){
//     fm::Folder::Create("Servers");
//     if(!fm::File::isExist(".\\Servers\\manager")) {
//         fm::File::Create("manager");
//         fm::File::Move("manager", ".\\Servers\\manager");

//     }
//     getServersList();


//     // CHECK IF EXISTS FOLDER AND INIT FILE
// }

// ================= PUBLIC =================

std::vector<std::string> Manager::getServersList(){
    YAML::Node cfg = getNode();
    std::vector<std::string> list;

    // cfg["NAME"].push_back("SOSAL");
    // cfg["NAME"].push_back("LASOS");

    // if(cfg.IsSequence()){
    //     fmt::print("CHCHCHCHCHCHCH");
    // } else {fmt::print("IDDDKKK");}

    // fmt::print("peni\n{}\n",cfg["NAME"][0].as<std::string>());
    // for(auto it = cfg.begin();it!=cfg.end();++it){
    //     i++;
    //     // auto key = it->first.as<std::string>();
    //     // auto value = it->second[0].as<std::string>();

    //     // fmt::print("{} - {}\n",key,value);
    //     std::cout<<it->first.as<std::string>()<<" - "<<i<<std::endl;
    // }

    for(int i = 0; i < cfg["NAME"].size();i++){
        // fmt::print("{}\n",cfg["NAME"][i].as<std::string>());
        list.push_back(cfg["NAME"][i].as<std::string>());
    }
    // fmt::print("{}\n",cfg["NAME"][0].as<std::string>());

    return list;
}

YAML::Node Manager::getNode(){
    return YAML::LoadFile(".\\Servers\\manager");
}

std::fstream Manager::getFile(){
    return std::fstream{".\\Servers\\manager"};
}

void Manager::writeToFile(YAML::Node config){
    std::fstream fout = getFile();
    fout<<config;
    fout.flush();
    fout.close();
}

// void idk(){
//     YAML::Node config = YAML::LoadFile(".\\Servers\\manager");
//     if(!config){
//         fmt::print("ERRRRRR");
//         exit(1);
//     }
//     std::ofstream fout {".\\Servers\\manager"};

//     fout<<std::string{"SOSAL"};



//     fout.close();
    
    
// }

void Manager::addServer(std::string name){
    YAML::Node config = getNode();
    config["NAME"].push_back(name);
    writeToFile(config);
}

// ================= PRIVATE =================


#include <fstream>
#include "ServerClass.h"

Server::Server(std::string name, std::string path, std::string args = " "){
    this->name = name;
    this->corePath = path;
    this->args = args;
}

void Server::editOwnConfig(std::string name, YAML::Node config){
    std::ofstream fout {"./Servers/"+name+"/SERGERCONFIG"};
    fout<<config;
    fout.flush();
    fout.close();
}

void Server::ownConfigInit(std::string name, Server s){
    YAML::Node config = YAML::LoadFile("./Servers/"+name+"/SERGERCONFIG");
    config["name"] = s.getName();
    config["core"] = s.getCorePath();
    config["args"] = s.getArgs();
    editOwnConfig(name, config);
}

std::string Server::getName(){
    return this->name;
}

void Server::setName(std::string name){
    this->name = name;
}

std::string Server::getCorePath(){
    return this->corePath;
}

void Server::setCorePath(std::string corePath){
    this->corePath = corePath;
}

std::string Server::getArgs(){
    return this->args;
}

void Server::setArgs(std::string args){
    this->args = args;
}





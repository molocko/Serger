#include <fmt/color.h>
#include <windows.h>
#include <filesystem>
#include <iostream>
#include "Job.h"
#include "Fimager.h"
#include "Values.h"
#include "Manager.h"
#include "ServerClass.h"

using fmt::print;
using us = unsigned short;

Values::Stage stage = Values::Stage::none;
Config *config = nullptr;
bool isRunning = true;
Manager man;

void first_time();
void main_menu();
void settings();
void explorer();
void createNewServer();

void launch(Config *cfg) {
    config = cfg;
    first_time();
    stage = Values::Stage::main;
    while(isRunning){
        if(stage == Values::Stage::main){
            main_menu();
        }
        else if(stage == Values::Stage::settings){
            settings();
        }
        else if(stage == Values::Stage::explorer){
            explorer();
        }
        else if(stage == Values::Stage::createServer){
            createNewServer();
        }
    }



}

void choose(std::string text, std::unordered_map<std::string, void(*)()> vars) {

    short i;
    std::vector<void(*)()> funcs;
    while (true) {
        clear();
        print("{}\n",text);
        i = 1;
        for(std::pair<std::string, void(*)()> var : vars){
            if(std::string {" "} == var.first){
                print("\n");
            } else {
                funcs.push_back(var.second);
                print("[{}] {}\n",i++,var.first);
            }
        }

        auto temp = std::cin.get();
        if(isdigit(temp)){
            unsigned short val = temp-48;

            if(val>0 && val<=i-1){
                (*funcs[val-1])();
                return;
            }

        }
        clear();
    }
}

void clear() {
    system("cls");
}

// ================= STAGES =================
void first_time(){
    if (config->getValue("first_time")) {
        print("Hi\n"
                   "This program aims to simplify interaction with the Minecraft servers you host\n"
                   "Enjoy <3\n"
                   "(Press Enter)");
        getchar();
        clear();
        config->setValue("first_time", false);
        return;
        // !!!!!LATER!!!!!
        // print("Did ur console support ASCII colors? (check below)\n");
        // print(fmt::fg(fmt::color::aqua) | fmt::emphasis::blink,"Aqua blinking text\n");
        // Sleep(1500);
        // unsigned short sel = choose(std::vector<std::string>{"Yes","No"});
        // if (sel == 1) { 
        //     config->setValue("use_colors",true);
        // }
    }
}

void main_menu(){
    choose("SAMPLE TEXT", std::unordered_map<std::string, void(*)()>{
        {"Manage servers",[]{stage=Values::Stage::explorer;}},
        {"Settings",[]{stage = Values::Stage::settings;}},
        {" ",[]{}},
        {"Exit",[]{isRunning = false;}}
    } );
}

void settings(){
    const std::string text = fmt::format("Auto eula = {}\n"
                                    "Use (ASCII) colors = {}\n"
                                    "Set up Russifikator = {}\n"
                                    ,config->getValue("auto_eula")
                                    ,config->getValue("use_colors")
                                    ,config->getValue("use_russifikator")
                                );

    choose(text, std::unordered_map<std::string, void(*)()>{
        {"Toggle `Auto Eula`",[]{config->setValue("auto_eula",!config->getValue("auto_eula"));}},
        {"Toggle `Use colors`",[]{config->setValue("use_colors",!config->getValue("use_colors"));}},
        {"Toggle `Russifikator`",[]{config->setValue("use_russifikator",!config->getValue("use_russifikator"));}},
        {" ",[]{}},
        {"Back",[]{stage = Values::Stage::main;}}

    });
}

void explorer(){
    man = Manager();
    std::vector list = man.getServersList();
    if(!list.size()){
        choose("Looks empty\nU probably wanna create server, isnt it?",std::unordered_map<std::string, void(*)()>{
            {"Yes, create server", []{stage=Values::Stage::createServer;}},
            {"No, back to main menu", []{stage=Values::Stage::main;}}

        });
        return;
    } else {

        for(std::string lists : list){
            fmt::print("{}\n",lists);
        }
    }
    isRunning = false;
    

}

void createNewServer(){
    std::string name, corePath, args;

    // СДЕЛАТЬ ПРОВЕРКУ НА СУЩЕСТВУЮЩЕЕ ИМЯ
    fmt::print("Enter server name (w/o space)\n");
    getchar();
    std::getline(std::cin,name);

    man.getNode()["NAME"];

    fmt::print("Enter absolute path to server's core in any directory (it willbe copy to program's folder)\n"
        "Example - `C:/Users/John/Desktop/core.jar`\n"
        "File MUST end at .jar and be careful to use '/' symbol, NOT '\\'\n"
        "(Also u can just Drag N Drop server's jar to this window)\n");
    std::getline(std::cin,corePath);

    fmt::print("If u know u do, u can enter here arguments for server's core\n"
                "If not - just skip this step by press Enter\n");
    std::getline(std::cin,args);

    
    fmt::print("Wait few seconds\nIll get ready ur server files\n");
    fm::Folder::Create("./Servers/"+name);
    fm::File::Create("./Servers/"+name+"/SERGERCONFIG");
    // fm::File::Copy(corePath, std::filesystem::current_path().string()+"\\Servers\\"+name+"\\"+std::filesystem::path{corePath}.filename().string());
    fm::File::Copy(corePath, "./Servers/"+name+"/"+std::filesystem::path{corePath}.filename().string());
    
    Server s = Server(name,"./Servers/"+name+"/"+std::filesystem::path{corePath}.filename().string(),args);
    s.ownConfigInit(name, s);
    man.addServer(name);


    
    

    isRunning = false;
}


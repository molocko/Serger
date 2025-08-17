#include <iostream>
#include <fmt/core.h>
#include <filesystem>
#include <windows.h>
// #include <libloaderapi.h>
#include "Config.h"
#include "Job.h"
#include "Fimager.h"

int main() {
    char buffer[512];
    GetModuleFileNameA(NULL, buffer, 512);
    buffer[511] = '\0';
    // fmt::print("{}\n", std::filesystem::current_path().string());
    // std::string temp (buffer);
    // try{
    std::filesystem::current_path(std::filesystem::path {buffer}.parent_path());

    // } catch(std::exception *e){
    //     fmt::print("{}",e->what());
    //     return 0;
    // }
    // GetCurrentDirectoryA(512, buffer);
    // fmt::print("{}\n", std::filesystem::current_path().string());
    // SetCurrentDirectoryA(buffer);
    // fmt::print("{}\n", std::filesystem::current_path().string());
    // getchar();
    // getchar();
    // сделать чтобы файлы создавались в каталоге с exe
    Config cfg {"serger.cfg"};
    launch(&cfg);
    // clear();
    



    

    return 0;
}

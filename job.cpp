#include <fmt/color.h>
#include <windows.h>
#include "job.h"

#include <iostream>

#include "Values.h"

Values::Stage stage = Values::Stage::none;

void job::launch(Config cfg) {
    if (cfg.getValue("first_time")) {
        fmt::print("Hi\n"
                   "This program aims to simplify interaction with the Minecraft servers you host\n"
                   "Enjoy <3\n"
                   "(Press Enter)");
        getchar();
        clear();
        // cfg.setValue("first_time", false);
        fmt::print("Did ur console support ASCII colors? (check below)\n");
        fmt::print(fmt::fg(fmt::color::aqua) | fmt::emphasis::blink,"Aqua blinking text\n");
        Sleep(2000);
        if (choose(std::vector<std::string>{"Yes","No"}) == 1) { // не работает вроде
            cfg.setValue("use_colors",true);
        }
    }
    stage = Values::Stage::main;


    // MAIN MENU ETC..








}

unsigned short job::choose(std::vector<std::string> vars) {
    int i = 1;
    for (std::string var : vars) {
        fmt::print("[{}] {}\n",i++,var);
    }
    while (true) {
        auto val = std::cin.get();
        if (isdigit(val)) {
            std::cout<<"return "<<val<<std::endl;
            return val;
        }
    }
}

void job::clear() {
    system("cls");
}


#include "Fimager.h"
#include <windows.h>
#include <fmt/core.h>
#include <Shlwapi.h>

// ================= FILE =================
void fm::File::Create(std::string name){
    HANDLE hFile = CreateFileA(name.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    CloseHandle(hFile);
}

void fm::File::Delete(std::string name){
    DeleteFileA(name.c_str());
}

// fm::File::Move("SOSAL",".\\a\\SOSAL");
void fm::File::Move(std::string name, std::string to){
    MoveFileA(name.c_str(), to.c_str());
}

bool fm::File::isExist(std::string name){
    return PathFileExistsA(name.c_str());
}

void fm::File::Copy(std::string from, std::string to){
    if(!CopyFileA(from.c_str(),to.c_str(),false)){
        fmt::print("{}\n",GetLastError());
    }
}

// ================= FOLDER =================
void fm::Folder::Create(std::string name){
    CreateDirectoryA(name.c_str(), nullptr);
}

void fm::Folder::Delete(std::string name){
    RemoveDirectoryA(name.c_str());
}

// fm::File::Move("SOSAL",".\\a\\SOSAL");
void fm::Folder::Move(std::string name, std::string to){
    MoveFileA(name.c_str(), to.c_str());
}

bool fm::Folder::isExist(std::string name){
    return PathFileExistsA(name.c_str());
}
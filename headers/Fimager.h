#pragma once
#include <string>

namespace fm{
    namespace File{
        void Create(std::string);
        void Delete(std::string);
        void Move(std::string, std::string);
        bool isExist(std::string);
        void Copy(std::string, std::string);
    }

    namespace Folder{
        void Create(std::string);
        void Delete(std::string);
        void Move(std::string, std::string);
        bool isExist(std::string);
    } 
    
}
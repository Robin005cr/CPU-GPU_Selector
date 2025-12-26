/*
* project   : https://github.com/Robin005cr/CPU-GPU_Selector
* file name : fileGuard.hpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/

#pragma once

#include <cstdio>
#include <dirent.h>

class FileGuard {
public:
    
    explicit FileGuard(FILE* filePtr) : filePtr_(filePtr) {}

    ~FileGuard() {
        if (filePtr_) {
            std::fclose(filePtr_);
        }
    }

    operator FILE*() const {
        return filePtr_;
    }

    FILE* get() const {
        return filePtr_;
    }

    bool isValid() const {
        return filePtr_ != nullptr;
    }

    FILE* filePtr_;

    private:
    // Disable copy semantics
    FileGuard(const FileGuard&) = delete;  
    FileGuard& operator=(const FileGuard&) = delete;

    // Enable move semantics
    FileGuard(FileGuard&& ) = delete;
    FileGuard& operator=(FileGuard&& ) = delete;
};

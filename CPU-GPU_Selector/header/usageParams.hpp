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

#include <cstdint>

struct usageParams
{
    double cycleTime = 0.0;               // Time per CPU cycle in seconds
    uint32_t pidRAM = 0;                // Process ID for RAM monitoring
    int64_t totalRAM = 0;              // Total RAM in MB
    uint32_t numCPUcores = 0;          // Number of CPU cores   
    uint64_t processCPUtime = 0;   // CPU cycles used by the process
    uint64_t totalCPUtime = 0;     // Total CPU cycles  
    double cycleEnd = 0.0;              // End time for CPU cycle measurement
    double processCPUusage = 0.0;       // CPU usage percentage of the process
    
    usageParams() = default;



};

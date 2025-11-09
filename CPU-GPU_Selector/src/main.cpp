/*
* project   : https://github.com/Robin005cr/CPU-GPU_Selector
* file name : main.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/
#include <iostream>
using namespace std;

int main()
{
    // Array of standard resolutions (length x breadth)
    const int resolutions[10][2] = 
    {
        {640, 480},     // VGA
        {800, 600},     // SVGA
        {1024, 768},    // XGA
        {1280, 720},    // HD
        {1280, 1024},   // SXGA
        {1366, 768},    // WXGA
        {1600, 900},    // HD+
        {1920, 1080},   // Full HD
        {2560, 1440},   // QHD
        {3840, 2160}    // 4K UHD
    };

    // Display resolution options
    cout << "Select a resolution:\n";
    for (int i = 0; i < 10; ++i)
    {
        cout << i + 1 << ". " << resolutions[i][0] << " x " << resolutions[i][1] << endl;
    }

    // Get user's choice
    uint16_t choice;
    cout << "Enter the number corresponding to your choice: ";
    cin >> choice;

    // Validate choice
    if (choice < 1 || choice > 10) 
    {
        cout << "Invalid choice. Please run the program again and select a valid option." << endl;
        return 1;
    }

    // Set selected resolution
    uint16_t RESOLUTION_LENGTH = resolutions[choice - 1][0];
    uint16_t RESOLUTION_BREADTH = resolutions[choice - 1][1];

    // Input variables
    double refreshRate;           // Refresh rate in Hz
    double clockSpeed;            // CPU clock speed in GHz
    double avgInstructionsPerCycle; // Average instructions per CPU cycle
    long long totalInstructions;  // Total instructions to execute

    // Taking user inputs
    cout << "Enter the CPU configurations" << endl;
    cout << "****************************" << endl;
    cout << "Enter the CPU clock speed (GHz): ";
    cin >> clockSpeed;
    cout << "Enter the average instructions per cycle: ";
    cin >> avgInstructionsPerCycle;
    cout << "Enter the training task configurations" << endl;
    cout << "**************************************" << endl;
    cout << "Enter the refresh rate (Hz): ";
    cin >> refreshRate;
    cout << "Enter the total instructions to execute: ";
    cin >> totalInstructions;

    // Ensure all inputs are positive
    if (refreshRate <= 0 || clockSpeed <= 0 || avgInstructionsPerCycle <= 0 || totalInstructions <= 0) {
        cout << "All input values must be positive." << endl;
        return 1;
    }

    // Calculate the total time needed to execute the instructions
    double clockCyclesPerSecond = clockSpeed * 1e9; // Convert GHz to Hz (cycles per second)
    double instructionsPerSecondCPU = clockCyclesPerSecond * avgInstructionsPerCycle;
    double executionTime = totalInstructions / instructionsPerSecondCPU; // Time in seconds
    double instructionsPerSecondTask = RESOLUTION_LENGTH * RESOLUTION_BREADTH * refreshRate * totalInstructions;

    if (instructionsPerSecondTask > instructionsPerSecondCPU)
    {
        cout << "CPU cannot handle the training" << endl;
    }
    else
    {
        cout << "CPU can handle the training." << endl;
    }
    // Display results
    cout << "\nSelected Resolution: " << RESOLUTION_LENGTH << " x " << RESOLUTION_BREADTH << endl;
    cout << "Instructions Per Second CPU :" << instructionsPerSecondCPU << endl;
    cout << "Instructions Per Second Task :" << instructionsPerSecondTask << endl;
    cout << "Execution time to complete all instructions: " << executionTime << " seconds" << endl;

    return 0;
}

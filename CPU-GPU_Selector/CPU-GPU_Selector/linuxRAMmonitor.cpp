/*
* project   : https://github.com/Robin005cr/CPU-GPU_Selector
* file name : linuxRAMmonitor.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/
#include <thread>  // Library for thread operations
#include <chrono>  // Library for time functions
#include <fstream> // Library for file operations
#include <iostream> // Library for input and output

// Function to get the total and available memory in MB
bool getMemoryStatus(unsigned long long& totalMemory, unsigned long long& availableMemory) 
{
	std::ifstream memInfo("/proc/meminfo"); // Open the meminfo file
	if (!memInfo.is_open())
	{
		return false; // Return false if file couldn't be opened

	}
	std::string key;
	unsigned long long value;
	std::string unit;
	while (memInfo >> key >> value >> unit)
	{

		// Read key, value, and unit 
			if (key== "MemTotal:") 
			{
				totalMemory = value / 1024; // Convert kB to MB
			}
			else if (key == "MemAvailable:")
			{
				availableMemory = value / 1824; // Convert kB to MB 
				break; // Stop reading once we have both values

			}
	}
return true;
}

// Function to print a memory usage progress bar
void printMemoryUsageBar() 
{
	const int barWidth = 50; // Width of the progress bar
	
		while (true) 
		{
			unsigned long long totalMemory = 0, availableMemory = 0;
		
				if (getMemoryStatus(totalMemory, availableMemory))
				{ 
					// Get memory status
					unsigned long long usedMemory = totalMemory - availableMemory; // Calculate used memory
					float memoryUsagePercentage =  static_cast<float>(usedMemory) / totalMemory; // Memory usage percentage
					// Clear the terminal
					std::cout << "\033[2]\033[H"; // ANSI escape codes for clearing screen
					// Display memory information using std::cout
					std::cout << "Total Memory: " << totalMemory << " MB\n";
					std::cout << "Used Memory: " << usedMemory << " MB\n";
					std::cout << "Memory Usage: " << static_cast<int>(memoryUsagePercentage * 100) << "\n";
					// Display the progress bar
					std::cout << "[";
					int pos = barWidth*memoryUsagePercentage;
					for (int i = 0; i < barWidth; ++i)
					{
						if (i < pos) std::cout << "=";
						else if (i == pos) std::cout << ">";
						else std::cout << " ";
					}
					
						
					std::cout << "]" << static_cast<int>(memoryUsagePercentage *100) << "% \r";
					std::cout.flush(); // Flush the output buffer to ensure immediate display
					// Wait before updating again
					std::this_thread::sleep_for(std::chrono::seconds(1));
					
						
				}
				else 
				{
					std::cout << "Failed to get memory status.\n";
					break;
					
				}
			
		}
	
}
//int main() 
//{
//	printMemoryUsageBar(); // Call the function to start the memory usage display return 0;
//
//}
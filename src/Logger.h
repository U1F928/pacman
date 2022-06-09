#pragma once
#include <string>
#include <fstream>
#define LOG_FILE_NAME  "logFile.txt"
#define log(message)  														\
{ 																			\
	std::ofstream logFile(LOG_FILE_NAME, std::ios_base::app);  				\
	logFile << message; 													\
	logFile.close(); 														\
}

#define startLog()  																		\
{ 																							\
	std::ofstream logFile(LOG_FILE_NAME, std::ios_base::app);  								\
	logFile << "\n\n> " << __FILE__ << ":" << __LINE__ << " in " << __func__ << "() \n";	\
	logFile.close(); 																		\
}

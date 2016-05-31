// Auteur K. Steiner  - 09-2012 - version initiale
// Auteur J. Dominski - 10-2012 - test file validity and exceptions
// Auteur J. Dominski - 10-2012 - add process(line), toString(), printOut()
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

#include "ConfigFile.h"
namespace ONIGIRIX_GUI {
	ConfigFile::ConfigFile(const std::string& fileName) {
		std::ifstream file;
		file.open(fileName.c_str());
		if (!file) {
			throw "[ConfigFile] Error in openening file " + fileName;
		}
		try {
			std::string lineread;
			while (std::getline(file, lineread)) {
				process(lineread);
			}
			file.close();
		}
		catch (std::string e) {
			file.close();
			throw e;
		}
	}

	ConfigFile::~ConfigFile() {}

	void ConfigFile::printOut(std::string path) {
		/*  std::ofstream outputFile();
		  outputFile.open(path.c_str());*/
		std::ofstream outputFile(path.c_str());
		if (outputFile.is_open())
		{
			outputFile << toString() << std::endl;
		}
		outputFile.close();
	}

	std::string ConfigFile::toString() {
		std::map<std::string, std::string>::iterator iter;
		std::string strToReturn; //This is no longer on the heap

		for (iter = configMap.begin(); iter != configMap.end(); ++iter) {
			strToReturn.append(iter->first); //Not a method call
			strToReturn.append("=");
			strToReturn.append(iter->second);
			strToReturn.append("\n");
			//....
			// Make sure you don't modify table here or the iterators will not work as you expect
		}
		//...
		return strToReturn;
	}

	void ConfigFile::process(const std::string& lineread) {
		//cout << "Process: "<< lineread <<endl;
		size_t commentPosition = lineread.find('#', 0);
		if (commentPosition != 0) {
			size_t spacePosition = lineread.find(' ', 0);
			if (spacePosition != std::string::npos) {
				std::cerr << "ConfigFile object do not support character ' ' at position " << spacePosition << " in line '" << lineread << std::endl;
			}
			size_t equalPosition = lineread.find('=', 1);
			if (equalPosition == std::string::npos) {
				std::cerr << "Line without '=' " << lineread << std::endl;
			}
			else {
				std::string key = lineread.substr(0, equalPosition);
				std::string value = lineread.substr(equalPosition + 1, lineread.length());
				std::map<std::string, std::string>::const_iterator val = configMap.find(key);
				if (val != configMap.end()) {
					configMap.erase(key);
				}
				configMap.insert(std::pair<std::string, std::string>(key, value));
			}
		}

	}
}


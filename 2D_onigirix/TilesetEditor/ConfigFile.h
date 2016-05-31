// Auteur K. Steiner  - 09-2012 - version initiale
// Auteur J. Dominski - 10-2012 - test file validity and exceptions
// Auteur J. Dominski - 10-2012 - add process(line), toString(), printOut()
#ifndef TEST_CONFIGFILE_H_INCLUDED
#define TEST_CONFIGFILE_H_INCLUDED

#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

namespace ONIGIRIX_GUI {
	class ConfigFile {

	public:
		ConfigFile(const std::string& filename);
		~ConfigFile();

		template<typename T> T get(const std::string& key) const {
			std::map<std::string, std::string>::const_iterator val = configMap.find(key);
			if (val != configMap.end()) {
				T out;
				std::istringstream iss(val->second);
				iss >> out;
				//std::cout << "\t" << key << "=" << out << std::endl;
				return out;
			}
			else {
				std::string msg = "[Phys input] Key missing from file, key=";
				throw msg + key;
			}
		}

		template<> bool get<bool>(const std::string& key) const {
			std::istringstream iss(configMap.find(key)->second);
			bool result(false);
			iss >> result;
			if (iss.fail()) {
				iss.clear();
				iss >> std::boolalpha >> result;
			}
			return result;
		}

		void process(const std::string& lineread);

		std::string toString();

		void printOut(std::string path);

	private:
		std::map<std::string, std::string> configMap;
	};

}

#endif //TEST_CONFIGFILE_H_INCLUDED
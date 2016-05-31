#pragma once
#include<iostream>
#include <fstream>
#include <streambuf>
#include<string>

inline std::string file2string(std::string file) {
	try {
		std::ifstream t(file);
		std::string str;

		t.seekg(0, std::ios::end);
		str.reserve(t.tellg());
		t.seekg(0, std::ios::beg);

		str.assign((std::istreambuf_iterator<char>(t)),
			std::istreambuf_iterator<char>());
		return str;
	}
	catch (...) {
		throw("Error occured opening the file (in file2string)");
		return "";
	}
}
#pragma once

int line = 0;

rlutil::setColor(rlutil::WHITE);

std::cout << "STARTING GENERATION" << std::endl;
std::cout << "output : " << OUTPUTDIRECTORY;
std::cout << "\n\n\t ~~~ FUNCTIONS ~~~ \n\n" << std::endl;

line += 7;

int i = 0;
for (auto & fct : FUNCTIONS) {

	rlutil::locate(1, line);

	int percent = ((double)i / (double)FUNCTIONS.size()) * 100.0;
	rlutil::setColor(rlutil::RED);
	std::cout << "\r" << rlutli::fillString(std::to_string(percent) + "%", 5);
	rlutil::setColor(rlutil::GREY);
	std::cout << " completed : [";
	std::cout << rlutli::fillString(std::string(percent / 5, '#'), 20) << "]";

	std::cout << "\n\n\t Current : " << fct.nom << std::endl;

	Sleep(1000);

	i++;
}

rlutil::locate(1, line);

int percent = ((double)i / (double)FUNCTIONS.size()) * 100.0;
rlutil::setColor(rlutil::RED);
std::cout << "\r" << rlutli::fillString(std::to_string(percent) + "%", 5);
rlutil::setColor(rlutil::GREY);
std::cout << " completed : [";
std::cout << rlutli::fillString(std::string(percent / 5, '#'), 20) << "]";


printf("\n\n\r                                           ");
rlutil::setColor(rlutil::GREEN);
std::cout << "\r\t FINISHED" << std::endl;
rlutil::setColor(rlutil::WHITE);

std::cout << "\n\n\t ~~~ OPERATORS ~~~ \n\n" << std::endl;


//create MACROS

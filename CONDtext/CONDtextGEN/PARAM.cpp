#include"PARAM.h"

std::vector<f_struct>		FUNCTIONS =			std::vector<f_struct>({ f_struct("sin"),f_struct("cos"),f_struct("pow"),f_struct("display"),f_struct("change") });
std::vector<f_struct>		MEMBERS=			std::vector<f_struct>({ f_struct("size"),f_struct("pop_back") });
std::vector<std::string>	OPERATORS =			std::vector<std::string>({"+","-","*","/","^","&&","||","|","&"});
std::string					OUTPUTDIRECTORY =	"Z:\\cpp\\visual_studio\\GROUGROUengine\\CONDtext\\GEN_ANY\\";
std::string					ACCESS_F_ACCESS =	"GEN_ANY\\";
std::string					ID_NAME =			"ANY_class_"; // a random name normally never used !
std::string					NAME_SPACE =		"ANY_FCT";
int							MAX_ARGUMENT =		7;
int							REFERENCES =		3;//1->passage par valeur; 2->passage par référence; 3-> passage par référence et rvalue reference - ATTENTION 3-> plus de temps à générer -

//auto FILLING PARAMETER DO NOT TOUCH AFTER !!!


void finish_param() {
	for (auto m : MEMBERS) {
		m.nom = "CALL_MEMBER_" + m.nom;
		m.name = "ANY_FCT";
		FUNCTIONS.push_back(m);
	}
}


#include <map>
#include <string>
#include "G_inc.h"
#include "Mesure.h"
#include "manga_class.h"

struct data_store{
	std::map<std::string, int> int_data;
	std::map<std::string, double> double_data;
	std::map<std::string, Rectangle*> rect_data;
	std::map<std::string, Fenetre*> fenetre_data;
	std::map<std::string, std::string> string_data;
	std::map<std::string, Scroll*> scroll_data;
	std::map<std::string, Mesure> mesure_data;
	std::map<std::string, DATA_MANGA*> mangas_data;
};
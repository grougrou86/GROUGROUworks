#include <map>
#include <string>
#include <vector>
#include "G_inc.h"
#include "Mesure.h"
#include <boost/any.hpp>


namespace ONIGIRIX_GUI {
	struct data_store {
		std::map<std::string, int> int_data;
		std::map<std::string, double> double_data;
		std::map<std::string, void*> pointer_data;
		std::map<std::string, Rectangle*> rect_data;
		std::map<std::string, Fenetre*> fenetre_data;
		std::map<std::string, std::string> string_data;
		std::map<std::string, Scroll*> scroll_data;
		std::map<std::string, Mesure> mesure_data;
		std::map<std::string, std::vector<const char*>*> const_char_data;
		std::map<std::string, const char*> const_char_2_data;
		std::map<std::string, rebuild_funk> rebuild_funk_data;
		std::map<std::string, boost::any> any_data;
	};
}
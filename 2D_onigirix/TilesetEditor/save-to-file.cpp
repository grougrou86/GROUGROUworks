#include"save-to-file.h"
#include"ConfigFile.h"
#include <iostream>
#include <fstream>
void save_to_file(std::string path, fusion& to_save) {

	std::ofstream myfile;
	myfile.open(path.c_str(), std::fstream::out| std::fstream::trunc);
	myfile << "Y=" << to_save.compo.size() << std::endl;
	myfile << "X=" << to_save.compo[0].size()<<std::endl;
	size_t i(0);
	size_t j(0);
	while (i < to_save.compo.size()) {
		j = 0;
		while (j < to_save.compo[i].size()) {
			myfile << "Full_"<<j<<"_"<<i<<"=" << (int)to_save.compo[i][j].full << std::endl;
			myfile << "Url_" << j << "_" << i << "=" << to_save.compo[i][j].url << std::endl;
			myfile << "X_" << j << "_" << i << "=" << (int)to_save.compo[i][j].x << std::endl;
			myfile << "Y_" << j << "_" << i << "=" << (int)to_save.compo[i][j].y << std::endl;
			j++;
		}
		i++;
	}
	myfile.close();


}
fusion get_path_fusion(std::string inputPath) {

	

	ONIGIRIX_GUI::ConfigFile configFile(inputPath);
	int x = configFile.get<int>("X");
	int y = configFile.get<int>("Y");
	fusion newFUS(x,y);

	int i(0);
	int j(0);
	while (i < y) {
		j = 0;
		while (j < x) {
			std::stringstream sstm;
			sstm << "Full_" << j << "_" << i ;
			newFUS.compo[i][j].full = configFile.get<bool>(sstm.str());
			sstm.str(std::string());
			sstm << "Url_" << j << "_" << i;
			newFUS.compo[i][j].url = configFile.get<std::string>(sstm.str());
			sstm.str(std::string());
			sstm << "X_" << j << "_" << i;
			newFUS.compo[i][j].x = configFile.get<int>(sstm.str());
			sstm.str(std::string());
			sstm << "Y_" << j << "_" << i;
			newFUS.compo[i][j].y = configFile.get<int>(sstm.str());


			j++;
		}
		i++;
	}

	return newFUS;
}
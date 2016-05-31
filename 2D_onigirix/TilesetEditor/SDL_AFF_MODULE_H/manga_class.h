#ifndef MANGA_CLASS_H
#define MANGA_CLASS_H
#include <vector> 
#include <map> 
class scan;
class serie;
class DATA_MANGA{
public:
	std::vector<serie*> series;
	~DATA_MANGA();
};
class serie{
public:
	std::string nom;
	std::string synopsis;
	std::map<double , scan*> scans;
	~serie();
};
class scan{
public:
	std::vector<std::string> img_link;
};

#endif
#pragma once
#include <string>
#include<boost\regex.hpp>
inline std::string retab(std::string s) {
	while (s.find("    ") != std::string::npos) s.replace(s.find("    "), 3, "\t");


	boost::regex ENDSPACE("((?:\t| )+)\n");

	std::string::const_iterator start, end;
	start = s.begin();
	end = s.end();
	boost::match_results<std::string::const_iterator> result;
	boost::smatch match;
	boost::match_flag_type flags = boost::match_default;

	while (regex_search(start, end, match, ENDSPACE , flags))
	{
		std::string var = match[1]; //std::string(what[2].first, what[1].second);
									//std::cout << match. << std::endl;

		auto begin2 = (int)(match[1].first - s.begin()); 
		auto end2 = (int)(match[1].second - s.begin());

		s.erase(begin2, end2 - begin2);

		start = s.begin();
		end = s.end();

		//std::cout << "deleting tab : " << begin2 << "-" << end2 << std::endl;

		flags |= boost::match_prev_avail;
		flags |= boost::match_not_bob;
	}


	return s;
}
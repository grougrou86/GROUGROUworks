#ifndef ETAT_H
#define ETAT_H
#include<string>
#include<vector>
#include"G_inc.h"

#include<iostream>


namespace ONIGIRIX_GUI {
	class etat {
	public:
		etat(std::string nom2, bool active2) :nom(nom2), active(active2) { }
		etat() :nom(""), active(false) {}
		~etat() { }
		std::string nom;
		bool active;
		int user = 0;
		static int total;
	};
	struct etat_imp {
		etat etat;
		int importance;
	};
	struct etat_point_imp {
		etat* etat;
		int importance;
	};
	struct etat_state {
		int state;
		int importance;
	};
	class callback_etat {
	public:
		std::string nom;
		call_funk on_start = NULL;
		call_funk on_while = NULL;
		call_funk on_end = NULL;
		call_funk on_false = NULL;
		callback_etat* copie() const;
	};//car on peux vouloir partager des etant sans les callback XD

	template <typename T>
	class etat_data
	{
	public:
		etat_data(T _data) :nom("default"), data(_data) {}
		etat_data(std::string name, T _data) :nom(name), data(_data) {}
		std::string nom;
		T data;
	};
	/*-----------------------------*/
	template <typename T>
	struct value_indicator {
		std::string nom = "default";
		int importance = 0;
		T old_value;
	};
	template <>
	struct value_indicator<std::string> {
		std::string nom = "default";
		int importance = 0;
		std::string old_value = "none";
	};
	class style_etat_base {
	public:
		bool changed = true;
		bool check_implicite_change = true;//pour le bon fonctionement
		std::string old_nom = "default";
		int old_importance = 0;
		int _nmb = 0;
	};
	template <typename T>
	class style_etat_data : public style_etat_base {
	public:
		style_etat_data(int nmb) : style_etat_base(), Main_data(std::vector < etat_data< T > > {etat_data<T>(T())}), old_value() { _nmb = nmb; }
		style_etat_data(int nmb, T defVal) : style_etat_base(), Main_data(std::vector < etat_data< T > > {etat_data<T>(defVal)}), old_value(defVal) { _nmb = nmb; }
		std::vector<etat_data< T >> Main_data = std::vector < etat_data< T > >{ etat_data<T>(T()) };;
		T old_value;
	};
	template <>
	class style_etat_data<std::string> : public style_etat_base {
	public:
		style_etat_data(int nmb, std::string phr = "none") {
			Main_data = std::vector < etat_data< std::string > >{ etat_data<std::string>(phr) };
			_nmb = nmb;
		}
		std::vector<etat_data< std::string >> Main_data;
		std::string old_value;
	};
	/*-----------------------------*/
	template <typename T>
	bool is_in_datas(std::string nom, std::vector<etat_data<T>> datas) {
		for (auto& dat : datas) {
			if (dat.nom == nom) {
				return true;
			}
		}
		return false;
	}
	template <typename T>
	T best_result(std::vector<etat_point_imp> const_etat, style_etat_data<T> & datasI) {
		std::vector<etat_data<T>> datas =
			datasI.Main_data;
		//std::vector<etat_data<T>> datas =  datasI;

		T data = T();
		bool found = false;
		etat et2;

		//while (found != true ){
		int importance(0);
		/*for (auto& et : etats){
			if ((importance <= et.importance) && et.etat.active && is_in_datas(et.etat.nom,datas)){
				et2 = et.etat;
				importance = et.importance;
			}
			//std::cout << et.etat.nom << "||" << et.importance << std::endl;
		}*/
		for (auto& et : const_etat) {
			if ((importance <= et.importance) && et.etat->active && is_in_datas(et.etat->nom, datas)) {
				et2 = *(et.etat);
				importance = et.importance;
			}
			//std::cout << et.etat->nom << "||" << et.importance << std::endl;
		}
		for (auto& dat : datas) {
			if (dat.nom == et2.nom) {

				data = dat.data;
				//std::cout << dat.nom << ":" << dat.data << std::endl;
			}
		}
		found = true;
		datasI.old_nom = et2.nom;
		datasI.old_importance = importance;
		//}
		return data;
	}


	template <typename T>
	void set_to_best(T data, style_etat_data<T>& save_vec, std::string state_save) {
		bool need_new = true;
		if (save_vec.Main_data.size() != 0) {
			for (auto& coco : save_vec.Main_data) {
				if (coco.nom == state_save) {
					coco.data = data;
					need_new = false;
				}
			}
		}

		if (need_new)save_vec.Main_data.push_back(etat_data<T>(state_save, data));

	}

	template <typename T>
	void search_and_delete_vect(std::vector<T>& v, T value) {
		size_t i = 0;
		while (i < v.size()) {

			if (v[i] == value) {
				delete v[i];
				v.erase(v.begin() + i);
				return;
			}
			i++;
		}
	}

}
#endif

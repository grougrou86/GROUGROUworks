#pragma once
#include"Image.h"

namespace ONIGIRIX_GUI {
	//forward declaration
	class VideoInstance;
	class VideoManager;

	class ImageVideo : public ImageStream {
	public:
		friend VideoManager;
		ImageVideo();
		virtual ~ImageVideo();

		void play(bool);
		bool is_play();
		void set_time(int);
		int get_time();
		int get_max_time();
		void set_volume(double);
		double get_volume();

	private:
		VideoInstance* _instance_vid = nullptr;
		VideoManager* _manager_vid = nullptr;
	};
}

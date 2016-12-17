#include"Image.h"
#include"ImageVideo.h"
#include"encodage.h"
#include"Video_Player.h"
#include<mutex>

namespace ONIGIRIX_GUI {
	ImageVideo::ImageVideo() {
	}
	ImageVideo::~ImageVideo() {
		if (_instance_vid != nullptr && _manager_vid != nullptr) {
			_manager_vid->RemoveInstance(_instance_vid);
		}
	}
	void ImageVideo::play(bool p) {
		_instance_vid->play(p);
	}
	bool ImageVideo::is_play() {
		return _instance_vid->is_play();
	}
	void ImageVideo::set_time(int t) {
		_instance_vid->set_time(t);
	}
	int ImageVideo::get_time() {
		return _instance_vid->get_time();
	}
	int ImageVideo::get_max_time() {
		return _instance_vid->get_max_time();
	}
	void ImageVideo::set_volume(double v) {
		_instance_vid->set_volume(v);
	}
	double ImageVideo::get_volume() {
		return _instance_vid->get_volume();
	}
}
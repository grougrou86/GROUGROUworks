#pragma once
namespace ONIGIRIX_GUI {
	class VideoInstance;
	static void *vlc_lock(void *data, void **p_pixels);
	static void vlc_unlock(void *data, void *id, void *const *p_pixels);
	static void vlc_display(void *data, void *id);
}
#include "ImageIncludes.h"
#include"texture.h"
#include<vector>
#include<string>
#include<atomic>
#include "vlc/vlc.h"

namespace ONIGIRIX_GUI {
	struct SDL_context {
		void* instance;
	};
	//video Manager can only be used in one thread !!!
	class VideoManager {
	public:
		friend VideoInstance;
		VideoManager(const VideoManager&);
		VideoManager(bool is_hardware=true);
		~VideoManager();
		void RemoveInstance(VideoInstance*);
		ImageVideo* get_Video(std::wstring url);//the instance will survive as long as the video manager
		void Update();//update the image call one's every loop
		void set_DisplayContext(DisplayContext r);//the render in case of hardware use
	private:
		bool _use=true; // true-> hardware false->software
		void init(DisplayContext,bool);
		std::vector<VideoInstance*> _videos;
		libvlc_instance_t *libvlc;
		DisplayContext _DisplayContext = DisplayContext();
	};
	unsigned change_video_format(void **data, char *chroma, unsigned *width, unsigned *height, unsigned *pitches, unsigned *lines);
	class VideoInstance {
	public:
		friend void VideoManager::Update();
		friend void *vlc_lock(void *data, void **p_pixels);
		friend void vlc_unlock(void *data, void *id, void *const *p_pixels);
		friend void vlc_display(void *data, void *id);
		friend void ResizeFrame(VideoInstance *ctx, int num);
		friend unsigned change_video_format(void **data, char *chroma, unsigned *width, unsigned *height, unsigned *pitches, unsigned *lines);
		VideoInstance(std::wstring, VideoManager*, ImageVideo*, bool is_hardware );
		virtual ~VideoInstance();
		void play(bool);
		bool is_play();
		void set_time(int);
		int get_time();
		int get_max_time();
		void set_volume(double);
		double get_volume();

		unsigned int get_max_width();
		unsigned int get_max_height();
		unsigned int get_width();
		unsigned int get_height();
		void set_width_height(unsigned int w, unsigned int h);

	private:

		bool _use = true; // true-> hardware false->software
		BasicImage* get_frame();
		void try_rotate_frame();//rotate frame if ready;

								//the streaming image to update

								//the images (frame of video)
		std::array<BasicImage*,4> _frames = { nullptr,nullptr,nullptr,nullptr};//the frame to display
		std::array<bool, 4> _hardware_to_clear = { false,false,false,false };//note if hardware has to be cleared 
		//the 4th frame is a dustbin hahahah in case

		std::atomic<bool> nextFrameReady = false;//to sycronise the changing of the Images

		std::atomic<short int> current_display_frame = 0;

		bool _play=true;//play by default
		std::atomic<float> _speed;
		std::atomic<int> _volume;
		std::atomic<int> _time;

		std::wstring _url;
		
		std::atomic<unsigned int> _width = 1280;
		std::atomic<unsigned int> _height = 720;

		VideoManager* _manager;

		libvlc_media_t *m;
		libvlc_media_player_t *mp;

		ImageVideo* _output;

		SDL_context context;

		std::atomic<bool> write_garbage=false;

		//for inner funbction to be able to pause directly


		int _seted_time = -1;//in case time is setted before player is ready
		std::atomic<int> numframe = 0;

	};
}

//exemple of VLC
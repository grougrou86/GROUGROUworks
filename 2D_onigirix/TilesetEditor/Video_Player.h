#pragma once
namespace ONIGIRIX_GUI {
	class VideoInstance;
	static void *vlc_lock(void *data, void **p_pixels);
	static void vlc_unlock(void *data, void *id, void *const *p_pixels);
	static void vlc_display(void *data, void *id);
}
#include"ImageDealer.h"
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
		void set_renderer(SDL_Renderer*);//the render in case of hardware use
	private:
		bool _use=true; // true-> hardware false->software
		void init(SDL_Renderer*,bool);
		std::vector<VideoInstance*> _videos;
		libvlc_instance_t *libvlc;
		SDL_Renderer* _renderer=nullptr;
	};

	class VideoInstance {
	public:
		friend void VideoManager::Update();
		friend void *vlc_lock(void *data, void **p_pixels);
		friend void vlc_unlock(void *data, void *id, void *const *p_pixels);
		friend void vlc_display(void *data, void *id);
		VideoInstance(std::wstring, VideoManager*, ImageVideo*, bool is_hardware );
		virtual ~VideoInstance();
		void play(bool);
		bool is_play();
		void set_time(int);
		int get_time();
		int get_max_time();
		void set_volume(double);
		double get_volume();

	private:

		bool _use = true; // true-> hardware false->software
		BasicImage* get_frame();
		void try_rotate_frame();//rotate frame if ready;

								//the streaming image to update

								//the images (frame of video)
		std::array<BasicImage*,4> _frames = { nullptr,nullptr,nullptr};//the frame to display

		//the 4th frame is a dustbin hahahah in case

		std::atomic<bool> nextFrameReady = false;//to sycronise the changing of the Images

		std::atomic<short int> current_display_frame = 0;

		bool _play=true;//play by default
		std::atomic<float> _speed;
		std::atomic<int> _volume;
		std::atomic<int> _time;

		std::wstring _url;
		
		unsigned int _width = 0;
		unsigned int _height = 0;

		VideoManager* _manager;

		libvlc_media_t *m;
		libvlc_media_player_t *mp;

		ImageVideo* _output;

		SDL_context context;

		std::atomic<bool> write_garbage=false;

		//for inner funbction to be able to pause directly


		int _seted_time = -1;//in case time is setted before player is ready
		int numframe = 0;

	};
}

//exemple of VLC
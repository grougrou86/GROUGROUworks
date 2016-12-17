
// libSDL and libVLC sample code.
// License: [http://en.wikipedia.org/wiki/WTFPL WTFPL]

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include "windows.h"
#include "encodage.h"
#include "SDL.h"
#include "SDL_mutex.h"
#include "vlc/vlc.h"
#include "ImageIncludes.h"
#include"texture.h"
#include"Video_Player.h"
#include"VLC_test.h"


namespace ONIGIRIX_GUI {

	//FOR VLC 

	static void *vlc_lock(void *data, void **p_pixels)
	{
		SDL_context *ctx1 = (SDL_context *)(data);
		VideoInstance *ctx = (VideoInstance*)(ctx1->instance);
		int num=0;
		if (!ctx->nextFrameReady) {
			num = ctx->current_display_frame;
			SDL_LockSurface(ctx->_frames[(num + 1) % 3]->get_SOFTWARE()->native());
			*p_pixels = ctx->_frames[(num + 1) % 3]->get_SOFTWARE()->native()->pixels;
		}
		else {
			ctx->write_garbage = true;
			num = 3;
			SDL_LockSurface(ctx->_frames[num]->get_SOFTWARE()->native());
			*p_pixels = ctx->_frames[num]->get_SOFTWARE()->native()->pixels;
		}

		return NULL; /* picture identifier, not needed here */
	}

	static void vlc_unlock(void *data, void *id, void *const *p_pixels)
	{
		SDL_context *ctx1 = (SDL_context *)(data);
		VideoInstance *ctx = (VideoInstance*)(ctx1->instance);

		/* VLC just rendered the video, but we can also render stuff */
		uint16_t *pixels = (uint16_t *)*p_pixels;
		int num;
		if (!ctx->write_garbage) {
			num = ctx->current_display_frame;
			SDL_UnlockSurface(ctx->_frames[(num + 1) % 3]->get_SOFTWARE()->native());
			ctx->nextFrameReady = true;
		}
		else {
			num = 3;
			SDL_UnlockSurface(ctx->_frames[num]->get_SOFTWARE()->native());
			ctx->write_garbage = false;
		}
		assert(id == NULL); /* picture identifier, not needed here */
	}

	static void vlc_display(void *data, void *id)
	{
		/* VLC wants to display the video */
		(void)data;
		assert(id == NULL);
	}

	

	//END FOR VLC

	void VideoManager::Update() {
		for (auto& v : _videos) {
			v->try_rotate_frame();
		}
	}
	void VideoManager::init(DisplayContext r,bool use) {
		_DisplayContext = r;
		_use = use;
		char const *vlc_argv[] = {

			//"--no-audio", // Don't play audio.
			"--no-xlib", // Don't use Xlib.
			"--play-and-pause",
						 // Apply a video filter.
						 //"--video-filter", "sepia",
						 //"--sepia-intensity=200"
		};
		int vlc_argc = sizeof(vlc_argv) / sizeof(*vlc_argv);
		printf("VLC_PLUGIN_PATH=%s\n", getenv("VLC_PLUGIN_PATH"));

		// Initialise libVLC.
		libvlc = libvlc_new(vlc_argc, vlc_argv);
		if (NULL == libvlc) {
			printf("LibVLC initialization failure.\n");
		}
	}
	void VideoManager::set_DisplayContext(DisplayContext r) {
		_DisplayContext = r;
	}
	VideoManager::VideoManager(bool use) {
		init(nullptr,use); 
	}

	VideoManager::VideoManager(const VideoManager& old) {
		init(old._DisplayContext,old._use);
	}
	VideoManager::~VideoManager() {
		//delete remaining videos
		for (auto&v : _videos) {
			delete v;
		}
		//delete libvlc instance
		libvlc_release(libvlc);

		int a = 3;
	}
	VideoInstance::VideoInstance(std::wstring url, VideoManager* manager, ImageVideo* out, bool hard) {

		_use = hard;

		_url = url;
		_manager = manager;
		_output = out;

		context.instance = this;

		_height = 1080;
		_width = 1920;


		for (int i = 0; i < 4; i = i + 1) {
			_frames[i] = new BasicImage();
			SDL_Surface* surf = SDL_CreateRGBSurface(SDL_SWSURFACE, _width, _height, 32, 0, 0, 0, 0);
			SDL_S_texture* a = new SDL_S_texture(surf);
			if (_use) {
				SDL_H_texture* b = new SDL_H_texture(nullptr);
				_frames[i]->set_SDL_TEXTURE(b);
			}
			_frames[i]->set_SOFTWARE(a);
			
			_frames[i]->set_width(_width);
			_frames[i]->set_height(_height);
		}

		char const *vlc_argv[] = { "--no-xlib" };
		int vlc_argc = sizeof(vlc_argv) / sizeof(*vlc_argv);
		m = libvlc_media_new_path(_manager->libvlc, ws2s(_url).c_str());
		mp = libvlc_media_player_new_from_media(m);
		libvlc_media_release(m);

		libvlc_video_set_callbacks(mp, vlc_lock, vlc_unlock, vlc_display, &context);
		libvlc_video_set_format(mp, "RV32", _width, _height, _width*4);
		libvlc_media_player_play(mp);
		//if (a = -1)throw("error media not played");

	}
	VideoInstance::~VideoInstance(){


		libvlc_media_player_stop(mp);
		libvlc_media_player_release(mp);

		for (int i = 0; i < 4; i = i + 1) {
			if (_frames[i] != nullptr) {
				delete _frames[i]->get_SDL_TEXTURE();
				delete _frames[i]->get_GL_TEXTURE();
				delete _frames[i]->get_SOFTWARE();
				delete _frames[i];
			}
		}

	}
	BasicImage* VideoInstance::get_frame() {
		return _frames[current_display_frame];
	}
	void VideoInstance::try_rotate_frame() {
		if (nextFrameReady) {
			if (numframe == 0)numframe++;
			if (numframe == 1) { 
				numframe++; 
				libvlc_media_player_set_pause(mp, (int)(!_play));
				if(_seted_time!=-1)libvlc_media_player_set_time(mp, _seted_time);
			}
			short int a = current_display_frame;
			a = (a + 1) % 3;
			current_display_frame = a;
			nextFrameReady = false;
			if (_use){
				if (_frames[a]->get_SDL_TEXTURE()->native() == nullptr) {
					SDL_Texture* newtex = SDL_CreateTexture(_manager->_DisplayContext.get_SDL_Renderer(),SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,_frames[a]->get_SOFTWARE()->native()->w, _frames[a]->get_SOFTWARE()->native()->h);
					//SDL_Texture* newtex = SDL_CreateTextureFromSurface(_manager->_renderer, _frames[a]->get_SOFTWARE()->native());
					_frames[a]->get_SDL_TEXTURE()->set(newtex);
				}
				SDL_Texture* tex = _frames[a]->get_SDL_TEXTURE()->native();
				void* mPixels;
				SDL_LockTexture(tex, NULL, &mPixels,&(_frames[a]->get_SOFTWARE()->native()->pitch));
				memcpy(mPixels, (_frames[a]->get_SOFTWARE()->native()->pixels), _frames[a]->get_SOFTWARE()->native()->pitch *  _frames[a]->get_SOFTWARE()->native()->h);
				SDL_UnlockTexture(tex);
				mPixels = NULL;
				//SDL_UpdateTexture(tex, NULL, _frames[a]->get_SOFTWARE()->native()->pixels, 4*_width);
				
			}
			_output->update(_frames[a]);
		}
	}
	ImageVideo* VideoManager::get_Video(std::wstring url) {
		ImageVideo* retour = nullptr;
		retour = new ImageVideo();
		VideoInstance* instance = new VideoInstance(url, this, retour,_use);
		retour->_instance_vid = instance;
		retour->_manager_vid = this;
		_videos.push_back(instance);
		return retour;
	}
	void VideoManager::RemoveInstance(VideoInstance* i) {
		std::vector<VideoInstance*>::iterator position = std::find(_videos.begin(), _videos.end(), i);
		if (position != _videos.end()) {
			delete (*position);
			_videos.erase(position);
		}
	}
	void VideoInstance::play(bool play) {
		libvlc_media_player_set_pause(mp, (int)(!play));
		_play = play;
	}
	bool VideoInstance::is_play() {
		return  libvlc_media_player_is_playing(mp);
	}
	int VideoInstance::get_time() {
		return libvlc_media_player_get_time(mp);
	}
	int VideoInstance::get_max_time() {
		return libvlc_media_player_get_length(mp);
	}
	void  VideoInstance::set_time(int t) {
		_seted_time = t;
		libvlc_media_player_set_time(mp, t);
	}
	void VideoInstance::set_volume(double v) {
		libvlc_audio_set_volume(mp, v);
	}
	double VideoInstance::get_volume() {
		return libvlc_audio_get_volume(mp);
	}
}
//exemple of VLC

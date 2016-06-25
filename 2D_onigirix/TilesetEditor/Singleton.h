#pragma once
namespace ONIGIRIX_GUI {
	template <class T> class Singleton
	{
	public:
		static T* Get();
		static void Kill();
	protected:
		static T* m_i;
	private:
		T& operator= (const T&) {}
	};

	class SoundManager :public Singleton<SoundManager>
	{
		friend SoundManager* Singleton<SoundManager>::Get();
		friend void Singleton<SoundManager>::Kill();

	private:
		SoundManager(const SoundManager&) {}

		SoundManager();
		~SoundManager();
	};



}
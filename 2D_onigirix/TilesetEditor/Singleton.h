#pragma once
namespace ONIGIRIX_GUI {
	template <class T> class Singleton
	{
	public:
		static T* Get();
	};
}
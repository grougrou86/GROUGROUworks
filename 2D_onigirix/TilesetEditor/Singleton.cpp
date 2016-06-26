#include "Singleton.h"
namespace ONIGIRIX_GUI {
	template <class T>  T* Singleton<T>::Get()
	{
		static T instance;
		return &instance;
	}
}
#include "Singleton.h"
namespace ONIGIRIX_GUI {
	template <class T> T* Singleton<T>::m_i = 0;

	template <class T>  T* Singleton<T>::Get()
	{
		if (m_i == 0)
		{
			m_i = new T();
		}
		return m_i;
	}
}
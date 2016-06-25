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
	template <class T> void Singleton<T>::Kill()
	{
		delete m_i;
		m_i = 0;
	}
}
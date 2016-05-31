#pragma once

namespace ONIGIRIX_GUI {
	template <typename T>
	class auto_choice {
	public:
		auto_choice(T val) :is_auto(false), value(val) {}
		auto_choice(bool s_auto) :is_auto(s_auto), value(T()) {}
		auto_choice() :is_auto(true), value() {}
		bool is_auto = false;
		T value;
	};
	template <typename T>
	bool operator==(auto_choice<T> A, auto_choice<T> B) {
		return ((A.is_auto&&B.is_auto) || ((!A.is_auto) && (!B.is_auto))) && (A.value == B.value);
	}
}

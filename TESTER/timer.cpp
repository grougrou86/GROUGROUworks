 #include "timer.h"
 void Timer::reset() { beg_ = clock_::now(); }
 double Timer::elapsed() const { return std::chrono::duration_cast<std::chrono::milliseconds> (clock_::now() - beg_).count(); }

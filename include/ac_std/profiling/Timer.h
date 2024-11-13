// Copyright (c) 2024 Alexandru Constantin

#ifndef INCLUDE_AC_STD_PROFILING_TIMER_H_
#define INCLUDE_AC_STD_PROFILING_TIMER_H_

#include <chrono>
#include <cstdint>

namespace ac_std {
namespace profiler {
struct TimerResult {
  const char* name;
  const int64_t start;
  const int64_t end;
  const uint32_t threadId;
};

class Timer {
 public:
  explicit Timer(const char* name);

  void start();

  void stop();

  TimerResult getTimerInfo();

  int64_t elapsedMicroseconds();
  double elapsedMiliseconds();
  double elapsedSeconds();

 private:
  const char* _name;
  std::chrono::time_point<std::chrono::high_resolution_clock> _startTimePoint;
  std::chrono::time_point<std::chrono::high_resolution_clock> _endTimePoint;
  bool _isRunning;
};
}  // namespace profiler
}  // namespace ac_std

#endif  // INCLUDE_AC_STD_PROFILING_TIMER_H_

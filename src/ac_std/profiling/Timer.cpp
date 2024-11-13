// Copyright (c) 2024 Alexandru Constantin

#include "profiling/Timer.h"
#include <thread>

namespace ac_std {
namespace profiler {
Timer::Timer(const char* name) : _name(name) {}

void Timer::start() {
  this->_startTimePoint = std::chrono::high_resolution_clock::now();
  this->_isRunning = true;
}

void Timer::stop() {
  this->_endTimePoint = std::chrono::high_resolution_clock::now();
  this->_isRunning = false;
}

TimerResult Timer::getTimerInfo() {
  std::chrono::time_point<std::chrono::high_resolution_clock> endTimePoint;

  if (this->_isRunning)
    endTimePoint = std::chrono::high_resolution_clock::now();
  else
    endTimePoint = std::chrono::high_resolution_clock::now();

  int64_t start = std::chrono::time_point_cast<std::chrono::microseconds>(
                      this->_startTimePoint)
                      .time_since_epoch()
                      .count();

  int64_t end =
      std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint)
          .time_since_epoch()
          .count();

  uint32_t threadId = std::hash<std::thread::id>{}(std::this_thread::get_id());

  return {this->_name, start, end, threadId};
}

int64_t Timer::elapsedMicroseconds() {
  TimerResult timerResult = getTimerInfo();

  return timerResult.end - timerResult.start;
}

double Timer::elapsedMiliseconds() {
  TimerResult timerResult = getTimerInfo();
  return (timerResult.end - timerResult.start) / 1000.0;
}

double Timer::elapsedSeconds() {
  TimerResult timerResult = getTimerInfo();
  return (timerResult.end - timerResult.start) / 1000.0 / 1000.0;
}
}  // namespace profiler
}  // namespace ac_std

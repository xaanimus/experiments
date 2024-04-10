#pragma once

#include <string>
#include <sstream>

class LogBuilder;

class Logger {
public:
  explicit Logger(const std::string& prefix);

  void print_chapter_init(const std::string& chapter_name);
  Logger fork(const std::string& prefix);

  friend void operator&(const Logger& logger, const LogBuilder& logBuilder);

private:
  std::string prefix_;
};

class LogBuilder {
public:
  explicit LogBuilder();

  template <typename T>
  LogBuilder& operator<<(const T val) {
    buf_ << val;
    return *this;
  }

  friend void operator&(const Logger& logger, const LogBuilder& logBuilder);

private:
  std::stringstream buf_;
};

void operator&(const Logger& logger, const LogBuilder& logBuilder);

#define LOG(logger) logger & LogBuilder()


#include "logger.h"
#include <iostream>


Logger::Logger(const std::string& prefix): prefix_(prefix) {}

void Logger::print_chapter_init(const std::string& chapter_name) {
  LOG(*this) << "-- Running " << chapter_name << " --";
}

Logger Logger::fork(const std::string& prefix) {
  return Logger(prefix_ + "/" + prefix);
}

LogBuilder::LogBuilder() {}

void operator&(const Logger& logger, const LogBuilder& logBuilder) {
  std::cout << "[" << logger.prefix_ << "] "
    << logBuilder.buf_.str()
    << std::endl;
}

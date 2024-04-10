#include "chapters.h"
#include "logger.h"

#include <iostream>

void run_ch1_deducing_types(Logger&& logger) {
  logger.print_chapter_init("ch1_deducing_types");
  LOG(logger) << "hi";
}

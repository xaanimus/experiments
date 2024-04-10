#include <iostream>
#include "chapters.h"
#include "logger.h"

int main() {
  Logger logger = Logger("");

  run_ch1_deducing_types(logger.fork("ch1"));

  return 0;
}

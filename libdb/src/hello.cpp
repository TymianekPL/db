#include "hello.h"
#include <print>
#include <chrono>

void SayHi(void) { std::println("hi {}!", std::chrono::system_clock::now()); }

module;
#include <chrono>
#include <print>
export module Hello;

import :Arithmetic;

export void SayHi(void) { std::println("hi {}!!", CurrentTime()); }

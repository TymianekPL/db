module Hello;

import std;
import :Impl;

void SayHi(void)
{
     const auto time = CurrentTime();
     std::println("it is {}!", time);
}

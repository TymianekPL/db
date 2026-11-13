module Hello:Impl;

import std;

auto CurrentTime(void)
{
     return std::chrono::system_clock::now();
}

add_library(db STATIC)

target_sources(db PUBLIC FILE_SET CXX_MODULES FILES
  src/hello.cpp
  src/arithmetic.cpp
)

# target_include_directories(db PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

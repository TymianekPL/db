add_executable(dbcli src/main.cpp)

target_link_libraries(dbcli PRIVATE db)
target_link_options(dbcli PRIVATE -no-pie)

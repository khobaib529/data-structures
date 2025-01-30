# Build SkipList usage example
add_executable(SkipListUsageExample SkipListUsageExample.cc)
target_link_libraries(SkipListUsageExample PRIVATE ds)
target_include_directories(SkipListUsageExample PRIVATE ${CMAKE_SOURCE_DIR}/include)

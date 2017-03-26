include_directories(.)
add_executable(tests tests.cpp)
set_property(TARGET tests PROPERTY CXX_STANDARD 14)
target_link_libraries (tests LINK_PUBLIC mylib)

file(GLOB SRCS "*.cpp")

# Exclude main.cpp from SRCS
# foreach(s ${SRCS})
# if(NOT ${s} MATCHES "main.cpp")
#   list(APPEND NEW_SRCS "${s}")
# endif()
# endforeach()
# SET(SRCS ${NEW_SRCS})

add_library(mylib STATIC ${SRCS})
target_include_directories (mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(semi main.cpp)
set_property(TARGET semi PROPERTY CXX_STANDARD 14)
set_property(TARGET mylib PROPERTY CXX_STANDARD 14)
target_link_libraries (semi LINK_PUBLIC mylib)

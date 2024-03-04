cmake_minimum_required(VERSION 3.0.0)
project(spanner VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(spanner main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(cpprestsdk CONFIG REQUIRED)
target_link_libraries(spanner PRIVATE cpprestsdk::cpprest cpprestsdk::cpprestsdk_zlib_internal cpprestsdk::cpprestsdk_brotli_internal)

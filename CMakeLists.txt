cmake_minimum_required(VERSION 3.1...3.16)
project(csv_engine VERSION 1.0)
add_subdirectory(library)
add_subdirectory(unit_test)
#install(EXPORT csv_engineConfig DESTINATION lib/cmake)
export(TARGETS csv_engine FILE csv_engineConfig.cmake)


set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(csv_engine SHARED src/basic_func.cpp)
target_include_directories(csv_engine PUBLIC include)
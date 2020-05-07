set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(csv_engine STATIC src/basic_func.cpp)
#add_library(csv_engine STATIC src/advanced_func.cpp)
set_target_properties(csv_engine PROPERTIES PUBLIC_HEADER include/csv_engine.h)
target_include_directories(csv_engine PUBLIC include)
INSTALL(TARGETS csv_engine EXPORT csv_engineConfig ARCHIVE DESTINATION lib LIBRARY DESTINATION lib PUBLIC_HEADER DESTINATION include)


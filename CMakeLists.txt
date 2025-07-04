cmake_minimum_required(VERSION 3.8.0)
project(Chessy VERSION 0.0.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 11)

# --- Executables ---
file(GLOB Sources "src/*.cc" "src/*/*.cc")
add_executable("${PROJECT_NAME}" ${Sources})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPACK)

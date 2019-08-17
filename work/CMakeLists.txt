cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
project(cw_face_ped_match)

# cnpy, a lib to read data from .npz
include_directories("/usr/local/include/")
link_directories("/usr/local/lib/")
link_libraries(-lcnpy)

add_executable(match main.cc cw_face_ped_match.cc)
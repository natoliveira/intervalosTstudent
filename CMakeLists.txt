cmake_minimum_required(VERSION 3.19)
project(medias)

set(CMAKE_CXX_STANDARD 14)
#set(GSL_ROOT "/usr/include/gsl")
set(BOOST_ROOT "/usr/include/boost")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_package(GSL REQUIRED)


add_executable(medias main.cpp distribuition.h confidenceInterval.h average.h t_student.h interval.cpp distribuition.cpp average.cpp t_student.cpp)
target_link_libraries(medias -lgsl -lgslcblas -lm)
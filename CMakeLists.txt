cmake_minimum_required(VERSION 4.3)
project(cpp_course_lab_works)

set(CMAKE_CXX_STANDARD 20)

#pw
add_executable(pw1 pw1/pw1.cpp)
add_executable(pw2 pw2/pw2.cpp)
add_executable(pw3 pw3/pw3.cpp)
add_executable(pw4 pw4/pw4.cpp)
add_executable(pw5 pw5/pw5.cpp)

#lpw
add_executable(lpw lpw/main.cpp
        lpw/Contact.h
        lpw/tools/UniqueIdGenerator.h
        lpw/ContactService.cpp
        lpw/ContactService.cpp)
cmake_minimum_required(VERSION 3.23)
project(PlayerManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(PlayerManager main.cpp University.cpp University.h UniversityCollection.cpp UniversityCollection.h IvyLeague.cpp IvyLeague.h TopKoreaUniversityCollection.cpp TopKoreaUniversityCollection.h UniversityManager.cpp UniversityManager.h)

# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/AGoogle/SkillBox/_C++/Skillbox_practice_works_30/cmake-build-debug/_deps/curl-src"
  "D:/AGoogle/SkillBox/_C++/Skillbox_practice_works_30/cmake-build-debug/_deps/curl-build"
  "D:/AGoogle/SkillBox/_C++/Skillbox_practice_works_30/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix"
  "D:/AGoogle/SkillBox/_C++/Skillbox_practice_works_30/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/tmp"
  "D:/AGoogle/SkillBox/_C++/Skillbox_practice_works_30/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
  "D:/AGoogle/SkillBox/_C++/Skillbox_practice_works_30/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src"
  "D:/AGoogle/SkillBox/_C++/Skillbox_practice_works_30/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/AGoogle/SkillBox/_C++/Skillbox_practice_works_30/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/AGoogle/SkillBox/_C++/Skillbox_practice_works_30/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.12.0)

if(CMAKE_BUILD_RPATH)
    message("CMAKE_BUILD_RPATH: ${CMAKE_BUILD_RPATH}")
endif()

# 项目信息
project (cc_algorithm)
set (CC_ALGORITHM_MAX_VERSION 1)
set (CC_ALGORITHM_MID_VERSION 0)
set (CC_ALGORITHM_MIN_VERSION 0)

# 设置编译选项
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -g -fprofile-arcs -ftest-coverage") 
# 目录下的所有源文件
aux_source_directory(src CC_ALGORITHM_SRC_FILES)
aux_source_directory(gtest CC_ALGORITHM_TEST_FILES)

# 头文件目录
include_directories(${PROJECT_SOURCE_DIR}/hdr)

# 库文件目录
include_directories(${CMAKE_BUILD_RPATH}/include)
link_directories(${CMAKE_BUILD_RPATH}/lib)

#添加编译选项
add_executable(cc_algorithm ${CC_ALGORITHM_SRC_FILES} 
                ${CC_ALGORITHM_TEST_FILES})
target_link_libraries(cc_algorithm PRIVATE gtest)
target_link_libraries(cc_algorithm PRIVATE gcov)

#执行程序
add_custom_target(test
	COMMAND ./cc_algorithm
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
	COMMENT "run test suit.")

add_custom_target(gen_coverage
	COMMAND lcov -d CMakeFiles/cc_algorithm.dir/src -t cc_algorithm -o 'cc_algorithm.cov.info' -b . -c
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
	COMMENT "genarate coverage info")

add_custom_target(gen_coverage_html
	COMMAND genhtml -o cov_result cc_algorithm.cov.info
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
	COMMENT "genarate coverage info to ./cov_result")

add_dependencies(gen_coverage test)
add_dependencies(gen_coverage cc_algorithm)
add_dependencies(gen_coverage_html gen_coverage)

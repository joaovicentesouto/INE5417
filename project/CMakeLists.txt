cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME "virtual_wallet")
project (PROJECT_NAME)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.58 REQUIRED)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

set(VIRTUAL_WALLET_INCLUDE_DIR
	${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/src/
  ${PROJECT_SOURCE_DIR}/test/
)

include_directories(VIRTUAL_WALLET_INCLUDE_DIR)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()

add_test (NAME MyTest COMMAND Test)

cmake_minimum_required (VERSION 2.6)

project (posix)

include(toolchain.cmake NO_POLICY_SCOPE)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

set(CFLAGS "\
	-ggdb3 \
	-ffunction-sections \
	-fdata-sections \
	\
	-Wall \
	-Werror \
	-Wfatal-errors \
	\
	-Wno-sign-compare \
	-Wno-unused-variable \
	-Wno-unused-but-set-variable \
	-Wno-deprecated-declarations \
	-Wno-parentheses \
	-Wno-format \
")
set(CCFLAGS "\
	-Wno-pointer-to-int-cast \
	-Wno-pointer-sign \
	-std=gnu99 \
")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CFLAGS} ${CCFLAGS}")

target_link_libraries(${CMAKE_PROJECT_NAME}
	pthread
)

include_directories(${CMAKE_PROJECT_NAME} PRIVATE
	inc
	src
)

FILE(GLOB SRC src/*.c*)
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
	${SRC}
)
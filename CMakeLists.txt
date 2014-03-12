cmake_minimum_required(VERSION 2.8)

project(qplugininfo)

# ---- dependencies -----------------------------------------------------------
find_package(Qt4 REQUIRED)

# ---- compiler flags ---------------------------------------------------------
if(MSVC)
	# Force to always compile with W4
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic -Werror -Wno-write-strings -O3")
endif()

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

# ---- build binary -----------------------------------------------------------
add_executable(qplugininfo qplugininfo.cpp)

# ---- install target ---------------------------------------------------------
install(TARGETS qplugininfo DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
target_link_libraries(qplugininfo ${QT_LIBRARIES})

# ---- uninstall target -------------------------------------------------------
configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
	IMMEDIATE @ONLY)

add_custom_target(uninstall
	COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

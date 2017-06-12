# SDL2 find module
#
# Variables:
# SDL2_FOUND - system has SDL2
# SDL2_INCLUDE_DIRS - SDL2 include directories
# SDL2_LIBRARIES - libraries need to use SDL2

find_package(PkgConfig)
pkg_check_modules(PC_SDL2 REQUIRED SDL2)

find_library(SDL2_LIBRARY NAMES SDL2
			  HINTS ${PC_SDL2_STATIC_LIBRARIES})
find_path(SDL2_INCLUDE_DIR SDL2/SDL.h
			   HINTS ${PC_SDL2_STATIC_INCLUDE_DIRS}
			   PATH_SUFFIXES SDL2)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2 DEFAULT_MSG
				       SDL2_LIBRARY SDL2_INCLUDE_DIR)
mark_as_advanced(SDL2_LIBRARY SDL2_INCLUDE_DIR)

set(SDL2_LIBRARIES ${SDL2_LIBRARY})
set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS})

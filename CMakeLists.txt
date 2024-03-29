#
# Build configuration
#
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 17)
project(tomatoPANIC)

# Enable ccache by default and as early as possible because project() performs
# checks on the compiler
option(ENABLE_CCACHE "Enable ccache support" ON)
if(ENABLE_CCACHE)
  message(STATUS "Trying to enable ccache")
  find_program(BIN_CCACHE ccache)

  string(ASCII 27 esc)
  if(NOT BIN_CCACHE)
    message(STATUS "${esc}[33mCouldn't locate ccache, disabling ccache...${esc}[0m")
  else()
    # Enable only if the binary is found
    message(STATUS "${esc}[32mUsing compiler cache ${BIN_CCACHE}${esc}[0m")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${BIN_CCACHE})
  endif()
endif()

###############################################################################
## file globbing ##############################################################
###############################################################################

# These instructions search the directory tree when cmake is
# invoked and put all files that match the pattern in the variables
# `sources` and `headers`.
file(GLOB sources  src/*.c)
file(GLOB headers  include/*.h)
file(GLOB objs     obj/*.o)
# You can use set(sources src/main.cpp) etc if you don't want to
# use globbing to find files automatically.

###############################################################################
## target definitions #########################################################
###############################################################################
# The data is just added to the executable, because in some IDEs (QtCreator)
# files are invisible when they are not explicitly part of the project.
add_executable(tomatoPANIC ${sources} ${objs})

# Just for example add some compiler flags.
target_compile_options(tomatoPANIC PUBLIC -Wall -Wfloat-conversion -pipe)

# This allows to include files relative to the root of the src directory with a <> pair
target_include_directories(tomatoPANIC PUBLIC include)

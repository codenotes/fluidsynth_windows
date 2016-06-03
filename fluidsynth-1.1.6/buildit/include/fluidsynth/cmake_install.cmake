# Install script for directory: D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/FluidSynth")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/fluidsynth" TYPE FILE FILES
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/audio.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/event.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/gen.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/log.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/midi.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/misc.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/mod.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/ramsfont.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/seq.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/seqbind.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/settings.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/sfont.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/shell.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/synth.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/types.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/include/fluidsynth/voice.h"
    "D:/repos/fluidsynth_windows/fluidsynth-1.1.6/buildit/include/fluidsynth/version.h"
    )
endif()


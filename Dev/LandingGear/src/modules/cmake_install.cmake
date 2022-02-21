# Install script for directory: /home/badger/forte-incubation_1.14.0/src/modules

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/IEC61131-3/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/PLC01A1/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/ads/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/arrowhead/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/conmeleon_c1/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/convert/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/embrick/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/i2c_dev/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/lms_ev3/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/mlpi/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/odroid/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/piface/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/raspberry_sps/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/reconfiguration/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/rt_events/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/sysfs/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/umic/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/utils/cmake_install.cmake")
  include("/home/Fan/Dev/4diac/LandingGear/src/modules/wagokbus/cmake_install.cmake")

endif()


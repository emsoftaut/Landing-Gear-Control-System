SET(SOURCE_GROUP_BACKUP "${SOURCE_GROUP}")
SET(SOURCE_GROUP "${SOURCE_GROUP}/AlarmClock")
ADD_SUBDIRECTORY("${FORTE_EXTERNAL_MODULES_DIRECTORY}/AlarmClock" "${CMAKE_CURRENT_BINARY_DIR}/external/AlarmClock")
SET(SOURCE_GROUP "${SOURCE_GROUP_BACKUP}")
SET(SOURCE_GROUP_BACKUP "${SOURCE_GROUP}")
SET(SOURCE_GROUP "${SOURCE_GROUP}/First")
ADD_SUBDIRECTORY("${FORTE_EXTERNAL_MODULES_DIRECTORY}/First" "${CMAKE_CURRENT_BINARY_DIR}/external/First")
SET(SOURCE_GROUP "${SOURCE_GROUP_BACKUP}")
SET(SOURCE_GROUP_BACKUP "${SOURCE_GROUP}")
SET(SOURCE_GROUP "${SOURCE_GROUP}/HVACsim")
ADD_SUBDIRECTORY("${FORTE_EXTERNAL_MODULES_DIRECTORY}/HVACsim" "${CMAKE_CURRENT_BINARY_DIR}/external/HVACsim")
SET(SOURCE_GROUP "${SOURCE_GROUP_BACKUP}")
SET(SOURCE_GROUP_BACKUP "${SOURCE_GROUP}")
SET(SOURCE_GROUP "${SOURCE_GROUP}/LandingGear")
ADD_SUBDIRECTORY("${FORTE_EXTERNAL_MODULES_DIRECTORY}/LandingGear" "${CMAKE_CURRENT_BINARY_DIR}/external/LandingGear")
SET(SOURCE_GROUP "${SOURCE_GROUP_BACKUP}")

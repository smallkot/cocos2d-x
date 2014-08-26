cmake_minimum_required(VERSION 2.8)

set(APP_NAME MyGame)
project (${APP_NAME})

include(cocos2d/build/BuildHelpers.CMakeLists.txt)

option(USE_CHIPMUNK "Use chipmunk for physics library" ON)
option(USE_BOX2D "Use box2d for physics library" OFF)
option(DEBUG_MODE "Debug or release?" ON)

if(DEBUG_MODE)
  set(CMAKE_BUILD_TYPE DEBUG)
  message("DEBUG MODE")
else(DEBUG_MODE)
  set(CMAKE_BUILD_TYPE RELEASE)
  message("RELEASE MODE")
endif(DEBUG_MODE)

set(CMAKE_C_FLAGS_DEBUG "-DCOCOS2D_DEBUG=1")
set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})

if(WIN32)
  ADD_DEFINITIONS (-D_USRDLL -DCOCOS2DXWIN32_EXPORTS -D_WINDOWS -DWIN32)

  if(MSVC)
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS 
					-D_SCL_SECURE_NO_WARNINGS 
					-wd4251 -wd4244 -wd4334 
					-wd4005 -wd4820 -wd4710
					-wd4514 -wd4056 -wd4996 -wd4099)
  else(MSVC)#MINGW
  
  endif(MSVC)
elseif(APPLE)


else()#Linux
ADD_DEFINITIONS(-DLINUX)
endif()


if(NOT MSVC)# all gcc
  set(CMAKE_C_FLAGS_DEBUG "-g -Wall -DCOCOS2D_DEBUG=1")
  set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
  if (NOT DEBUG_MODE)
    set(CMAKE_EXE_LINKER_FLAGS "-s")
  endif()
  set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-std=c99")
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
endif()

if(MINGW)
  add_definitions(-DGLEW_STATIC)
  add_definitions(-D__SSIZE_T)
  set(CMAKE_C_STANDARD_LIBRARIES "${CMAKE_C_STANDARD_LIBRARIES} -lws2_32")
  set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} -lws2_32")
endif()


if(USE_CHIPMUNK)
  message("Using chipmunk ...")
  add_definitions(-DCC_ENABLE_CHIPMUNK_INTEGRATION=1)
elseif(USE_BOX2D)
  message("Using box2d ...")
  add_definitions(-DCC_ENABLE_BOX2D_INTEGRATION=1)
else(USE_CHIPMUNK)
  message(FATAL_ERROR "Must choose a physics library.")
endif(USE_CHIPMUNK)

# architecture
if ( CMAKE_SIZEOF_VOID_P EQUAL 8 )
set(ARCH_DIR "64-bit")
else()
set(ARCH_DIR "32-bit")
endif()

if( UNIX ) #assume linux
set(GAME_SRC
  proj.linux/main.cpp
)
elseif ( WIN32 )
set(GAME_SRC
  proj.win32/main.cpp
  proj.win32/main.h
  proj.win32/resource.h
)
endif()

file(GLOB CLASSES_SRC
    "Classes/*.cpp"
)

include_directories(
  Classes
)

set(COCOS2D_ROOT ${CMAKE_SOURCE_DIR}/cocos2d)
if(WIN32) # Win32
  set(PLATFORM_FOLDER win32)
elseif(APPLE)# osx or ios
  set(PLATFORM_FOLDER mac)
else() # Assume Linux
  set(PLATFORM_FOLDER linux)
endif()

include_directories(
  ${COCOS2D_ROOT}
  ${COCOS2D_ROOT}/cocos
  ${COCOS2D_ROOT}/cocos/platform/desktop
  ${COCOS2D_ROOT}/cocos/platform/${PLATFORM_FOLDER}
  ${COCOS2D_ROOT}/cocos/audio/include
  ${COCOS2D_ROOT}/cocos/editor-support
  ${COCOS2D_ROOT}/cocos/scripting/lua-bindings/auto
  ${COCOS2D_ROOT}/cocos/scripting/lua-bindings/manual
  ${COCOS2D_ROOT}/extensions
  ${COCOS2D_ROOT}/external
  ${COCOS2D_ROOT}/external/tinyxml2
  ${COCOS2D_ROOT}/external/unzip
  ${COCOS2D_ROOT}/external/edtaa3func
  ${COCOS2D_ROOT}/external/chipmunk/include/chipmunk
  ${COCOS2D_ROOT}/external/jpeg/include/${PLATFORM_FOLDER}
  ${COCOS2D_ROOT}/external/png/include/${PLATFORM_FOLDER}
  ${COCOS2D_ROOT}/external/tiff/include/${PLATFORM_FOLDER}
  ${COCOS2D_ROOT}/external/webp/include/${PLATFORM_FOLDER}
  ${COCOS2D_ROOT}/external/glfw3/include/${PLATFORM_FOLDER}
  ${COCOS2D_ROOT}/external/freetype2/include/${PLATFORM_FOLDER}
  ${COCOS2D_ROOT}/external/websockets/include/${PLATFORM_FOLDER}
  ${COCOS2D_ROOT}/external/xxhash
  ${COCOS2D_ROOT}/external/xxtea
)

if(WIN32)
  if(NOT MINGW)
    include_directories(
      ${COCOS2D_ROOT}/external/${PLATFORM_FOLDER}-specific/gles/include/OGLES
      ${COCOS2D_ROOT}/external/${PLATFORM_FOLDER}-specific/icon/include
      ${COCOS2D_ROOT}/external/${PLATFORM_FOLDER}-specific/zlib/include
    )
  endif()
    include_directories(
      ${COCOS2D_ROOT}/external/curl/include/${PLATFORM_FOLDER}
      ${COCOS2D_ROOT}/external/sqlite3/include
    )
elseif(APPLE)
  include_directories(
  	${COCOS2D_ROOT}/external/curl/include/${PLATFORM_FOLDER}
  )
else()
  include_directories(
    /usr/include
    /usr/include/GLFW
    /usr/local/include/GLFW
  )
endif()


if(WIN32)

  if(NOT MINGW)
  link_directories(
    ${COCOS2D_ROOT}/external/jpeg/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/tiff/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/png/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/freetype2/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/curl/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/sqlite3/libraries/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/websockets/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/webp/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/glfw3/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/${PLATFORM_FOLDER}-specific/icon/prebuilt
    ${COCOS2D_ROOT}/external/${PLATFORM_FOLDER}-specific/zlib/prebuilt
    ${COCOS2D_ROOT}/external/${PLATFORM_FOLDER}-specific/gles/prebuilt
  )
  endif()
  link_directories(
    ${COCOS2D_ROOT}/external/curl/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/websockets/prebuilt/${PLATFORM_FOLDER}
    ${COCOS2D_ROOT}/external/sqlite3/libraries/${PLATFORM_FOLDER}
  )

elseif(APPLE)

else()

  link_directories(
    /usr/local/lib
    ${COCOS2D_ROOT}/external/jpeg/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${COCOS2D_ROOT}/external/tiff/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${COCOS2D_ROOT}/external/webp/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${COCOS2D_ROOT}/external/png/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${COCOS2D_ROOT}/external/freetype2/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${COCOS2D_ROOT}/external/websockets/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
    ${COCOS2D_ROOT}/external/${PLATFORM_FOLDER}-specific/fmod/prebuilt/${ARCH_DIR}
  )

endif()

if(USE_CHIPMUNK)

	include_directories(${COCOS2D_ROOT}/external/chipmunk/include/chipmunk)
	# chipmunk library
	add_subdirectory(${COCOS2D_ROOT}/external/chipmunk/src)
endif()

if(USE_BOX2D)
	# box2d library
	add_subdirectory(${COCOS2D_ROOT}/external/Box2D)
endif()

# unzip library
add_subdirectory(${COCOS2D_ROOT}/external/unzip)

# tinyxml2 library
add_subdirectory(${COCOS2D_ROOT}/external/tinyxml2)

# audio
add_subdirectory(${COCOS2D_ROOT}/cocos/audio)

# xxhash library
add_subdirectory(${COCOS2D_ROOT}/external/xxhash)

# cocos2d
add_subdirectory(${COCOS2D_ROOT}/cocos)

# extensions
add_subdirectory(${COCOS2D_ROOT}/extensions)

## Editor Support

# spine
add_subdirectory(${COCOS2D_ROOT}/cocos/editor-support/spine)

# cocosbuilder
add_subdirectory(${COCOS2D_ROOT}/cocos/editor-support/cocosbuilder)

# cocostudio
add_subdirectory(${COCOS2D_ROOT}/cocos/editor-support/cocostudio)

if ( WIN32 )
	# add the executable
	add_executable(${APP_NAME}
	  WIN32
	  ${GAME_SRC} ${CLASSES_SRC}
	)
else()
	# add the executable
	add_executable(${APP_NAME}
	  ${GAME_SRC} ${CLASSES_SRC}
	)
endif()

target_link_libraries(${APP_NAME}
  spine
  cocostudio
  cocosbuilder
  extensions
  audio
  cocos2d
)

set(APP_BIN_DIR "${CMAKE_BINARY_DIR}/bin")

set_target_properties(${APP_NAME} PROPERTIES
     RUNTIME_OUTPUT_DIRECTORY  "${APP_BIN_DIR}")

if(WIN32)
  if(MSVC)
    #also copying dlls to binary directory for the executable to run
    pre_build(${APP_NAME}
      COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}
      COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
      COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/win32-specific/gles/prebuilt/glew32.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
      COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/win32-specific/zlib/prebuilt/zlib1.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
      COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/win32-specific/icon/prebuilt/iconv.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
      COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/curl/prebuilt/win32/libcurl.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
      COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/websockets/prebuilt/win32/websockets.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
      COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/sqlite3/libraries/win32/sqlite3.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
	  )
  else()
    pre_build(${APP_NAME}
      COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}
      COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}
      COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/curl/prebuilt/win32/libcurl.dll ${APP_BIN_DIR}
      COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/websockets/prebuilt/win32/websockets.dll ${APP_BIN_DIR}
      COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/sqlite3/libraries/win32/sqlite3.dll ${APP_BIN_DIR}
      )
  endif()
else()
  pre_build(${APP_NAME}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}
    )

endif()

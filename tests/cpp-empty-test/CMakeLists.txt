cmake_minimum_required(VERSION 2.8)

set(APP_NAME cpp-empty-test)

if(QT)
  set(PLATFORM_SRC
    proj.qt/main.cpp
  )
elseif(ANDROID)
  set(PLATFORM_SRC
    proj.android/jni/hellocpp/main.cpp
  )
elseif(WIN32)
  set(PLATFORM_SRC
    proj.win32/main.cpp
  )
elseif(APPLE)
  if(IOS)
    set(PLATFORM_SRC
      proj.ios/main.m
      proj.ios/AppController.mm
      proj.ios/RootViewController.mm
    )
  else()
    set(PLATFORM_SRC
      proj.mac/main.cpp
    )
  endif()
else()
  set(PLATFORM_SRC
    proj.linux/main.cpp
  )
  endif()

set(SAMPLE_SRC
  Classes/AppDelegate.cpp
  Classes/HelloWorldScene.cpp
  ${PLATFORM_SRC}
)

if ( WIN32 )
	# add the executable
	add_executable(${APP_NAME}
	  WIN32
	  ${SAMPLE_SRC}
	)
else()
	# add the executable
	add_executable(${APP_NAME}
	  ${SAMPLE_SRC}
	)
endif()

target_link_libraries(${APP_NAME} audio cocos2d)

set(APP_BIN_DIR "${CMAKE_BINARY_DIR}/bin/${APP_NAME}")

set_target_properties(${APP_NAME} PROPERTIES
     RUNTIME_OUTPUT_DIRECTORY  "${APP_BIN_DIR}")

if(WIN32 AND MSVC)
pre_build(${APP_NAME}
  COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../external/win32-specific/zlib/prebuilt/zlib1.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../external/win32-specific/gles/prebuilt/glew32.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../external/win32-specific/icon/prebuilt/iconv.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
)
else()
pre_build(${APP_NAME}
  COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}
)
endif()


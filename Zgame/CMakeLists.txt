cmake_minimum_required(VERSION 3.14)

project(Zgame)

set(CMAKE_CXX_STANDARD 17)

# Find the QtWidgets library
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# List of source files
set(SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/gameengine.cpp
        src/room.cpp
        src/basicroom.cpp
        src/item.cpp
        src/player.cpp
        src/secrets.cpp
)

# List of header files
set(HEADERS
        include/mainwindow.h
        include/gameengine.h
        include/room.h
        include/basicroom.h
        include/item.h
        include/player.h
        include/secrets.h
)

# Ensure MOC (Meta-Object Compiler) is run on the headers
qt6_wrap_cpp(MOC_SOURCES ${HEADERS})

# Add the executable
add_executable(Zgame ${SOURCES} ${MOC_SOURCES}
        include/itemContainer.h
        include/describable.h
        include/game_exception.h
        include/variant.h
)

# Link the QtWidgets library
target_link_libraries(Zgame Qt6::Widgets)



if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

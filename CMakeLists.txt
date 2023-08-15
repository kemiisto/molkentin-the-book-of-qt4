cmake_minimum_required(VERSION 3.1)

project(molkentin-the-book-of-qt4 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_QT5 "Enable this if you want to use Qt 5, instead of Qt 6" OFF)

if(USE_QT5)
    message(STATUS "Using Qt 5")
    find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
else()
    message(STATUS "Using Qt 6")
    find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
endif()
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

macro(SUBDIRLIST result curdir pattern)
    file(GLOB children RELATIVE ${curdir} ${curdir}/${pattern})
    set(dirlist "")
    foreach(child ${children})
        if(IS_DIRECTORY ${curdir}/${child})
            list(APPEND dirlist ${child})
        endif()
    endforeach()
    set(${result} ${dirlist})
endmacro()

function(create_project_from_sources chapter demo)
    file(GLOB SOURCE ${chapter}/${demo}/*.cpp ${chapter}/${demo}/*.qrc)
    set(NAME "${chapter}-${demo}")
    if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
        qt_add_executable(${NAME} MANUAL_FINALIZATION ${SOURCE})
    else()
        add_executable(${NAME} ${SOURCE})
    endif()
    target_link_libraries(${NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
    if(QT_VERSION_MAJOR EQUAL 6)
        qt_finalize_executable(${NAME})
    endif()

    if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        if(CMAKE_BUILD_TYPE STREQUAL "Debug")
            find_program(WINDEPLOYQT NAMES windeployqt.debug.bat REQUIRED)
        else()
            find_program(WINDEPLOYQT NAMES windeployqt REQUIRED)
        endif()
        add_custom_command(TARGET ${NAME} POST_BUILD
            COMMAND ${WINDEPLOYQT}
            $<TARGET_FILE:${NAME}>
            COMMENT "Running windeployqt..."
        )
    endif()
endfunction()

SUBDIRLIST(CHAPTERS ${CMAKE_SOURCE_DIR} ch*)

foreach(CHAPTER ${CHAPTERS})
    message(STATUS "Configuring examples for chapter ${CHAPTER}")
    SUBDIRLIST(EXAMPLES ${CMAKE_SOURCE_DIR}/${CHAPTER} *)
    foreach(EXAMPLE ${EXAMPLES})
        message(STATUS "Configuring example ${CHAPTER}-${EXAMPLE}")
        create_project_from_sources(${CHAPTER} ${EXAMPLE})
    endforeach(EXAMPLE)
endforeach(CHAPTER)

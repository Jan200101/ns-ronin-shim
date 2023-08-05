cmake_minimum_required(VERSION 3.10)

list(APPEND
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/shim.c
)

project(shim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VS_PLATFORM_TOOLSET v143)

if (NOT WIN32)
    message(FATAL_ERROR "Windows only")
endif()

add_library(shim_objects OBJECT ${SOURCES})
set_property(TARGET shim_objects PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET shim_objects PROPERTY C_VISIBILITY_PRESET hidden)
set_property(TARGET shim_objects PROPERTY VISIBILITY_INLINES_HIDDEN ON)

add_library(shim SHARED $<TARGET_OBJECTS:shim_objects>)
set_target_properties(shim PROPERTIES
    OUTPUT_NAME Northstar
    PREFIX ""
)

if (MSVC)
    target_link_options(shim PRIVATE /MANIFEST:NO)
endif()
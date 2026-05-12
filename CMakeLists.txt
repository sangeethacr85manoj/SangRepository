cmake_minimum_required(VERSION 3.20)
project(TelemetryProcessingSystem LANGUAGES CXX)

# Project version
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Compiler flags
if(MSVC)
    add_compile_options(/W4 /permissive- /EHsc /fp:precise)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wno-long-long)
endif()

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/core/include
    ${CMAKE_CURRENT_SOURCE_DIR}/modules
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party
)

# Add subdirectories
add_subdirectory(core)
add_subdirectory(modules)
add_subdirectory(tests)

# Main executable
add_executable(TelemetryProcessingApp
    src/main.cpp
)

target_link_libraries(TelemetryProcessingApp
    TelemetryCore
    IngestionModule
    TransformationModule
    AnalyticsModule
    ExporterModule
)

# Installation
install(TARGETS TelemetryProcessingApp RUNTIME DESTINATION bin)

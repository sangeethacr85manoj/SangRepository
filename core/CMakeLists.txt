# TelemetryProcessingSystem Core Module

file(GLOB_RECURSE CORE_SOURCES "src/*.cpp")
file(GLOB_RECURSE CORE_HEADERS "include/*.h" "include/*.hpp")

add_library(TelemetryCore STATIC
    ${CORE_SOURCES}
    ${CORE_HEADERS}
)

target_include_directories(TelemetryCore
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(TelemetryCore PRIVATE _CORE_MODULE_EXPORT)

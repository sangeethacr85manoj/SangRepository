# Ingestion Module

file(GLOB_RECURSE MODULE_SOURCES "src/*.cpp")
file(GLOB_RECURSE MODULE_HEADERS "include/*.h" "include/*.hpp")

add_library(ingestionModule STATIC
    ${MODULE_SOURCES}
    ${MODULE_HEADERS}
)

target_include_directories(ingestionModule
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(ingestionModule PUBLIC TelemetryCore)

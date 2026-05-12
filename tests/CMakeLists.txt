# Unit Tests Configuration

enable_testing()

file(GLOB_RECURSE TEST_SOURCES "unit/*.cpp" "integration/*.cpp")

add_executable(TelemetryTests
    ${TEST_SOURCES}
)

target_include_directories(TelemetryTests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../core/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../modules
)

target_link_libraries(TelemetryTests
    TelemetryCore
    IngestionModule
    TransformationModule
    AnalyticsModule
    ExporterModule
)

add_test(NAME TelemetryTests COMMAND TelemetryTests)

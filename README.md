# TelemetryProcessingSystem

A legacy C++ application for processing large-scale telemetry data in manufacturing environments.

## Project Structure

- **core/**: Core telemetry processing engine
- **modules/**: Feature modules (ingestion, transformation, analytics, exporter)
- **config/**: Configuration files and environment settings
- **tests/**: Unit and integration tests
- **third_party/**: External library dependencies
- **docs/**: Architecture and API documentation
- **build/**: Build scripts and CMake configurations

## Prerequisites

- Visual Studio 2022 with C++ workload
- CMake 3.20+
- Git
- Boost libraries
- Protocol Buffers

## Build Instructions

\\\ash
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
\\\

## Running Tests

\\\ash
cd build
ctest --output-on-failure
\\\

## Architecture

See [docs/architecture/](docs/architecture/) for detailed architecture documentation.

## License

Internal Use Only

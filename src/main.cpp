#include <iostream>
#include "TelemetryProcessor.h"

int main(int argc, char* argv[]) {
    std::cout << "TelemetryProcessingSystem v1.0.0" << std::endl;
    std::cout << "Legacy C++ Application for Manufacturing Telemetry" << std::endl;
    
    Telemetry::Core::TelemetryProcessor processor;
    
    if (!processor.Initialize()) {
        std::cerr << "Failed to initialize processor" << std::endl;
        return 1;
    }
    
    std::cout << "System initialized successfully" << std::endl;
    
    processor.Shutdown();
    return 0;
}

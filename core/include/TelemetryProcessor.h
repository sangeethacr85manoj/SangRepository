#pragma once

namespace Telemetry {
namespace Core {

class TelemetryProcessor {
public:
    TelemetryProcessor();
    ~TelemetryProcessor();
    
    bool Initialize();
    void Process(const void* data, size_t size);
    void Shutdown();
    
private:
    bool initialized_;
};

} // namespace Core
} // namespace Telemetry

#pragma once

#include <vector>
#include <string>

class ParticleSystem {
public:
    // Constructors and Destructor
    ParticleSystem() = delete;
    ParticleSystem(int n);
    ParticleSystem(const std::vector<float>& pos_x, const std::vector<float>& pos_y);
    ParticleSystem(const std::string& file_name);
    ~ParticleSystem();

private:
    // Position
    std::vector<float> pos_x;
    std::vector<float> pos_y;
    
    // Velocity
    std::vector<float> dx;
    std::vector<float> dy;

    // Color
    std::vector<uint8_t> color;
};
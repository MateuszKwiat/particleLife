/////////////////////////////////////////////
//
// Class represents state of N particles.
// Each particle can be represented with 
// five values:
// - (float, float)
//   position on X and Y axis,
//
// - (float, float)
//   vectors parallel to X and Y axis
//   representing velocity,
//
// - (uint8_t)
//   color which corresponds to visuals used
//   for rendering particle and type/species 
//   of particle. 
//
/////////////////////////////////////////////

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
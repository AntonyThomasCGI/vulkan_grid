#pragma once

#include <vector>

#include "geometry/mesh.hpp"


class Line : public Mesh
{
public:
    Line(Device *device) : Mesh(
        device,
        std::vector<Vertex>{
            {{-0.5f, -0.5f}},
            {{0.5f, -0.5f}},
            {{0.5f, 0.5f}},
            {{-0.5f, 0.5f}}
        },
        std::vector<uint16_t>{
            0, 1, 2, 2, 3, 0
        }
    ) {}
};
#pragma once

#include <vector>

#include "vertex.hpp"


class Mesh
{
    Mesh(std::vector<Vertex> &vertices, std::vector<uint16_t> &indicies = {});
};

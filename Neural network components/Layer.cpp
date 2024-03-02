//
// Created by macie on 27/02/2024.
//

#include "Layer.h"

Layer::Layer(Vector nodes, Matrix inWeights, Vector biases): nodes(std::move(nodes)), inWeights(std::move(inWeights)), biases(std::move(biases)) {}

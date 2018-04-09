cmake_minimum_required(VERSION 3.10)
project(nn)

set(CMAKE_CXX_STANDARD 11)

add_executable(nn main.cpp Global/Global.cpp Global/Global.h Neuron/GenericNeuron.cpp Neuron/GenericNeuron.h Neuron/InputLayerNeuron.cpp Neuron/InputLayerNeuron.h Neuron/OutputLayerNeuron.cpp Neuron/OutputLayerNeuron.h Neuron/HiddenLayerNeuron.cpp Neuron/HiddenLayerNeuron.h Layer/GenericLayer.cpp Layer/GenericLayer.h Layer/HiddenLayer.cpp Layer/HiddenLayer.h Layer/InputLayer.cpp Layer/InputLayer.h Layer/OutputLayer.cpp Layer/OutputLayer.h Network/Network.cpp Network/Network.h Global/Declarations.h Connection/Connection.cpp Connection/Connection.h Algorithm/ActivationFunctions.cpp Algorithm/ActivationFunctions.h Algorithm/BackPropagator.cpp Algorithm/BackPropagator.h)
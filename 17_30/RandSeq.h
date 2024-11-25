#pragma once
#include <random>


unsigned randomSequence(unsigned start = std::default_random_engine::default_seed);

unsigned randomSequence(unsigned min, unsigned max, unsigned start = std::default_random_engine::default_seed);
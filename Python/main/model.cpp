#include <math.h>
#include "model.h"
#include "weight.h"

inline float relu(float x) {
    return fmaxf(0.0f, x); 
}

float predict(float x1, float x2) {
    float h1[DENSE1_SIZE];

    // First dense layer.
    for (int i = 0; i < DENSE1_SIZE; ++i) {
        h1[i] = relu(x1 * W1(i) + x2 * W1(DENSE1_SIZE/2 + i) + b1(i));
    }

    // Second dense layer.
    float y = 0.0f;
    for (int i = 0; i < DENSE2_SIZE; ++i) {
        float h2 = 0.0f;
        for (int j = 0; j < DENSE1_SIZE; ++j) {
            h2 += h1[j] * W2(i, j);
        }
        h2 = relu(h2 + b2(i));
        y += h2 * W3(i);
    }

    // Final dense layer.
    return y + b3();
}
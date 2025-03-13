// Copyright (c) 2025. BNU-HKBU UIC RoboMaster
//
// This program is free software: you can redistribute it
// and/or modify it under the terms of the GNU General
// Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even
// the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU General
// Public License along with this program.  If not, see
// <https://www.gnu.org/licenses/>.

#ifndef WEIGHT_H
#define WEIGHT_H

extern const float W_relu[];
extern const float b_relu[];
extern const float W_relu2[];
extern const float b_relu2[];
extern const float W_output[];
extern const float b_output[];

const int DENSE1_SIZE = 32;
const int DENSE2_SIZE = 16;

inline float W1(int i) {
    return *(W_relu + i);
}

inline float b1(int i) {
    return *(b_relu + i);
}

inline float W2(int i, int j) {
    return *(W_relu2 + i * DENSE1_SIZE + j);
}

inline float b2(int i) {
    return *(b_relu2 + i);
}

inline float W3(int i) {
    return *(W_output + i);
}

inline float b3() {
    return *b_output;
}

#endif  // WEIGHT_H

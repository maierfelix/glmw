#include <webassembly.h>
#include <math.h>
#include "common.h"

#define vec4(x) vec4_##x

/**
 * Frees a vec4
 */
export float *vec4(free)(float *a) {
  free(a);
  return NULL;
};

/**
 * Creates a new, empty vec4
 *
 * @returns {vec4} a new 3D vector
 */
export float *vec4(create)() {
  float *out = malloc(VEC_SIZE_4 * sizeof(*out));
  out[0] = 0;
  out[1] = 0;
  out[2] = 0;
  out[3] = 0;
  return out;
};

/**
 * Creates a new vec4 initialized with values from an existing vector
 *
 * @param {vec4} a vector to clone
 * @returns {vec4} a new 4D vector
 */
export float *vec4(clone)(float *a) {
  float *out = malloc(VEC_SIZE_4 * sizeof(*out));
  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return out;
};

/**
 * Creates a new vec4 initialized with the given values
 *
 * @param {Number} x X component
 * @param {Number} y Y component
 * @param {Number} z Z component
 * @param {Number} w W component
 * @returns {vec4} a new 4D vector
 */
export float *vec4(fromValues)(float x, float y, float z, float w) {
  float *out = malloc(VEC_SIZE_4 * sizeof(*out));
  out[0] = x;
  out[1] = y;
  out[2] = z;
  out[3] = w;
  return out;
};

/**
 * Copy the values from one vec4 to another
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the source vector
 * @returns {vec4} out
 */
export float *vec4(copy)(float *out, float *a) {
  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return out;
};

/**
 * Set the components of a vec4 to the given values
 *
 * @param {vec4} out the receiving vector
 * @param {Number} x X component
 * @param {Number} y Y component
 * @param {Number} z Z component
 * @param {Number} w W component
 * @returns {vec4} out
 */
export float *vec4(set)(float *out, float x, float y, float z, float w) {
  out[0] = x;
  out[1] = y;
  out[2] = z;
  out[3] = w;
  return out;
};

/**
 * Adds two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {vec4} out
 */
export float *vec4(add)(float *out, float *a, float *b) {
  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  return out;
};

/**
 * Subtracts vector b from vector a
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {vec4} out
 */
export float *vec4(subtract)(float *out, float *a, float *b) {
  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  out[3] = a[3] - b[3];
  return out;
};

/**
 * Multiplies two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {vec4} out
 */
export float *vec4(multiply)(float *out, float *a, float *b) {
  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  out[2] = a[2] * b[2];
  out[3] = a[3] * b[3];
  return out;
};

/**
 * Divides two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {vec4} out
 */
export float *vec4(divide)(float *out, float *a, float *b) {
  out[0] = a[0] / b[0];
  out[1] = a[1] / b[1];
  out[2] = a[2] / b[2];
  out[3] = a[3] / b[3];
  return out;
};

/**
 * Math.ceil the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to ceil
 * @returns {vec4} out
 */
export float *vec4(ceil)(float *out, float *a) {
  out[0] = ceilf(a[0]);
  out[1] = ceilf(a[1]);
  out[2] = ceilf(a[2]);
  out[3] = ceilf(a[3]);
  return out;
};

/**
 * Math.floor the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to floor
 * @returns {vec4} out
 */
export float *vec4(floor)(float *out, float *a) {
  out[0] = floorf(a[0]);
  out[1] = floorf(a[1]);
  out[2] = floorf(a[2]);
  out[3] = floorf(a[3]);
  return out;
};

/**
 * Returns the minimum of two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {vec4} out
 */
export float *vec4(min)(float *out, float *a, float *b) {
  out[0] = fminf(a[0], b[0]);
  out[1] = fminf(a[1], b[1]);
  out[2] = fminf(a[2], b[2]);
  out[3] = fminf(a[3], b[3]);
  return out;
};

/**
 * Returns the maximum of two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {vec4} out
 */
export float *vec4(max)(float *out, float *a, float *b) {
  out[0] = fmaxf(a[0], b[0]);
  out[1] = fmaxf(a[1], b[1]);
  out[2] = fmaxf(a[2], b[2]);
  out[3] = fmaxf(a[3], b[3]);
  return out;
};

/**
 * Math.round the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to round
 * @returns {vec4} out
 */
export float *vec4(round)(float *out, float *a) {
  out[0] = roundf(a[0]);
  out[1] = roundf(a[1]);
  out[2] = roundf(a[2]);
  out[3] = roundf(a[3]);
  return out;
};

/**
 * Scales a vec4 by a scalar number
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the vector to scale
 * @param {Number} b amount to scale the vector by
 * @returns {vec4} out
 */
export float *vec4(scale)(float *out, float *a, float b) {
  out[0] = a[0] * b;
  out[1] = a[1] * b;
  out[2] = a[2] * b;
  out[3] = a[3] * b;
  return out;
};

/**
 * Adds two vec4's after scaling the second operand by a scalar value
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @param {Number} scale the amount to scale b by before adding
 * @returns {vec4} out
 */
export float *vec4(scaleAndAdd)(float *out, float *a, float *b, float scale) {
  out[0] = a[0] + (b[0] * scale);
  out[1] = a[1] + (b[1] * scale);
  out[2] = a[2] + (b[2] * scale);
  out[3] = a[3] + (b[3] * scale);
  return out;
};

/**
 * Calculates the euclidian distance between two vec4's
 *
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {Number} distance between a and b
 */
export float vec4(distance)(float *a, float *b) {
  float x = b[0] - a[0];
  float y = b[1] - a[1];
  float z = b[2] - a[2];
  float w = b[3] - a[3];
  return sqrtf(x*x + y*y + z*z + w*w);
};

/**
 * Calculates the squared euclidian distance between two vec4's
 *
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {Number} squared distance between a and b
 */
export float vec4(squaredDistance)(float *a, float *b) {
  float x = b[0] - a[0];
  float y = b[1] - a[1];
  float z = b[2] - a[2];
  float w = b[3] - a[3];
  return x*x + y*y + z*z + w*w;
};

/**
 * Calculates the length of a vec4
 *
 * @param {vec4} a vector to calculate length of
 * @returns {Number} length of a
 */
export float vec4(length)(float *a) {
  float x = a[0];
  float y = a[1];
  float z = a[2];
  float w = a[3];
  return sqrtf(x*x + y*y + z*z + w*w);
};

/**
 * Calculates the squared length of a vec4
 *
 * @param {vec4} a vector to calculate squared length of
 * @returns {Number} squared length of a
 */
export float vec4(squaredLength)(float *a) {
  float x = a[0];
  float y = a[1];
  float z = a[2];
  float w = a[3];
  return x*x + y*y + z*z + w*w;
};

/**
 * Negates the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to negate
 * @returns {vec4} out
 */
export float *vec4(negate)(float *out, float *a) {
  out[0] = -a[0];
  out[1] = -a[1];
  out[2] = -a[2];
  out[3] = -a[3];
  return out;
};

/**
 * Returns the inverse of the components of a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to invert
 * @returns {vec4} out
 */
export float *vec4(inverse)(float *out, float *a) {
  out[0] = 1.0 / a[0];
  out[1] = 1.0 / a[1];
  out[2] = 1.0 / a[2];
  out[3] = 1.0 / a[3];
  return out;
};

/**
 * Normalize a vec4
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a vector to normalize
 * @returns {vec4} out
 */
export float *vec4(normalize)(float *out, float *a) {
  float x = a[0];
  float y = a[1];
  float z = a[2];
  float w = a[3];
  float len = x*x + y*y + z*z + w*w;
  if (len > 0) {
    len = 1 / sqrtf(len);
    out[0] = x * len;
    out[1] = y * len;
    out[2] = z * len;
    out[3] = w * len;
  }
  return out;
};

/**
 * Calculates the dot product of two vec4's
 *
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @returns {Number} dot product of a and b
 */
export float vec4(dot)(float *a, float *b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
};

/**
 * Performs a linear interpolation between two vec4's
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the first operand
 * @param {vec4} b the second operand
 * @param {Number} t interpolation amount between the two inputs
 * @returns {vec4} out
 */
export float *vec4(lerp)(float *out, float *a, float *b, float t) {
  float ax = a[0];
  float ay = a[1];
  float az = a[2];
  float aw = a[3];
  out[0] = ax + t * (b[0] - ax);
  out[1] = ay + t * (b[1] - ay);
  out[2] = az + t * (b[2] - az);
  out[3] = aw + t * (b[3] - aw);
  return out;
};

/**
 * Generates a random vector with the given scale
 *
 * @param {vec4} out the receiving vector
 * @param {Number} [scale] Length of the resulting vector. If ommitted, a unit vector will be returned
 * @returns {vec4} out
 */
export float *vec4(random)(float *out, float scale) {
  //vectorScale = vectorScale || 1.0;
  //TODO: This is a pretty awful way of doing this. Find something better.
  out[0] = randf();
  out[1] = randf();
  out[2] = randf();
  out[3] = randf();
  vec3(normalize)(out, out);
  vec3(scale)(out, out, scale);
  return out;
};

/**
 * Transforms the vec4 with a mat4.
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the vector to transform
 * @param {mat4} m matrix to transform with
 * @returns {vec4} out
 */
export float *vec4(transformMat4)(float *out, float *a, float *m) {
  float x = a[0], y = a[1], z = a[2], w = a[3];
  out[0] = m[0] * x + m[4] * y + m[8] * z + m[12] * w;
  out[1] = m[1] * x + m[5] * y + m[9] * z + m[13] * w;
  out[2] = m[2] * x + m[6] * y + m[10] * z + m[14] * w;
  out[3] = m[3] * x + m[7] * y + m[11] * z + m[15] * w;
  return out;
};

/**
 * Transforms the vec4 with a quat
 *
 * @param {vec4} out the receiving vector
 * @param {vec4} a the vector to transform
 * @param {quat} q quaternion to transform with
 * @returns {vec4} out
 */
export float *vec4(transformQuat)(float *out, float *a, float *q) {
  float x = a[0], y = a[1], z = a[2];
  float qx = q[0], qy = q[1], qz = q[2], qw = q[3];
  // calculate quat * vec
  float ix = qw * x + qy * z - qz * y;
  float iy = qw * y + qz * x - qx * z;
  float iz = qw * z + qx * y - qy * x;
  float iw = -qx * x - qy * y - qz * z;
  // calculate result * inverse quat
  out[0] = ix * qw + iw * -qx + iy * -qz - iz * -qy;
  out[1] = iy * qw + iw * -qy + iz * -qx - ix * -qz;
  out[2] = iz * qw + iw * -qz + ix * -qy - iy * -qx;
  out[3] = a[3];
  return out;
};

/**
 * Returns a string representation of a vector
 *
 * @param {vec4} a vector to represent as a string
 * @returns {String} string representation of the vector
 */
export float *vec4(str)(float *a) {
  return a;
};

/**
 * Returns whether or not the vectors have exactly the same elements in the same position (when compared with ===)
 *
 * @param {vec4} a The first vector.
 * @param {vec4} b The second vector.
 * @returns {Boolean} True if the vectors are equal, false otherwise.
 */
export int vec4(exactEquals)(float *a, float *b) {
  return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
};

/**
 * Returns whether or not the vectors have approximately the same elements in the same position.
 *
 * @param {vec4} a The first vector.
 * @param {vec4} b The second vector.
 * @returns {Boolean} True if the vectors are equal, false otherwise.
 */
export int vec4(equals)(float *a, float *b) {
  float a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
  float b0 = b[0], b1 = b[1], b2 = b[2], b3 = b[3];
  return (fabs(a0 - b0) <= EPSILON*fmaxf(1.0, fmaxf(fabs(a0), fabs(b0))) &&
          fabs(a1 - b1) <= EPSILON*fmaxf(1.0, fmaxf(fabs(a1), fabs(b1))) &&
          fabs(a2 - b2) <= EPSILON*fmaxf(1.0, fmaxf(fabs(a2), fabs(b2))) &&
          fabs(a3 - b3) <= EPSILON*fmaxf(1.0, fmaxf(fabs(a3), fabs(b3))));
};

/**
 * Alias for {@link vec4.subtract}
 * @function
 */
export float *vec4(sub)(float *out, float *a, float *b) {
  return vec4(subtract)(out, a, b);
};

/**
 * Alias for {@link vec4.multiply}
 * @function
 */
export float *vec4(mul)(float *out, float *a, float *b) {
  return vec4(multiply)(out, a, b);
};

/**
 * Alias for {@link vec4.divide}
 * @function
 */
export float *vec4(div)(float *out, float *a, float *b) {
  return vec4(divide)(out, a, b);
};

/**
 * Alias for {@link vec4.distance}
 * @function
 */
export float vec4(dist)(float *a, float *b) {
  return vec4(distance)(a, b);
};

/**
 * Alias for {@link vec4.squaredDistance}
 * @function
 */
export float vec4(sqrDist)(float *a, float *b) {
  return vec4(squaredDistance)(a, b);
};

/**
 * Alias for {@link vec4.length}
 * @function
 */
export float vec4(len)(float *a) {
  return vec4(length)(a);
};

/**
 * Alias for {@link vec4.squaredLength}
 * @function
 */
export float vec4(sqrLen)(float *a) {
  return vec4(squaredLength)(a);
};

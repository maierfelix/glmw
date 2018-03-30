#include <webassembly.h>
#include <math.h>
#include "common.h"

#define vec3(x) vec3_##x

/**
 * Frees a vec3
 */
export float *vec3(free)(float *a) {
  free(a);
  return NULL;
};

/**
 * Creates a new, empty vec3
 *
 * @returns {vec3} a new 3D vector
 */
export float *vec3(create)() {
  float *out = malloc(VEC_SIZE_3 * sizeof(*out));
  out[0] = 0;
  out[1] = 0;
  out[2] = 0;
  return out;
};

/**
 * Creates a new vec3 initialized with values from an existing vector
 *
 * @param {vec3} a vector to clone
 * @returns {vec3} a new 3D vector
 */
export float *vec3(clone)(float *a) {
  float *out = malloc(VEC_SIZE_3 * sizeof(*out));
  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  return out;
};

/**
 * Calculates the length of a vec3
 *
 * @param {vec3} a vector to calculate length of
 * @returns {Number} length of a
 */
export float vec3(length)(float *a) {
  float x = a[0];
  float y = a[1];
  float z = a[2];
  return sqrtf(x*x + y*y + z*z);
};

/**
 * Creates a new vec3 initialized with the given values
 *
 * @param {Number} x X component
 * @param {Number} y Y component
 * @param {Number} z Z component
 * @returns {vec3} a new 3D vector
 */
export float *vec3(fromValues)(float x, float y, float z) {
  float *out = malloc(VEC_SIZE_3 * sizeof(*out));
  out[0] = x;
  out[1] = y;
  out[2] = z;
  return out;
};

/**
 * Copy the values from one vec3 to another
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the source vector
 * @returns {vec3} out
 */
export float *vec3(copy)(float *out, float *a) {
  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  return out;
};

/**
 * Set the components of a vec3 to the given values
 *
 * @param {vec3} out the receiving vector
 * @param {Number} x X component
 * @param {Number} y Y component
 * @param {Number} z Z component
 * @returns {vec3} out
 */
export float *vec3(set)(float *out, float x, float y, float z) {
  out[0] = x;
  out[1] = y;
  out[2] = z;
  return out;
};

/**
 * Adds two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {vec3} out
 */
export float *vec3(add)(float *out, float *a, float *b) {
  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  return out;
};

/**
 * Subtracts vector b from vector a
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {vec3} out
 */
export float *vec3(subtract)(float *out, float *a, float *b) {
  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  return out;
};

/**
 * Multiplies two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {vec3} out
 */
export float *vec3(multiply)(float *out, float *a, float *b) {
  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  out[2] = a[2] * b[2];
  return out;
};

/**
 * Divides two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {vec3} out
 */
export float *vec3(divide)(float *out, float *a, float *b) {
  out[0] = a[0] / b[0];
  out[1] = a[1] / b[1];
  out[2] = a[2] / b[2];
  return out;
};

/**
 * Math.ceil the components of a vec3
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a vector to ceil
 * @returns {vec3} out
 */
export float *vec3(ceil)(float *out, float *a) {
  out[0] = ceilf(a[0]);
  out[1] = ceilf(a[1]);
  out[2] = ceilf(a[2]);
  return out;
};

/**
 * Math.floor the components of a vec3
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a vector to floor
 * @returns {vec3} out
 */
export float *vec3(floor)(float *out, float *a) {
  out[0] = floorf(a[0]);
  out[1] = floorf(a[1]);
  out[2] = floorf(a[2]);
  return out;
};

/**
 * Returns the minimum of two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {vec3} out
 */
export float *vec3(min)(float *out, float *a, float *b) {
  out[0] = fminf(a[0], b[0]);
  out[1] = fminf(a[1], b[1]);
  out[2] = fminf(a[2], b[2]);
  return out;
};

/**
 * Returns the maximum of two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {vec3} out
 */
export float *vec3(max)(float *out, float *a, float *b) {
  out[0] = fmaxf(a[0], b[0]);
  out[1] = fmaxf(a[1], b[1]);
  out[2] = fmaxf(a[2], b[2]);
  return out;
};

/**
 * Math.round the components of a vec3
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a vector to round
 * @returns {vec3} out
 */
export float *vec3(round)(float *out, float *a) {
  out[0] = roundf(a[0]);
  out[1] = roundf(a[1]);
  out[2] = roundf(a[2]);
  return out;
};

/**
 * Scales a vec3 by a scalar number
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the vector to scale
 * @param {Number} b amount to scale the vector by
 * @returns {vec3} out
 */
export float *vec3(scale)(float *out, float *a, float b) {
  out[0] = a[0] * b;
  out[1] = a[1] * b;
  out[2] = a[2] * b;
  return out;
};

/**
 * Adds two vec3's after scaling the second operand by a scalar value
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @param {Number} scale the amount to scale b by before adding
 * @returns {vec3} out
 */
export float *vec3(scaleAndAdd)(float *out, float *a, float *b, float scale) {
  out[0] = a[0] + (b[0] * scale);
  out[1] = a[1] + (b[1] * scale);
  out[2] = a[2] + (b[2] * scale);
  return out;
};

/**
 * Calculates the euclidian distance between two vec3's
 *
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {Number} distance between a and b
 */
export float vec3(distance)(float *a, float *b) {
  float x = b[0] - a[0];
  float y = b[1] - a[1];
  float z = b[2] - a[2];
  return sqrtf(x*x + y*y + z*z);
};

/**
 * Calculates the squared euclidian distance between two vec3's
 *
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {Number} squared distance between a and b
 */
export float vec3(squaredDistance)(float *a, float *b) {
  float x = b[0] - a[0];
  float y = b[1] - a[1];
  float z = b[2] - a[2];
  return x*x + y*y + z*z;
};

/**
 * Calculates the squared length of a vec3
 *
 * @param {vec3} a vector to calculate squared length of
 * @returns {Number} squared length of a
 */
export float vec3(squaredLength)(float *a) {
  float x = a[0];
  float y = a[1];
  float z = a[2];
  return x*x + y*y + z*z;
};

/**
 * Negates the components of a vec3
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a vector to negate
 * @returns {vec3} out
 */
export float *vec3(negate)(float *out, float *a) {
  out[0] = -a[0];
  out[1] = -a[1];
  out[2] = -a[2];
  return out;
};

/**
 * Returns the inverse of the components of a vec3
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a vector to invert
 * @returns {vec3} out
 */
export float *vec3(inverse)(float *out, float *a) {
  out[0] = 1.0 / a[0];
  out[1] = 1.0 / a[1];
  out[2] = 1.0 / a[2];
  return out;
};

/**
 * Normalize a vec3
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a vector to normalize
 * @returns {vec3} out
 */
export float *vec3(normalize)(float *out, float *a) {
  float x = a[0];
  float y = a[1];
  float z = a[2];
  float len = x*x + y*y + z*z;
  if (len > 0) {
    //TODO: evaluate use of glm_invsqrt here?
    len = 1 / sqrtf(len);
    out[0] = a[0] * len;
    out[1] = a[1] * len;
    out[2] = a[2] * len;
  }
  return out;
};

/**
 * Calculates the dot product of two vec3's
 *
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {Number} dot product of a and b
 */
export float vec3(dot)(float *a, float *b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
};

/**
 * Computes the cross product of two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @returns {vec3} out
 */
export float *vec3(cross)(float *out, float *a, float *b) {
  float ax = a[0], ay = a[1], az = a[2];
  float bx = b[0], by = b[1], bz = b[2];
  out[0] = ay * bz - az * by;
  out[1] = az * bx - ax * bz;
  out[2] = ax * by - ay * bx;
  return out;
};

/**
 * Performs a linear interpolation between two vec3's
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @param {Number} t interpolation amount between the two inputs
 * @returns {vec3} out
 */
export float *vec3(lerp)(float *out, float *a, float *b, float t) {
  float ax = a[0];
  float ay = a[1];
  float az = a[2];
  out[0] = ax + t * (b[0] - ax);
  out[1] = ay + t * (b[1] - ay);
  out[2] = az + t * (b[2] - az);
  return out;
};

/**
 * Performs a hermite interpolation with two control points
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @param {vec3} c the third operand
 * @param {vec3} d the fourth operand
 * @param {Number} t interpolation amount between the two inputs
 * @returns {vec3} out
 */
export float *vec3(hermite)(float *out, float *a, float *b, float *c, float *d, float t) {
  float factorTimes2 = t * t;
  float factor1 = factorTimes2 * (2 * t - 3) + 1;
  float factor2 = factorTimes2 * (t - 2) + t;
  float factor3 = factorTimes2 * (t - 1);
  float factor4 = factorTimes2 * (3 - 2 * t);
  out[0] = a[0] * factor1 + b[0] * factor2 + c[0] * factor3 + d[0] * factor4;
  out[1] = a[1] * factor1 + b[1] * factor2 + c[1] * factor3 + d[1] * factor4;
  out[2] = a[2] * factor1 + b[2] * factor2 + c[2] * factor3 + d[2] * factor4;
  return out;
};

/**
 * Performs a bezier interpolation with two control points
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the first operand
 * @param {vec3} b the second operand
 * @param {vec3} c the third operand
 * @param {vec3} d the fourth operand
 * @param {Number} t interpolation amount between the two inputs
 * @returns {vec3} out
 */
export float *vec3(bezier)(float *out, float *a, float *b, float *c, float *d, float t) {
  float inverseFactor = 1 - t;
  float inverseFactorTimesTwo = inverseFactor * inverseFactor;
  float factorTimes2 = t * t;
  float factor1 = inverseFactorTimesTwo * inverseFactor;
  float factor2 = 3 * t * inverseFactorTimesTwo;
  float factor3 = 3 * factorTimes2 * inverseFactor;
  float factor4 = factorTimes2 * t;
  out[0] = a[0] * factor1 + b[0] * factor2 + c[0] * factor3 + d[0] * factor4;
  out[1] = a[1] * factor1 + b[1] * factor2 + c[1] * factor3 + d[1] * factor4;
  out[2] = a[2] * factor1 + b[2] * factor2 + c[2] * factor3 + d[2] * factor4;
  return out;
};

/**
 * Generates a random vector with the given scale
 *
 * @param {vec3} out the receiving vector
 * @param {Number} [scale] Length of the resulting vector. If ommitted, a unit vector will be returned
 * @returns {vec3} out
 */
export float *vec3(random)(float *out, float scale) {
  float r = randf() * 2.0 * PI;
  float z = (randf() * 2.0) - 1.0;
  float zScale = sqrtf(1.0-z*z) * scale;
  out[0] = cosf(r) * zScale;
  out[1] = sinf(r) * zScale;
  out[2] = z * scale;
  return out;
};

/**
 * Transforms the vec3 with a mat4.
 * 4th vector component is implicitly '1'
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the vector to transform
 * @param {mat4} m matrix to transform with
 * @returns {vec3} out
 */
export float *vec3(transformMat4)(float *out, float *a, float *m) {
  float x = a[0], y = a[1], z = a[2];
  float w = m[3] * x + m[7] * y + m[11] * z + m[15];
  if (!w) w = w || 1.0;
  out[0] = (m[0] * x + m[4] * y + m[8] * z + m[12]) / w;
  out[1] = (m[1] * x + m[5] * y + m[9] * z + m[13]) / w;
  out[2] = (m[2] * x + m[6] * y + m[10] * z + m[14]) / w;
  return out;
};

/**
 * Transforms the vec3 with a mat3.
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the vector to transform
 * @param {mat3} m the 3x3 matrix to transform with
 * @returns {vec3} out
 */
export float *vec3(transformMat3)(float *out, float *a, float *m) {
  float x = a[0], y = a[1], z = a[2];
  out[0] = x * m[0] + y * m[3] + z * m[6];
  out[1] = x * m[1] + y * m[4] + z * m[7];
  out[2] = x * m[2] + y * m[5] + z * m[8];
  return out;
};

/**
 * Transforms the vec3 with a quat
 *
 * @param {vec3} out the receiving vector
 * @param {vec3} a the vector to transform
 * @param {quat} q quaternion to transform with
 * @returns {vec3} out
 */
export float *vec3(transformQuat)(float *out, float *a, float *q) {
  // benchmarks: http://jsperf.com/quaternion-transform-vec3-implementations
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
  return out;
};

/**
 * Rotate a 3D vector around the x-axis
 * @param {vec3} out The receiving vec3
 * @param {vec3} a The vec3 point to rotate
 * @param {vec3} b The origin of the rotation
 * @param {Number} c The angle of rotation
 * @returns {vec3} out
 */
export float *vec3(rotateX)(float *out, float *a, float *b, float c) {
  float p0, p1, p2;
  float r0, r1, r2;
  //Translate point to the origin
  p0 = a[0] - b[0];
  p1 = a[1] - b[1];
  p2 = a[2] - b[2];
  //perform rotation
  r0 = p0;
  r1 = p1*cosf(c) - p2*sinf(c);
  r2 = p2*sinf(c) + p2*cosf(c);
  //translate to correct position
  out[0] = r0 + b[0];
  out[1] = r1 + b[1];
  out[2] = r2 + b[2];
  return out;
};

/**
 * Rotate a 3D vector around the y-axis
 * @param {vec3} out The receiving vec3
 * @param {vec3} a The vec3 point to rotate
 * @param {vec3} b The origin of the rotation
 * @param {Number} c The angle of rotation
 * @returns {vec3} out
 */
export float *vec3(rotateY)(float *out, float *a, float *b, float c) {
  float p0, p1, p2;
  float r0, r1, r2;
  //Translate point to the origin
  p0 = a[0] - b[0];
  p1 = a[1] - b[1];
  p2 = a[2] - b[2];
  //perform rotation
  r0 = p2*sinf(c) + p0*cosf(c);
  r1 = p1;
  r2 = p2*cosf(c) - p1*sinf(c);
  //translate to correct position
  out[0] = r0 + b[0];
  out[1] = r1 + b[1];
  out[2] = r2 + b[2];
  return out;
};

/**
 * Rotate a 3D vector around the z-axis
 * @param {vec3} out The receiving vec3
 * @param {vec3} a The vec3 point to rotate
 * @param {vec3} b The origin of the rotation
 * @param {Number} c The angle of rotation
 * @returns {vec3} out
 */
export float *vec3(rotateZ)(float *out, float *a, float *b, float c) {
  float p0, p1, p2;
  float r0, r1, r2;
  //Translate point to the origin
  p0 = a[0] - b[0];
  p1 = a[1] - b[1];
  p2 = a[2] - b[2];
  //perform rotation
  r0 = p0*cosf(c) - p1*sinf(c);
  r1 = p0*sinf(c) + p1*cosf(c);
  r2 = p2;
  //translate to correct position
  out[0] = r0 + b[0];
  out[1] = r1 + b[1];
  out[2] = r2 + b[2];
  return out;
};

float aH0[VEC_SIZE_3] = { 0.0, 0.0, 0.0 };
float aH1[VEC_SIZE_3] = { 0.0, 0.0, 0.0 };
/**
 * Get the angle between two 3D vectors
 * @param {vec3} a The first operand
 * @param {vec3} b The second operand
 * @returns {Number} The angle in radians
 */
export float vec3(angle)(float *a, float *b) {
  // hacky helper to avoid allocation
  // but remain self api usage
  aH0[0] = a[0]; aH0[1] = a[1]; aH0[2] = a[2];
  aH1[0] = b[0]; aH1[1] = b[1]; aH1[2] = b[2];
  float *tempA = aH0;
  float *tempB = aH1;
  vec3(normalize)(tempA, tempA);
  vec3(normalize)(tempB, tempB);
  float cosine = vec3(dot)(tempA, tempB);
  if(cosine > 1.0) {
    return 0;
  }
  else if(cosine < -1.0) {
    return PI;
  } else {
    return acosf(cosine);
  }
};

/**
 * Returns a string representation of a vector
 *
 * @param {vec3} a vector to represent as a string
 * @returns {String} string representation of the vector
 */
export float *vec3(str)(float *a) {
  return a;
};

/**
 * Returns whether or not the vectors have exactly the same elements in the same position (when compared with ===)
 *
 * @param {vec3} a The first vector.
 * @param {vec3} b The second vector.
 * @returns {Boolean} True if the vectors are equal, false otherwise.
 */
export int vec3(exactEquals)(float *a, float *b) {
  return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
};

/**
 * Returns whether or not the vectors have approximately the same elements in the same position.
 *
 * @param {vec3} a The first vector.
 * @param {vec3} b The second vector.
 * @returns {Boolean} True if the vectors are equal, false otherwise.
 */
export int vec3(equals)(float *a, float *b) {
  float a0 = a[0], a1 = a[1], a2 = a[2];
  float b0 = b[0], b1 = b[1], b2 = b[2];
  return (fabs(a0 - b0) <= EPSILON*fmaxf(1.0, fmaxf(fabs(a0), fabs(b0))) &&
          fabs(a1 - b1) <= EPSILON*fmaxf(1.0, fmaxf(fabs(a1), fabs(b1))) &&
          fabs(a2 - b2) <= EPSILON*fmaxf(1.0, fmaxf(fabs(a2), fabs(b2))));
};

/**
 * Alias for {@link vec3.subtract}
 * @function
 */
export float *vec3(sub)(float *out, float *a, float *b) {
  return vec3(subtract)(out, a, b);
};

/**
 * Alias for {@link vec3.multiply}
 * @function
 */
export float *vec3(mul)(float *out, float *a, float *b) {
  return vec3(multiply)(out, a, b);
};

/**
 * Alias for {@link vec3.divide}
 * @function
 */
export float *vec3(div)(float *out, float *a, float *b) {
  return vec3(divide)(out, a, b);
};

/**
 * Alias for {@link vec3.distance}
 * @function
 */
export float vec3(dist)(float *a, float *b) {
  return vec3(distance)(a, b);
};

/**
 * Alias for {@link vec3.squaredDistance}
 * @function
 */
export float vec3(sqrDist)(float *a, float *b) {
  return vec3(squaredDistance)(a, b);
};

/**
 * Alias for {@link vec3.length}
 * @function
 */
export float vec3(len)(float *a) {
  return vec3(length)(a);
};

/**
 * Alias for {@link vec3.squaredLength}
 * @function
 */
export float vec3(sqrLen)(float *a) {
  return vec3(squaredLength)(a);
};

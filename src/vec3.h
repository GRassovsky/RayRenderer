#ifndef VEC3_H
#define VEC3_H




// System includes
#include <cmath>
#include <iostream>





class vec3
{
	public:
		vec3() : e{0,0,0} {}
		vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

		float x() const { return e[0]; }
		float y() const { return e[1]; }
		float z() const { return e[2]; }

		float r() const { return e[0]; }
		float g() const { return e[1]; }
		float b() const { return e[2]; }

		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		float operator[](int i) const { return e[i]; }
		float& operator[](int i) { return e[i]; }

		vec3& operator+=(const vec3 &v)
		{
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}

		vec3& operator*=(const float t)
		{
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}

		vec3& operator/=(const float t)
		{
			return *this *= 1/t;
		}

		float length() const
		{
			return std::sqrt(length_squared());
		}

		float length_squared() const
		{
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}

	public:
		float e[3];
};


// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color





#endif // VEC3_H

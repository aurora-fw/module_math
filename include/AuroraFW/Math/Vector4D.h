/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#ifndef AURORAFW_MATH_VECTOR4D_H
#define AURORAFW_MATH_VECTOR4D_H

#include <AuroraFW/Global.h>

#include <AuroraFW/Math/Vector3D.h>

namespace AuroraFW {
	namespace Math {
		template<typename T> struct vec2;
		template<typename T> struct vec3;

		/**
		 * A struct that represents a 4D vector. A struct that store's
		 * position in 4D coordinates, allows to manipulate them and also
		 * to do vector operations.
		 * @since snapshot20171003
		 */
		template<typename T>
		struct AFW_PREFIX vec4 {
			vec4();
			vec4(const T& );
			vec4(const T& , const T& , const T& , const T& );
			vec4(const vec2<T>& );
			vec4(const vec2<T>& , const T& , const T& );
			vec4(const vec3<T>& );
			vec4(const vec3<T>& , const T& );
			vec4(const vec4<T>& );

			vec4<T>& add(const vec4<T>& );
			vec4<T>& add(const T& );
			vec4<T>& add(const T& , const T& , const T& , const T& );
			vec4<T>& subtract(const vec4<T>& );
			vec4<T>& subtract(const T& );
			vec4<T>& subtract(const T& , const T& , const T& , const T& );
			vec4<T>& multiply(const vec4<T>& );
			vec4<T>& multiply(const T& );
			vec4<T>& multiply(const T& , const T& , const T& , const T& );
			vec4<T>& divide(const vec4<T>& );
			vec4<T>& divide(const T& );
			vec4<T>& divide(const T& , const T& , const T& , const T& );

			void setX(T );
			void setY(T );
			void setZ(T );
			void setW(T );

			void normalize();

			bool operator==(const vec4<T>& ) const;
			bool operator!=(const vec4<T>& ) const;
			bool operator<(const vec3<T>& ) const;
			bool operator>(const vec3<T>& ) const;
			bool operator<=(const vec3<T>& ) const;
			bool operator>=(const vec3<T>& ) const;

			vec4<T> operator+(const vec4<T>& );
			vec4<T> operator+(const T& );
			vec4<T> operator-(const vec4<T>& );
			vec4<T> operator-(const T& );
			vec4<T> operator*(const vec4<T>& );
			vec4<T> operator*(const T& );
			vec4<T> operator/(const vec4<T>& );
			vec4<T> operator/(const T& );

			vec4<T>& operator+=(const vec4<T>& );
			vec4<T>& operator+=(const T& );
			vec4<T>& operator-=(const vec4<T>& );
			vec4<T>& operator-=(const T& );
			vec4<T>& operator*=(const vec4<T>& );
			vec4<T>& operator*=(const T& );
			vec4<T>& operator/=(const vec4<T>& );
			vec4<T>& operator/=(const T& );

			T getX() const;
			T getY() const;
			T getZ() const;
			T getW() const;

			T length() const;
			T magnitude() const;
			bool isNull() const;
			vec4<T> normalized() const;
			T dot(vec4<T>) const;
			T distanceToPoint(const vec4<T>& ) const;
			T distanceToLine(const vec4<T>&, const vec4<T>& ) const;
			std::string toString() const;

			template<typename t>
			friend std::ostream& operator<<(std::ostream& , const vec4<T>& );

			T x, y, z, w;
		};

		typedef vec4<float> Vector4D;

		template<typename T>
		inline T vec4<T>::getX() const
		{
			return x;
		}

		template<typename T>
		inline T vec4<T>::getY() const
		{
			return y;
		}

		template<typename T>
		inline T vec4<T>::getZ() const
		{
			return z;
		}

		template<typename T>
		inline T vec4<T>::getW() const
		{
			return w;
		}

		template<typename T>
		inline void vec4<T>::setX(T val)
		{
			x = val;
		}

		template<typename T>
		inline void vec4<T>::setY(T val)
		{
			y = val;
		}

		template<typename T>
		inline void vec4<T>::setZ(T val)
		{
			z = val;
		}
		
		template<typename T>
		inline void vec4<T>::setW(T val)
		{
			w = val;
		}

		template<typename T>
		vec4<T>::vec4()
			: x(0), y(0), z(0), w(0)
		{}

		template<typename T>
		vec4<T>::vec4(const T& scalar)
			: x(scalar), y(scalar), z(scalar), w(scalar)
		{}

		template<typename T>
		vec4<T>::vec4(const T& x, const T& y, const T& z, const T& w)
			: x(x), y(y), z(z), w(w)
		{}
		
		template<typename T>
		vec4<T>::vec4(const vec2<T>& v)
			: x(v.x), y(v.y), z(0), w(0)
		{}

		template<typename T>
		vec4<T>::vec4(const vec2<T>& v, const T& z, const T& w)
		: x(v.x), y(v.y), z(z), w(w)
		{}
		
		template<typename T>
		vec4<T>::vec4(const vec3<T>& v)
			: x(v.x), y(v.y), z(v.z), w(0)
		{}

		template<typename T>
		vec4<T>::vec4(const vec4<T>& v)
			: x(v.x), y(v.y), z(v.z), w(v.w)
		{}

		//Operations
		template<typename T>
		vec4<T>& vec4<T>::add(const vec4<T>& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;

			return *this;
		}

		template<typename T>
		vec4<T>& vec4<T>::subtract(const vec4<T>& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;

			return *this;
		}

		template<typename T>
		vec4<T>& vec4<T>::multiply(const vec4<T>& v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			w *= v.w;

			return *this;
		}

		template<typename T>
		vec4<T>& vec4<T>::divide(const vec4<T>& v)
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;
			w /= v.w;

			return *this;
		}

		// Using a value (scalar)
		template<typename T>
		vec4<T>& vec4<T>::add(const T& val)
		{
			x += val;
			y += val;
			z += val;
			w += val;

			return *this;
		}

		template<typename T>
		vec4<T>& vec4<T>::subtract(const T& val)
		{
			x -= val;
			y -= val;
			z -= val;
			w -= val;

			return *this;
		}

		template<typename T>
		vec4<T>& vec4<T>::multiply(const T& val)
		{
			x *= val;
			y *= val;
			z *= val;
			w *= val;

			return *this;
		}

		template<typename T>
		vec4<T>& vec4<T>::divide(const T& val)
		{
			x /= val;
			y /= val;
			z /= val;
			w /= val;

			return *this;
		}

		// Using an x, y, z and w values
		template<typename T>
		vec4<T>& vec4<T>::add(const T& valX, const T& valY, const T& valZ, const T& valW)
		{
			x += valX;
			y += valY;
			z += valZ;
			w += valW;

			return *this;
		}

		template<typename T>
		vec4<T>& vec4<T>::subtract(const T& valX, const T& valY, const T& valZ, const T& valW)
		{
			x -= valX;
			y -= valY;
			z -= valZ;
			w -= valW;

			return *this;
		}

		template<typename T>
		vec4<T>& vec4<T>::multiply(const T& valX, const T& valY, const T& valZ, const T& valW)
		{
			x *= valX;
			y *= valY;
			z *= valZ;
			w *= valW;

			return *this;
		}

		template<typename T>
		vec4<T>& vec4<T>::divide(const T& valX, const T& valY, const T& valZ, const T& valW)
		{
			x /= valX;
			y /= valY;
			z /= valZ;
			w /= valW;

			return *this;
		}

		//Operators
		template<typename T>
		vec4<T> vec4<T>::operator+(const T& value)
		{
			return vec4<T>(x + value, y + value, z + value, w + value);
		}

		template<typename T>
		vec4<T> vec4<T>::operator-(const T& value)
		{
			return vec4<T>(x - value, y - value, z - value, w - value);
		}

		template<typename T>
		vec4<T> vec4<T>::operator*(const T& value)
		{
			return vec4<T>(x * value, y * value, z * value, w * value);
		}

		template<typename T>
		vec4<T> vec4<T>::operator/(const T& value)
		{
			return vec4<T>(x / value, y / value, z / value, w / value);
		}

		template<typename T>
		bool vec4<T>::operator==(const vec4<T>& other) const
		{
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}

		template<typename T>
		bool vec4<T>::operator!=(const vec4<T>& other) const
		{
			return !(*this == other);
		}

		template<typename T>
		bool vec4<T>::operator<(const vec4<T>& other) const
		{
			return x < other.x && y < other.y && z < other.z && w < other.w;
		}

		template<typename T>
		bool vec4<T>::operator<=(const vec4<T>& other) const
		{
			return x <= other.x && y <= other.y && z <= other.z && w <= other.w;
		}

		template<typename T>
		bool vec4<T>::operator>(const vec4<T>& other) const
		{
			return x > other.x && y > other.y && z > other.z && w > other.w;
		}

		template<typename T>
		bool vec4<T>::operator>=(const vec4<T>& other) const
		{
			return x >= other.x && y >= other.y && z >= other.z && w >= other.w;
		}

		template<typename T>
		T vec4<T>::length() const
		{
			return sqrt(x * x + y * y + z * z + w * w);
		}

		template<typename T>
		void vec4<T>::normalize()
		{
			T length = magnitude();
			this->x /= length;
			this->y /= length;
			this->z /= length;
			this->w /= length;
		}

		template<typename T>
		vec4<T> vec4<T>::normalized() const
		{
			T length = magnitude();
			return vec4<T>(x / length, y / length, z / length, w / length);
		}

		template<typename T>
		T vec4<T>::dot(const vec4<T>& other) const
		{
			return x * other.x + y * other.y + z * other.z + w * other.w;
		}

		template<typename T>
		T vec4<T>::distanceToPoint(const vec4<T>& other) const
		{
			T a = x - other.x;
			T b = y - other.y;
			T c = z - other.z;
			T s = w - other.w;
			return sqrt(a * a + b * b + c * c + d * d);
		}

		template<typename T>
		T vec4<T>::distanceToLine(const vec4<T>& point, const vec4<T>& direction) const
		{
			// TODO: Find the formula to get the distance
		}

		template<typename T>
		std::string vec4<T>::toString() const
		{
			return "vec4: (" + std::to_string(x) + ", " + std::to_string(y) + ")";
		}

		template <class T>
		std::ostream& operator<<(std::ostream& stream, const vec4<T>& vector)
		{
			stream << vector.toString();
			return stream;
		}
	}
}

#endif // AURORAFW_MATH_VECTOR4D_H
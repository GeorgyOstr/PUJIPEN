#pragma once
#include "Object.h"
#include "ShaderProgram.h"
#include "Camera.h"
namespace Graphics {
	class Drawable : public Object
	{
	public:
		virtual void init() = 0;

		virtual void render(ShaderProgram& program, Camera& camera) = 0;

		virtual void clean() = 0;
	};
}

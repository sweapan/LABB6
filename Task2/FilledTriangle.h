#pragma once
#include "SDL.h"
#include "Shape.h"
class FilledTriangle:public Shape
{
	float base;
	float height;
public:
	FilledTriangle();
	FilledTriangle(float base, float height, Point2D position, unsigned int RGBA);
	~FilledTriangle();
	void render(SDL_Renderer *renderer);
	const float getBase();
	const float getHeight();
	void setBase(float base);
	void setHeight(float height);
	bool hitbox(int mouseX, int mouseY);
};


#include "FilledRectangle.h"
#include <iostream>

using namespace std;

FilledRectangle::FilledRectangle() {

}

FilledRectangle::FilledRectangle(float width, float height, Point2D position, unsigned int RGBA) : Shape(position, RGBA)
{
	this->width = width;
	this->height = height;
}


FilledRectangle::~FilledRectangle()
{
}

void FilledRectangle::render(SDL_Renderer *renderer) {
	//cout << endl << "---Rectangle---" << endl << "Position: " << position.toString() << endl << "Width: " << width << endl << "Height: " << height << endl; 
	int r, g, b, a; // using bitwise operators to extract the specific colors
	r = RGBA >> 24;
	g = RGBA << 8; g = g >> 24;
	b = RGBA << 16; b = b >> 24;
	a = RGBA << 24; a = a >> 24;

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_Rect* rect = new SDL_Rect;
	rect->x = position.getX();
	rect->y = position.getY();
	rect->w = width;
	rect->h = height;
	SDL_RenderFillRect(renderer, rect); // using SDLs function to render a filled rectangle
	delete rect;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, a); // keeping the old rectangle rendering for a white outline
	SDL_RenderDrawLineF(renderer, position.getX(), position.getY(), position.getX() + width, position.getY());
	SDL_RenderDrawLineF(renderer, position.getX() + width, position.getY(), position.getX() + width, position.getY() + height);
	SDL_RenderDrawLineF(renderer, position.getX() + width, position.getY() + height, position.getX(), position.getY() + height);
	SDL_RenderDrawLineF(renderer, position.getX(), position.getY() + height, position.getX(), position.getY());
}

const float FilledRectangle::getWidth() {
	return width;
}
const float FilledRectangle::getHeight() {
	return height;
}
void FilledRectangle::setWidth(float width) {
	this->width = width;
}
void FilledRectangle::setHeight(float height) {
	this->height = height;
}

bool FilledRectangle::hitbox(int mouseX, int mouseY) { // checks if mouse position is inside of the rectangle
	if ((mouseX > getPos().getX()) && (mouseX < getPos().getX() + getWidth())
		&& (mouseY > getPos().getY()) && (mouseY < getPos().getY() + getHeight())) {
		return true;
	}
	else {
		return false;
	}
}
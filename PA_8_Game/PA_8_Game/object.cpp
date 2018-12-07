#include "Object.h"

Object::Object(int x1, int x2, int y1, int y2)
{
	mLocation.left = x1;
	mLocation.width = x2 - x1;
	mLocation.top = y2;
	mLocation.height = y2 - y1;
}
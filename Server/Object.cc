#include "Object.h"

int Object::globalId = 0;

int Object::GetId() {
	return id;
}

Coordinate Object::GetPosition() {
	return position;
}
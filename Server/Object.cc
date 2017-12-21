#include "Object.h"

<<<<<<< HEAD
int Object::globalId = 0;
=======
Object::Object(): position(0, 0) {
    SetId();
}

Object::Object(Coordinate startPosition): position(startPosition) {
	SetId();
}

void Object::SetId() {
    static int globalId = 0;
    id = globalId++;
}
>>>>>>> RustamDevelop_

int Object::GetId() {
	return id;
}

Coordinate Object::GetPosition() {
	return position;
}
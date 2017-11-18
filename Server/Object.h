#pragma once
#include "../Struct.h"

class Object {
		public:
			Object(Coordinate startPosition): id(globalId++) {};
			int GetId();
			Coordinate GetPosition();
		private:
			static int globalId;
			int id;
		protected:
			Coordinate position;
};
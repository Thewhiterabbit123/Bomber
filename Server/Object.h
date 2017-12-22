#pragma once
#include "../Struct.h"
#include <string>

class Object {
		public:
            Object();
			Object(Coordinate startPosition);
			int GetId();
			Coordinate GetPosition();
		    int GetIntPosition();
		private:
			int id;
            void SetId();
		protected:
			Coordinate position;
};
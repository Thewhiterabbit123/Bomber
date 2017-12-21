#pragma once
#include "../Struct.h"

class Object {
		public:
            Object();
			Object(Coordinate startPosition);
			int GetId();
			Coordinate GetPosition();
		private:
			int id;
            void SetId();
		protected:
			Coordinate position;
};
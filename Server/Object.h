#pragma once
#include "../Struct.h"

class Object {
		public:
<<<<<<< HEAD
			Object(Coordinate startPosition): id(globalId++) {};
			int GetId();
			Coordinate GetPosition();
		private:
			static int globalId;
			int id;
=======
            Object();
			Object(Coordinate startPosition);
			int GetId();
			Coordinate GetPosition();
		private:
			int id;
            void SetId();
>>>>>>> RustamDevelop_
		protected:
			Coordinate position;
};
#ifndef RESOLVEMANAGER_H
#define RESOLVEMANAGER_H
#include "struct.h"

class ResolveManager {
public:
	ResolveManager(playerEventRequest newEvent);
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();
	void PutBomb();
private:
	playerEventRequest currentEvent;
};

#endif RESOLVEMANAGER_H
#include "cbase.h"
#include "runline.h"
#include "GhostEntity.h"
#include "GhostUtils.h"

#pragma once

class GhostRun {
public:
	GhostRun(void);
	~GhostRun(void);

	void StartRun(bool);
	//ends the run for good
	void EndRun();
	bool openRun(const char*);
	GhostEntity* ent;
	float startTime;
	unsigned int step;
	//Not very subject to change, however, it can.
	char ghostName[32];
	//Subject to change, since this is a placeholder for the map the ghost.
	char currentMap[32];
	bool inReset;
	bool isPlaying;

	GhostUtils::GhostData ghostData;
};
#include "GhostRun.h"
#include "runline.h"
#include "GhostOnlineRun.h"
#include "GhostUtils.h"
#include "SFML\include\SFML\Network.hpp"
#pragma once
class GhostOnlineEngine {

public:
	GhostOnlineEngine() {
		shouldAct = false;
		firstTime = true;
		nextTime = 0.0f;
		inTransition = false;
	};
	//gets the singleton Engine instance
	static GhostOnlineEngine* getEngine();
	CUtlVector<GhostOnlineRun*> ghosts;
	static GhostOnlineEngine* instance;
	bool isActive();

	void EndRun(GhostOnlineRun*);
	//make this start the ghost by setting up the data and name
	void StartRun(const char*, bool);
	void ResetGhosts(void);//respawn the ghosts with their correct data

	void sendFirstData();

	

	static float nextTime;
	static bool shouldAct;
	static bool firstTime;

	static void connect(void);//bind the socket, make the thread
	static void disconnect(bool);//close the socket, remove all ghost entities (clear the vector)

	static sf::UdpSocket sendSock;
	static sf::IpAddress serverIPAddress;

	void handleEvent(sf::Packet*);
	void handleLine(sf::Packet*);
	void handleDisconnect(sf::Packet*);
	void handleConnect(sf::Packet*);
	void handleKick(sf::Packet*);

	void addRun(GhostOnlineRun*);
	GhostOnlineRun* getRun(const char*);//by name, the recieve thread uses this heavily!
	GhostOnlineRun* getRun(GhostOnlineEntity*);//this is by entity, used for interpolation
	void stopAllRuns();	
	void sendLine(OnlineRunLine);
	bool inTransition;

};
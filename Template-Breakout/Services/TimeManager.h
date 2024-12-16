#pragma once
#include <chrono>

#include "Singleton.h"

class TimeManager : public Singleton<TimeManager> 
{
	friend class Singleton<TimeManager>;

public:

	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;

	void Update();

	double GetDeltaTime() const { return deltaTime; }
	double GetFrameRate() const;
	double GetTotalTime() const;


private:
	// Constructeur privé pour le Singleton
	TimeManager();

	std::chrono::high_resolution_clock::time_point lastTimePoint;
	double deltaTime;
	double totalTime;
};

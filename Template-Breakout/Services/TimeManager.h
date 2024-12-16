#pragma once
#include <chrono>

class TimeManager {
public:
	// Singleton instance
	static TimeManager& Instance();

	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;

	void Update();

	double GetDeltaTime() const { return deltaTime; }
	double GetFrameRate() const;
	double GetTotalTime() const;


private:
	// Constructeur priv� pour le Singleton
	TimeManager();

	std::chrono::high_resolution_clock::time_point lastTimePoint;
	double deltaTime;
	double totalTime;
};

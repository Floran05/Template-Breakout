#include "TimeManager.h"


TimeManager::TimeManager()
{
	lastTimePoint = std::chrono::high_resolution_clock::now();
	deltaTime = 0.0;
	totalTime = 0;
}

void TimeManager::Update()
{
	auto currentTimePoint = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedTime = currentTimePoint - lastTimePoint;
	deltaTime = elapsedTime.count();

	float maxDeltaTime = 0.1f;
	if (deltaTime > maxDeltaTime)
	{
		deltaTime = maxDeltaTime;
	}

	totalTime += deltaTime;
	lastTimePoint = currentTimePoint;
}

double TimeManager::GetFrameRate() const
{
	if (deltaTime > 0.0)
		return 1.0 / deltaTime;
	return 0.0;
}

int TimeManager::GetApproxFrameRate() const 
{
	int m_approxFrameRate;
	if (deltaTime > 0.0)
	{
		m_approxFrameRate = (int) (1.0 / deltaTime);
		return m_approxFrameRate;
	}
	return 0;
}

double TimeManager::GetTotalTime() const
{
	float m_totalTime =  (float) totalTime;
	return m_totalTime;
}
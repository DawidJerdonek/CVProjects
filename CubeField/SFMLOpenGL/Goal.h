#pragma once
class Goal
{
public:
	Goal();

	bool goalReached(int t_score);
protected:
	int goal = 200000;
};


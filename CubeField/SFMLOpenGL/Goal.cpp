#include "Goal.h"

Goal::Goal()
{

}

bool Goal::goalReached(int t_score)
{
	if (t_score >= goal)
	{
		return true;
	}
	else
	{
		return false;
	}
}

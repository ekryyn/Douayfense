#include "Wave.hpp"
#include "Application.hpp"

Wave::Wave(Map *map, float freq) :
	gameMap(map),
	freq(freq),
	baseFreq(freq)
{
	lastToken = 0;
	clock = &Application::getInstance()->gameClock;
}

void Wave::initStock(const std::vector<Enemy*> &list)
{
	stock.clear();
	stock = list;

//	value = 10*stock.size();
}

bool Wave::hasStock()
{
	return !stock.empty();
}

Enemy* Wave::getNextEnemy()
{
	Enemy *e = NULL;

	if(hasStock())
	{
		if(stock.front()->waveWait > 0)
			freq = stock.front()->waveWait;
		else
			freq = baseFreq;

		if( clock->GetElapsedTime()-lastToken >= freq )
		{
			e = stock.front()->createClone();
			stock.erase(stock.begin());
			lastToken = clock->GetElapsedTime();
		}
	}

	return e;
}

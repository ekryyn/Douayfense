#ifndef TOWER_HPP
#define TOWER_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Enemy.hpp"
#include "Bullet.hpp"
#include "PausableClock.hpp"

class Tower
{
public:
	Tower();
	void render(sf::RenderTarget *target, bool ghost = false);
	Tower* createCopy();

	virtual Tower* getCopy();
	virtual void upgrade();
	virtual std::string upgradeDescription();
	virtual std::string getName();
	virtual std::string getDescription();
	virtual int getValue(){ return upgraded ? 0.80 * getUpgradePrice() : 0.85 * getPrice(); }
	virtual int getPrice(){ return 1.f*price; }
	virtual int getUpgradePrice(){ return 1.50*price; }
	virtual sf::Image* getImage();

	unsigned int i,j;
	bool selected;
	float range;
	int damage;
	float speed;
	bool wrong;
	bool upgraded;
	bool active;

	virtual void shoot(std::vector<Enemy*> enemies);
	virtual bool isValid(Enemy *e);
	virtual Bullet* createBullet(float x, float y, Enemy *e, int damage);

protected:
	int price;
	sf::Sprite sprite;

private:
	float lastShot;
	PausableClock *clock;
	std::vector<Bullet*> bullets;
};

#endif // TOWER_HPP

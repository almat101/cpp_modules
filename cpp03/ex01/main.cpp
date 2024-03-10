#include "ScavTrap.hpp"

void seedRandomGenerator()
{
	std::srand((std::time(0)));
}

int main(void)
{
	ScavTrap gimbo("gimbo");
	ScavTrap ringo("ringo");
	ScavTrap mingo("mingo");

	seedRandomGenerator();

	ringo.guardGate();
	mingo.guardGate();
	gimbo.guardGate();


	if (gimbo.isAlive())
		gimbo.attack(ringo.getName());
	if (gimbo.isAlive())
		ringo.takeDamage(gimbo.getAttackDamage());

	if (ringo.isAlive())
		ringo.attack(mingo.getName());
	if (ringo.isAlive())
		mingo.takeDamage(ringo.getAttackDamage());

	if (mingo.isAlive())
		mingo.attack(gimbo.getName());
	if(mingo.isAlive())
		gimbo.takeDamage(mingo.getAttackDamage());

	if (gimbo.isAlive())
		gimbo.attack(ringo.getName());
	if (gimbo.isAlive())
		ringo.takeDamage(gimbo.getAttackDamage());

	if (ringo.isAlive())
		ringo.attack(mingo.getName());
	if (ringo.isAlive())
		mingo.takeDamage(ringo.getAttackDamage());

	if (mingo.isAlive())
		mingo.attack(gimbo.getName());
	if(mingo.isAlive())
		gimbo.takeDamage(mingo.getAttackDamage());

if (gimbo.isAlive())
		gimbo.attack(ringo.getName());
	if (gimbo.isAlive())
		ringo.takeDamage(gimbo.getAttackDamage());

	if (ringo.isAlive())
		ringo.attack(mingo.getName());
	if (ringo.isAlive())
		mingo.takeDamage(ringo.getAttackDamage());

	if (mingo.isAlive())
		mingo.attack(gimbo.getName());
	if(mingo.isAlive())
		gimbo.takeDamage(mingo.getAttackDamage());


	ringo.displayStats();
	gimbo.displayStats();
	mingo.displayStats();

	return 0;
}

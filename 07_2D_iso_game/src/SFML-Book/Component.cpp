#include <SFML-Book/Component.hpp>

namespace book
{
    CompAIMain::CompAIMain(int gold,const sf::Time& timeDelta) :_gold_amount(gold),_delta(timeDelta), _elapsed(sf::Time::Zero)
    {
    }

    CompAIWarrior::CompAIWarrior(int hitPoint,const sf::Time& timeDelta,int range) : _hitPoint(hitPoint), _delta(timeDelta), _elapsed(sf::Time::Zero), _range(range)
    {
    }

    CompAIDefender::CompAIDefender(int hitPoint,const sf::Time& timeDelta) : _hitPoint(hitPoint), _delta(timeDelta), _elapsed(sf::Time::Zero)
    {
    }

    CompAISpawner::CompAISpawner(CompAISpawner::FuncType makeAs,int number,const sf::Time& timeDelta, CompAISpawner::FuncType_onSpawn onSpawn) : _makeAs(makeAs), _number(number), _delta(timeDelta), _elapsed(sf::Time::Zero), _OnSpawn(onSpawn)
    {
    }

    CompAIWalker::CompAIWalker(float speed) : _speed(speed)
    {
    }

    CompAIFlyer::CompAIFlyer(float speed) : _speed(speed)
    {
    }

    CompTeam::CompTeam(Team* team) : _team(team)
    {
    }

    CompHp::CompHp(int hp) : _hp(hp), _maxHp(hp)
    {
    }

    CompBuildArea::CompBuildArea(int range) : _range(range)
    {
    }
}

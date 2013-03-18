/*
** droid.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d08-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 16 09:34:48 2013 maxime ginters
** Last update Wed Jan 16 09:34:48 2013 maxime ginters
*/

#include <iostream>
#include "droid.hh"

Droid::Droid(std::string const& id) : _id(id), _energy(50), _attack(25),
    _thoughness(15), _status(NULL), _battleData(NULL)
{
    _status = new std::string("Standing by");
    _battleData = new DroidMemory();
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(Droid const& other) : _id(other._id), _energy(50),
    _attack(other._attack), _thoughness(other._thoughness), _status(NULL),
    _battleData(NULL)
{
    if (other._status)
    {
        if (_status)
            delete _status;
        _status = new std::string(*other._status);
    }
    else if (_status)
    {
        delete _status;
        _status = NULL;
    }
    _battleData = new DroidMemory(*other._battleData);

    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (_status)
        delete _status;
    if (_battleData)
        delete _battleData;
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

Droid& Droid::operator=(Droid const& other)
{
    if (this == &other)
        return *this;

    _id = other._id;
    _energy = 50;
    if (other._status)
    {
        if (_status)
            *_status = *other._status;
        else
            _status = new std::string(*other._status);
    }
    else if (_status)
    {
        delete _status;
        _status = NULL;
    }
    if (_battleData)
        delete _battleData;
    _battleData = new DroidMemory(*other._battleData);
    return *this;
}

std::string const& Droid::getId() const
{
    return _id;
}

void Droid::setId(std::string const& id)
{
    _id = id;
}

size_t Droid::getEnergy() const
{
    return _energy;
}

void Droid::setEnergy(size_t const val)
{
    _energy = val;
    if (_energy > 100)
        _energy = 100;
}

size_t Droid::getAttack() const
{
    return _attack;
}

size_t Droid::getThoughness() const
{
    return _thoughness;
}

size_t Droid::getToughness() const
{
    return _thoughness;
}

std::string* Droid::getStatus() const
{
    return _status;
}

void Droid::setStatus(std::string* val)
{
    if (_status)
        delete _status;
    _status = val;
}

void Droid::setStatus(std::string const& val)
{
    if (_status)
        *_status = val;
    else
        _status = new std::string(val);
}

bool Droid::operator==(Droid const& other) const
{
    return getStatus() && other.getStatus() && *getStatus() == *(other.getStatus());
}

bool Droid::operator!=(Droid const& other) const
{
    return !(getStatus() && other.getStatus() && *getStatus() == *(other.getStatus()));
}

Droid& operator<<(Droid& droid, size_t& value)
{
    if (droid.getEnergy() + value > 100)
    {
        value -= 100 - droid.getEnergy();
        droid.setEnergy(100);
    }
    else
    {
        droid.setEnergy(droid.getEnergy() + value);
        value = 0;
    }
    return droid;
}

std::ostream& operator<<(std::ostream& stream, Droid const& droid)
{
    stream << "Droid '" << droid.getId() << "', " << (droid.getStatus() ? *droid.getStatus() : "") << ", " << droid.getEnergy();
    return stream;
}

DroidMemory const* Droid::getBattleData() const
{
    return _battleData;
}

DroidMemory* Droid::getBattleData()
{
    return _battleData;
}

void Droid::setBattleData(DroidMemory* mem)
{
    _battleData = mem;
}

bool Droid::operator()(std::string const* task, size_t exp)
{
    if (!task || !_battleData)
        return false;
    if (!_status)
        _status = new std::string("");
    if (_energy <= 10)
    {
        *_status = "Battery Low";
        _energy = 0;
        return false;
    }
    _energy -= 10;
    if (_battleData->getExp() < exp)
    {
        *_status = *task + " - Failed!";
        _battleData->setExp(_battleData->getExp() + exp);
        return false;
    }
    *_status = *task + " - Completed!";
    _battleData->setExp(_battleData->getExp() + (exp / 2));
    return true;
}

/*
** droidmemory.cpp for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d08-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 16 13:25:55 2013 maxime ginters
** Last update Wed Jan 16 13:25:55 2013 maxime ginters
*/

#include <cstdlib>
#include "droidmemory.hh"

DroidMemory::DroidMemory() : _fingerPrint(random()), _exp(0)
{
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerPrint() const
{
    return _fingerPrint;
}

void DroidMemory::setFingerPrint(size_t const value)
{
    _fingerPrint = value;
}

size_t DroidMemory::getExp() const
{
    return _exp;
}

void DroidMemory::setExp(size_t const value)
{
    _exp = value;
}

DroidMemory& DroidMemory::operator<<(DroidMemory const& other)
{
    setExp(getExp() + other.getExp());
    setFingerPrint(getFingerPrint() ^ other.getFingerPrint());
    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory& other) const
{
    other.setExp(getExp() + other.getExp());
    other.setFingerPrint(getFingerPrint() ^ other.getFingerPrint());
    return other;
}

DroidMemory& DroidMemory::operator+=(DroidMemory const& other)
{
    setExp(getExp() + other.getExp());
    setFingerPrint(getFingerPrint() ^ other.getFingerPrint());
    return *this;
}
    
DroidMemory& DroidMemory::operator+=(size_t const& val)
{
    setExp(getExp() + val);
    setFingerPrint(getFingerPrint() ^ val);
    return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory const& other) const
{
    DroidMemory mem;
    mem.setExp(getExp() + other.getExp());
    mem.setFingerPrint(getFingerPrint() ^ other.getFingerPrint());
    return mem;
}

DroidMemory DroidMemory::operator+(size_t const val) const
{
    DroidMemory mem;
    mem.setExp(getExp() + val);
    mem.setFingerPrint(getFingerPrint() ^ val);
    return mem;
}

std::ostream& operator<<(std::ostream& stream, DroidMemory const& memory)
{
    stream << "DroidMemory '" << memory.getFingerPrint() << "', " << memory.getExp();
    return stream;
}

bool DroidMemory::operator==(DroidMemory const& other) const
{
    return getExp() == other.getExp() && getFingerPrint() == other.getFingerPrint();
}

bool DroidMemory::operator!=(DroidMemory const& other) const
{
    return !(getExp() == other.getExp() && getFingerPrint() == other.getFingerPrint());
}

bool DroidMemory::operator<(DroidMemory const& other) const
{
    return getExp() < other.getExp();
}

bool DroidMemory::operator<(size_t other) const
{
    return getExp() < other;
}

bool DroidMemory::operator>(DroidMemory const& other) const
{
    return getExp() > other.getExp();
}

bool DroidMemory::operator>(size_t other) const
{
    return getExp() > other;
}

bool DroidMemory::operator<=(DroidMemory const& other) const
{
    return getExp() <= other.getExp();
}

bool DroidMemory::operator<=(size_t other) const
{
    return getExp() <= other;
}

bool DroidMemory::operator>=(DroidMemory const& other) const
{
    return getExp() >= other.getExp();
}

bool DroidMemory::operator>=(size_t other) const
{
    return getExp() >= other;
}


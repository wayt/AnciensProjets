#ifndef TYPELIST_H_
# define TYPELIST_H_

#include "Storage.hpp"

struct TypeList0 : private Storage0
{
};

struct TypeList1 : private Storage1
{
};

struct TypeList2 : private Storage2
{
};

template<class P1, class P2, class P3>
struct TypeList3 : private Storage3<P1, P2, P3>
{
    typedef Storage3<P1, P2, P3> BaseClass;
    TypeList3(P1 p1, P2 p2, P3 p3) : BaseClass(p1, p2, p3)
    {}

    template<class T>
    T& operator[](Value<T>& value)
    {
        return value.get();
    }

    template<class ReturnType, class Caller, class List>
    ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
    {
        return caller(list[BaseClasse::_t1],
                list[BaseClass::_t2],
                list[BaseClass::_t3]
                );
    }
};

struct TypeList4 : private Storage4
{
};

struct TypeList5 : private Storage5
{
};

struct TypeList6 : private Storage6
{
};

#endif /* !TYPELIST_H_ */

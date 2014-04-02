#ifndef INSPECTOR_H_
# define INSPECTOR_H_

#include <string>
#include <iostream>
#include <typeinfo>

template<class T, class U>
struct IsPrintable
{
    typedef struct {int tab;} Yes;
    typedef struct {int tab[2];} No;


    template < size_t i >
    struct force_int {
        typedef void* type;
    };

    template < typename C >
    static Yes isPrintable( typeof(&C::operator<<) );

    template < typename C >
    static Yes isPrintable(typename force_int< sizeof((T&)((*(T*)(0))) << (C&)((*(C*)(0)))) >::type);

    template < typename C >
    static No isPrintable(...);

    static const bool ISPRINTABLE = (sizeof(isPrintable<U>((U*)0)) == sizeof(Yes));
};

template<bool C, class T = void*>
struct enable_if
{
    typedef T type;
};

template<class T>
struct enable_if<0, T>
{
};

template<class T>
struct Printer
{
    template<class U>
    static typename enable_if<IsPrintable<std::ostream, U >::ISPRINTABLE >::type print(T& stream, U const& u)
    {
        stream << u << std::endl;
    }

    template<class U>
    static typename enable_if<!IsPrintable<std::ostream, U >::ISPRINTABLE >::type print(T& stream, U const& u)
    {
        stream << typeid(u).name() << std::endl;
    }

};

template<class T>
void inspect(T t)
{
    Printer<std::ostream>::print(std::cout, t);
}

#endif /* !INSPECTOR_H_ */

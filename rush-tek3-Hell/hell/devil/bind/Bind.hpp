#ifndef BIND_H_
# define BIND_H_

template<class ReturnType, class X1, class X2, class X3,
    class Param1, class Param2, class Param3 >
Caller<ReturnType, ReturnType(*)(X1, X2, X3), class Traits3< Param1, Param2, Param3 >::Type >
bind(ReturnType(*)(X1, X2, X3), Param1 p1, Param2 p2, Param3 p3)
{
    typedef class GetType<Param1>::Type P1;
    typedef class GetType<Param2>::Type P2;
    typedef class GetType<Param3>::Type P3;
    typedef TypeList3<P1, P2, P3> ListType;
    ListType l(p1, p2, p3);
    return Caller<ReturnType, ReturnType(*)(X1, X2, X3), ListType> (f, l);
}

#endif /* !BIND_H_ */

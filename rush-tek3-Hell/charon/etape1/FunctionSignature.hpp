#ifndef FUNCTIONSIGNATURE_H_
# define FUNCTIONSIGNATURE_H_

template<class T>
struct FunctionSignature
{
    typedef T type;
};

template<class Retour>
struct FunctionSignature<Retour(void)>
{
    typedef Retour (*type)(void);
};

template<class Retour, class T>
struct FunctionSignature<Retour(T)>
{
    typedef Retour (*type)(T);
};

template<class Retour, class T, class U>
struct FunctionSignature<Retour(T, U)>
{
    typedef Retour (*type)(T, U);
};

template<class Retour, class T, class U, class K>
struct FunctionSignature<Retour(T, U, K)>
{
    typedef Retour (*type)(T, U, K);
};

template<class Retour, class T, class U, class K, class X>
struct FunctionSignature<Retour(T, U, K, X)>
{
    typedef Retour (*type)(T, U, K, X);
};

#endif /* !FUNCTIONSIGNATURE_H_ */

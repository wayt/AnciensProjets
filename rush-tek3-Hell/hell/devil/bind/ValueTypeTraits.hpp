#ifndef VALUETYPETRAITS_H_
# define VALUETYPETRAITS_H_

template<class T>
class Value
{
public:
    T& get() { return _val; }
    T const& get() const { return _val; }

private:
    T _val;
};

template<class T>
class GetType
{
public:
    typedef Value<T> Type
};

template<class T>
struct TypeTraits {};

#endif /* !VALUETYPETRAITS_H_ */

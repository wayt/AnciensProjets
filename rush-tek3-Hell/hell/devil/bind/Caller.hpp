#ifndef CALLER_H_
# define CALLER_H_

template<class ReturnType, class Callable, class List>
class Caller
{
public:
    Caller(Callable const& callable, List const& list) : _callable(callable),
    _list(list)
    {
    }

private:
    Callable& _callable;
    List& _list;
};

#endif /* !CALLER_H_ */

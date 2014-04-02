#ifndef FUNCTION_H_
# define FUNCTION_H_

#include <cstdlib>

template<class T>
class Function
{
};

template<class Retour>
class Function<Retour(void)>
{
public:
    Function() : _inner(NULL) {}
    virtual ~Function() { delete _inner; }
    template<class U>
    Function(U& obj) : _inner(NULL) { _inner = new InnerClass<U>(obj); }
    template<class U>
    Function(U const& obj) : _inner(NULL) { _inner = new ConstInnerClass<U>(obj); }
    Function(Retour(*func)(void)) : _inner(NULL) { _inner = new FunctionInnerClass(func); }

    template<class U>
    void operator=(U& obj) { delete _inner; _inner = new InnerClass<U>(obj); }
    template<class U>
    void operator=(U const& obj) { delete _inner; _inner = new ConstInnerClass<U>(obj);}
    void operator=(Retour(*func)(void)) { delete _inner; _inner = new FunctionInnerClass(func); }

    Retour operator()() { return (*_inner)(); }


private:
    class IInnerClass
    {
    public:
        virtual ~IInnerClass() {}
        virtual Retour operator()(void) = 0;
        virtual Retour operator()(void) const = 0;
    };

    IInnerClass* _inner;

    template<class U>
    class InnerClass : public IInnerClass
    {
    public:
        InnerClass(U& obj) : _obj(obj) {}
        Retour operator()(void) { return _obj(); }
        Retour operator()(void) const { return _obj(); }
    private:
        U& _obj;
    };

    template<class U>
    class ConstInnerClass : public IInnerClass
    {
    public:
        ConstInnerClass(U const& obj) : _obj(obj) {}
        Retour operator()(void) { return _obj(); }
        Retour operator()(void) const { return _obj(); }
    private:
        U const& _obj;
    };

    class FunctionInnerClass : public IInnerClass
    {
    public:
        FunctionInnerClass(Retour(*func)(void)) : _obj(func) {}
        Retour operator()(void) { return _obj(); }
        Retour operator()(void) const { return _obj(); }
    private:
        Retour(*_obj)(void);
    };

};

template<class Retour, class T>
class Function<Retour(T)>
{
public:
    Function() : _inner(NULL) {}
    virtual ~Function() { delete _inner; }
    template<class U>
    Function(U const& obj) : _inner(NULL) { _inner = new ConstInnerClass<U>(obj); }
    template<class U>
    Function(U& obj) : _inner(NULL) { _inner = new InnerClass<U>(obj); }
    Function(Retour(*func)(T)) : _inner(NULL) { _inner = new FunctionInnerClass(func); }

    template<class U>
    void operator=(U const& obj) { delete _inner; _inner = new ConstInnerClass<U>(obj); }
    template<class U>
    void operator=(U& obj) { delete _inner; _inner = new InnerClass<U>(obj); }
    void operator=(Retour(*func)(T)) { delete _inner; _inner = new FunctionInnerClass(func); }

    Retour operator()(T t) { return (*_inner)(t); }

private:
    class IInnerClass
    {
    public:
        virtual ~IInnerClass() {}
        virtual Retour operator()(T) = 0;
        virtual Retour operator()(T) const = 0;
    };

    IInnerClass* _inner;

    template<class U>
    class InnerClass : public IInnerClass
    {
    public:
        InnerClass(U& obj) : _obj(obj) {}
        Retour operator()(T t) { return _obj(t); }
        Retour operator()(T t) const { return _obj(t); }
    private:
        U& _obj;
    };

    template<class U>
    class ConstInnerClass : public IInnerClass
    {
    public:
        ConstInnerClass(U const& obj) : _obj(obj) {}
        Retour operator()(T t) { return _obj(t); }
        Retour operator()(T t) const { return _obj(t); }
    private:
        U const& _obj;
    };

    class FunctionInnerClass : public IInnerClass
    {
    public:
        FunctionInnerClass(Retour(*func)(T)) : _obj(func) {}
        Retour operator()(T t) { return _obj(t); }
        Retour operator()(T t) const { return _obj(t); }
    private:
        Retour(*_obj)(T);
    };
};

template<class Retour, class T, class I>
class Function<Retour(T, I)>
{
public:
    Function() : _inner(NULL) {}
    virtual ~Function() { delete _inner; }
    template<class U>
    Function(U const& obj) : _inner(NULL) { _inner = new ConstInnerClass<U>(obj); }
    template<class U>
    Function(U& obj) : _inner(NULL) { _inner = new InnerClass<U>(obj); }
    Function(Retour(*func)(T, I)) : _inner(NULL) { _inner = new FunctionInnerClass(func); }

    template<class U>
    void operator=(U const& obj) { delete _inner; _inner = new ConstInnerClass<U>(obj); }
    template<class U>
    void operator=(U& obj) { delete _inner; _inner = new InnerClass<U>(obj); }
    void operator=(Retour(*func)(T, I)) { delete _inner; _inner = new FunctionInnerClass(func); }

    Retour operator()(T t, I i) { return (*_inner)(t, i); }

private:
    class IInnerClass
    {
    public:
        virtual ~IInnerClass() {}
        virtual Retour operator()(T, I) = 0;
        virtual Retour operator()(T, I) const = 0;
    };

    IInnerClass* _inner;

    template<class U>
    class InnerClass : public IInnerClass
    {
    public:
        InnerClass(U& obj) : _obj(obj) {}
        Retour operator()(T t, I i) { return _obj(t, i); }
        Retour operator()(T t, I i) const { return _obj(t, i); }
    private:
        U& _obj;
    };

    template<class U>
    class ConstInnerClass : public IInnerClass
    {
    public:
        ConstInnerClass(U const& obj) : _obj(obj) {}
        Retour operator()(T t, I i) { return _obj(t, i); }
        Retour operator()(T t, I i) const { return _obj(t, i); }
    private:
        U const& _obj;
    };

    class FunctionInnerClass : public IInnerClass
    {
    public:
        FunctionInnerClass(Retour(*func)(T, I)) : _obj(func) {}
        Retour operator()(T t, I i) { return _obj(t, i); }
        Retour operator()(T t, I i) const { return _obj(t, i); }
    private:
        Retour(*_obj)(T, I);
    };
};

template<class Retour, class T, class I, class K>
class Function<Retour(T, I, K)>
{
public:
    Function() : _inner(NULL) {}
    virtual ~Function() { delete _inner; }
    template<class U>
    Function(U const& obj) : _inner(NULL) { _inner = new ConstInnerClass<U>(obj); }
    template<class U>
    Function(U& obj) : _inner(NULL) { _inner = new InnerClass<U>(obj); }
    Function(Retour(*func)(T, I, K)) : _inner(NULL) { _inner = new FunctionInnerClass(func); }

    template<class U>
    void operator=(U const& obj) { delete _inner; _inner = new ConstInnerClass<U>(obj); }
    template<class U>
    void operator=(U& obj) { delete _inner; _inner = new InnerClass<U>(obj); }
    void operator=(Retour(*func)(T, I, K)) { delete _inner; _inner = new FunctionInnerClass(func); }

    Retour operator()(T t, I i, K k) { return (*_inner)(t, i, k); }

private:
    class IInnerClass
    {
    public:
        virtual ~IInnerClass() {}
        virtual Retour operator()(T, I, K) = 0;
        virtual Retour operator()(T, I, K) const = 0;
    };

    IInnerClass* _inner;

    template<class U>
    class InnerClass : public IInnerClass
    {
    public:
        InnerClass(U& obj) : _obj(obj) {}
        Retour operator()(T t, I i, K k) { return _obj(t, i, k); }
        Retour operator()(T t, I i, K k) const { return _obj(t, i, k); }
    private:
        U& _obj;
    };

    template<class U>
    class ConstInnerClass : public IInnerClass
    {
    public:
        ConstInnerClass(U const& obj) : _obj(obj) {}
        Retour operator()(T t, I i, K k) { return _obj(t, i, k); }
        Retour operator()(T t, I i, K k) const { return _obj(t, i, k); }
    private:
        U const& _obj;
    };

    class FunctionInnerClass : public IInnerClass
    {
    public:
        FunctionInnerClass(Retour(*func)(T, I, K)) : _obj(func) {}
        Retour operator()(T t, I i, K k) { return _obj(t, i, k); }
        Retour operator()(T t, I i, K k) const { return _obj(t, i, k); }
    private:
        Retour(*_obj)(T, I, K);
    };
};

template<class Retour, class T, class I, class K, class L>
class Function<Retour(T, I, K, L)>
{
public:
    Function() : _inner(NULL) {}
    virtual ~Function() { delete _inner; }
    template<class U>
    Function(U const& obj) : _inner(NULL) { _inner = new ConstInnerClass<U>(obj); }
    template<class U>
    Function(U& obj) : _inner(NULL) { _inner = new InnerClass<U>(obj); }
    Function(Retour(*func)(T, I, K, L)) : _inner(NULL) { _inner = new FunctionInnerClass(func); }

    template<class U>
    void operator=(U const& obj) { delete _inner; _inner = new ConstInnerClass<U>(obj); }
    template<class U>
    void operator=(U& obj) { delete _inner; _inner = new InnerClass<U>(obj); }
    void operator=(Retour(*func)(T, I, K, L)) { delete _inner; _inner = new FunctionInnerClass(func); }

    Retour operator()(T t, I i, K k, L l) { return (*_inner)(t, i, k, l); }

private:
    class IInnerClass
    {
    public:
        virtual ~IInnerClass() {}
        virtual Retour operator()(T, I, K, L) = 0;
        virtual Retour operator()(T, I, K, L) const = 0;
    };

    IInnerClass* _inner;

    template<class U>
    class InnerClass : public IInnerClass
    {
    public:
        InnerClass(U& obj) : _obj(obj) {}
        Retour operator()(T t, I i, K k, L l) { return _obj(t, i, k, l); }
        Retour operator()(T t, I i, K k, L l) const { return _obj(t, i, k, l); }
    private:
        U& _obj;
    };

    template<class U>
    class ConstInnerClass : public IInnerClass
    {
    public:
        ConstInnerClass(U const& obj) : _obj(obj) {}
        Retour operator()(T t, I i, K k, L l) { return _obj(t, i, k, l); }
        Retour operator()(T t, I i, K k, L l) const { return _obj(t, i, k, l); }
    private:
        U const& _obj;
    };

    class FunctionInnerClass : public IInnerClass
    {
    public:
        FunctionInnerClass(Retour(*func)(T, I, K, L)) : _obj(func) {}
        Retour operator()(T t, I i, K k, L l) { return _obj(t, i, k, l); }
        Retour operator()(T t, I i, K k, L l) const { return _obj(t, i, k, l); }
    private:
        Retour(*_obj)(T, I, K, L);
    };
};



#endif /* !FUNCTION_H_ */

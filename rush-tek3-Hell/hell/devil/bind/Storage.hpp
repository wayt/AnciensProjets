#ifndef STORAGE_H_
# define STORAGE_H_

struct Storage0
{
};

template<class T1>
struct Storage1 : public Storage0
{
    Storage1(T1& t1) : Storage0(), _t1(t1)
    {
    }
    T1 _t1;
};

template<class T1, class T2>
struct Storage2 : public Storage1
{
    Storage2(T1& t1, T2& t2) : Storage1<T1>(t1), _t2(t2)
    {
    }
    T2 _t2;
};

template<class T1, class T2, class T3>
struct Storage3 : public Storage2
{
    Storage3(T1& t1, T2& t2, T3& t3) : Storage2<T1, T2>(t1, t2), _t3(t3)
    {
    }
    T3 _t3;
};

template<class T1, class T2, class T3, class T4>
struct Storage4 : public Storage3
{
    Storage4(T1& t1, T2& t2, T3& t3, T4& t4) : Storage3<T1, T2, T3>(t1, t2, t3), _t4(t4)
    {
    }
    T4 _t4;
};

template<class T1, class T2, class T3, class T4, class T5>
struct Storage5 : public Storage4
{
    Storage5(T1& t1, T2& t2, T3& t3, T4& t4, T5& t5) : Storage4<T1, T2, T3, T4>(t1, t2, t3, t4), _t5(t5)
    {
    }
    T5 _t5;
};

template<class T1, class T2, class T3, class T4, class T5, class T6>
struct Storage6 : public Storage5
{
    Storage6(T1& t1, T2& t2, T3& t3, T4& t4, T5& t5, T6& t6) : Storage5<T1, T2, T3, T4, T5>(t1, t2, t3, t4, t5), _t6(t6)
    {
    }
    T6 _t6;
};

#endif /* !STORAGE_H_ */

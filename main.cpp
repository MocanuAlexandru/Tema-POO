#include <fstream>
#include <iostream>
#include<algorithm>
using namespace std;
template <class T>
class coada;
template<class T>
class nod
{
    friend class coada<T>;
private:
    T ch;
    nod* after;
    nod(T c)
    {
        ch=c;
        after=NULL;
    }
    nod() {}
    template <class U>
    friend ostream& operator<<(ostream&,nod<U>);
    template <class U>
    friend istream& operator>>(istream&,nod<U>&);
    template <class U>
    friend istream& operator>>(istream&,coada<U>&);
};
template <class T>
class coada
{
private:
    ///campuri de date
    nod<T> *first,*last;
    int nrElem;
public:
    ///constructori
    coada()
    {
        first=last=NULL;
        nrElem=0;
    }
    coada(const coada& ob)
    {
        first=NULL;
        last=NULL;
        nrElem=0;
        for(nod<T>* p=ob.first; p!=NULL; p=p->after)
        {
            push(p->ch);
        }
    }
    ///destructor
    ~coada()
    {
        while(first!=NULL) pop();
    }
    ///supraincarcarea operatorului egal
    coada operator=(const coada& ob)
    {
        while(first!=NULL) pop();
        for(nod<T>* p=ob.first; p!=NULL; p=p->after)
        {
            push(p->ch);
        }
        return *this;
    }
    ///metode basic
    void push(const T c)
    {
        nrElem++;
        nod<T>* q=new nod<T>(c);
        if(last!=NULL) last->after=q;
        last=q;
        if(first==NULL) first=last;
    }
    void pop()
    {
        if(first==NULL) return;
        nrElem--;
        nod<T> *q=first;
        first=first->after;
        delete q;
        if(first==NULL) last=NULL;
    }
    T top()
    {
        return first->ch;
    }
    /// supraincarcare operatori matematici
    coada operator+(const coada& ob)
    {
        coada rez;
        for(nod<T>*p=first; p!=NULL; p=p->after)
        {
            rez.push(p->ch);
        }
        for(nod<T>*p=ob.first; p!=NULL; p=p->after)
        {
            rez.push(p->ch);
        }
        return rez;
    }
    coada& operator-(coada& ob)
    {
        nod<T> *q,*p;
        for(q=first,p=ob.first; p!=NULL && q!=NULL && p->ch==q->ch; p=p->after,q=q->after)
        {
            pop();
            ob.pop();
        }
        return *this;
    }
    ///supraincarcare operatori logici
    bool operator==(const coada& ob)
    {
        nod<T> *q,*p;
        for(q=first,p=ob.first; p!=NULL && q!=NULL && p->ch==q->ch; p=p->after,q=q->after);
        if(p==NULL && q==NULL) return true;
        return false;
    }
    bool operator!=(const coada& ob)
    {
        return !(*this==ob);
    }
    bool operator<(const coada ob)
    {
        if(nrElem<ob.nrElem) return true;
        if(nrElem>ob.nrElem) return false;
        nod<T> *q,*p;
        for(q=first,p=ob.first; p!=NULL && q!=NULL && p->ch==q->ch; p=p->after,q=q->after);
        if(p==NULL)
        {
            return false;
        }
        if(q->ch<p->ch)
        {
            return true;
        }
        if(p->ch<q->ch)
        {
            return false;
        }
        return false;
    }
    ///supraincarcare operatori citire/afisare
    template<class U>
    friend ostream& operator<<(ostream&,coada<U>&);
    template<class U>
    friend istream& operator>>(istream&,coada<U>&);
};
template <class T>
ostream& operator<< (ostream& out,nod<T> p)
{
    out<<p.ch;
    return out;
}
template <class T>
istream& operator>>(istream& in,nod<T>& p)
{
    in>>p.ch;
    return in;
}
template <class T>
ostream& operator<<(ostream& out,coada<T>& ob)
{
    while(ob.first!=NULL)
    {
        out<<*ob.first<<' ';
        ob.pop();
    }
    return out;
}
template<class T>
istream& operator>>(istream& in,coada<T>& ob)
{
    while(ob.first!=NULL) ob.pop();
    nod<T> q;
    int nr;
    in>>nr;
    while(nr--)
    {
        in>>q;
        ob.push(q.ch);
    }
    return in;
}
int main()
{
    ///declarare
    coada<char> o1;
    coada<int> o2;
    coada<long long> o3;
    coada<char> o4[100];
    coada<long long> o6;
    coada<int> o7,o8;
    int n;
    ifstream f("date.in");
    ofstream g("date.out");
    ///citire si scriere
    /*f>>o1;
    f>>o2;
    f>>o3;
    cout<<o1<<'\n';*/
    ///citirea, memorarea si afisarea a n obiecte
    /*f>>n;
    for(int i=0; i<n; ++i)
        f>>o4[i];
    for(int i=0; i<n; ++i)
        g<<o4[i]<<'\n';*/
    ///constructor de copiere
    /*coada<int> o5(o2);
    cout<<o5<<'\n';*/
    ///operator =
    /*o6=o3;
    cout<<o6<<'\n';*/
    ///destructor
    ///operator ==, !=, <
    /*cin>>o3>>o6;
    if(o3==o6) cout<<"Obiecte egale\n";
    if(o3!=o6) cout<<"Obiecte diferite\n";
    f>>n;
    for(int i=0; i<n; ++i)
        f>>o4[i];
    sort(o4,o4+n);
    for(int i=0; i<n; ++i)
        g<<o4[i]<<'\n';*/
    ///operatii(push,pop,top)
    /*o1.push('a');
    o1.push('c');
    cout<<o1.top()<<'\n';
    o1.pop();
    cout<<o1.top()<<'\n';
    cout<<o1<<'\n';*/
    ///citire+scriere
    /*cin>>o1;
    cout<<o1<<'\n';*/
    ///operator +
    /*cin>>o7>>o8;
    o2=o7+o8;
    cout<<o2<<'\n';*/
    ///operator -
    /*cin>>o7>>o8;
    o7-o8;
    cout<<o7<<'\n'<<o8<<'\n';*/
    return 0;
}

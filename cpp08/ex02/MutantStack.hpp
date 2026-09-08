#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);

        void push(T num);
        void pop();
        T &top();
        bool empty() const;
        // se pone typename delante porque sino el compilador no sabe si es o un tipo o un atributo estatico o lo que sea
        typename std::stack<T>::size_type size() const;

        iterator begin();
        iterator end();
    };

template <typename T>
void MutantStack<T>::push(T num)
{
    std::stack<T>::push(num);
}

template <typename T>
void MutantStack<T>::pop()
{
    std::stack<T>::pop();
}

template <typename T>
T &MutantStack<T>::top()
{
    return std::stack<T>::top();
}

template <typename T>
bool MutantStack<T>::empty() const
{
    if(std::stack<T>::empty() == true)
        return true;
    return false;
}
template <typename T>
typename std::stack<T>::size_type MutantStack<T>::size() const
{
    return std::stack<T>::size();
}

#endif
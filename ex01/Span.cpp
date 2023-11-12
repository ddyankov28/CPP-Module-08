/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:18 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/12 16:33:31 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span() : _maxSize(0)
{
    std::cout << GREEN << "Span Default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int N) : _maxSize(N)
{
    std::cout << GREEN << "Span Parameter constructor called" << RESET << std::endl;
}

Span::Span(const Span& inst)
{
    *this = inst;
    std::cout << YELLOW << "Span Copy constructor called" << RESET << std::endl;
}

Span&   Span::operator=(const Span& inst)
{
    if (this != &inst)
    {   
        _maxSize = inst._maxSize;
        _container = inst._container;
    }
    std::cout << CYAN << "Span Copy assignment operator called" << RESET << std::endl;
    return *this;
}

Span::~Span()
{
    std::cout << RED << "Span Destructor called" << RESET << std::endl;
}

void    Span::addNumber(int number)
{
    if (_container.size() == _maxSize)
        throw std::out_of_range("There is no place for more elements in the container");
    _container.insert(number);
}

void    Span::fillContainer()
{
    std::srand(time(NULL));
    std::multiset<int>    multiset;
    for(unsigned int i = 0; i < _maxSize; i++)
    {
        int number = rand();
        multiset.insert(number);
    }
    if (_container.size() + std::distance(multiset.begin(), multiset.end()) > _maxSize)
        throw std::out_of_range("There is no place for more elements in the container");
    _container.insert(multiset.begin(), multiset.end());
    
    /*std::multiset<int>::const_iterator    itBegin;
    std::multiset<int>::const_iterator    itEnd = multiset.end();
    for(itBegin = multiset.begin(); itBegin != itEnd; itBegin++)
        std::cout << *itBegin << " ";
    std::cout << std::endl;
    std::multiset<int>::const_iterator it;
    it = std::min_element(_container.begin(), _container.end());
    int smallest = *it;
    it = std::max_element(_container.begin(), _container.end());
    int biggest = *it;
    std::cout << "The smallest element is: " << smallest << std::endl;
    std::cout << "The biggest element is: " << biggest << std::endl;*/
}

int Span::shortestSpan() const
{
    checkContainer();
    std::multiset<int>::const_iterator  itZero = _container.begin();
    std::multiset<int>::const_iterator  itBegin = _container.begin();
    int shortestSpan = abs(*itZero - *(++itBegin));
    unsigned int a = 0;
    while (a < _container.size())
    {
        itBegin = itZero;
        if (shortestSpan > abs(*itZero - *(++itBegin)))
            shortestSpan = abs(*itZero - *itBegin);
        itZero++;
        a++;
    }
    return shortestSpan;
}

int Span::longestSpan() const
{
    checkContainer();
    int smallest;
    int biggest;
    std::multiset<int>::const_iterator it; 
    
    it = std::min_element(_container.begin(), _container.end());
    smallest = *it;
    it = std::max_element(_container.begin(), _container.end());
    biggest = *it;
    return abs(biggest - smallest);
}

void    Span::checkContainer() const
{
    if (_container.size() < 2)
        throw std::out_of_range("Not enough numbers to have a span");
}

void    Span::printContainer() const
{
    std::multiset<int>::const_iterator  itBegin;
    std::multiset<int>::const_iterator  itEnd = _container.end();
    int i = 0;
    for(itBegin = _container.begin(); itBegin != itEnd; itBegin++)
    {
        std::cout  << "Container[" << i << "] = " << *itBegin << " " << std::endl;
        i++;
    }
}

unsigned int Span::getMaxSize() const
{
    return _maxSize;
}

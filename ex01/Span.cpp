/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:18 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/11 13:45:48 by ddyankov         ###   ########.fr       */
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
    _container.push_back(number);
}

void    Span::fillContainer()
{
    std::srand(time(NULL));
    std::vector<int>    vector(_maxSize);
    for(unsigned int i = 0; i < _maxSize; i++)
    {
        int number = rand();
        vector[i] = number;
    }
    if (_container.size() + std::distance(vector.begin(), vector.end()) > _maxSize)
        throw std::out_of_range("There is no place for more elements in the container");
    _container.insert(_container.begin(), vector.begin(), vector.end());
    /*for (unsigned int i = 0; i < _container.size(); i++)
        std::cout << _container[i] << " ";
    std::cout << std::endl;
    std::vector<int>::const_iterator it;
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
    int shortestSpan = abs(_container.at(0) - _container.at(1));
    std::vector<int>::const_iterator it;
    for (it = _container.begin(); it < _container.end(); it++)
    {
        if (shortestSpan > abs(*it - *(it + 1)))
            shortestSpan = abs(*it - *(it + 1));
    }
    return shortestSpan;
}

int Span::longestSpan() const
{
    checkContainer();
    int smallest;
    int biggest;
    std::vector<int>::const_iterator it; 
    
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
    for (int i = 0; i < static_cast<int>(_container.size()); i++)
        std::cout  << "Container[" << i + 1 << "] = " << _container.at(i) << " " << std::endl;
}

unsigned int Span::getMaxSize() const
{
    return _maxSize;
}

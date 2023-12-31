/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:09 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/13 09:29:30 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>
# include <algorithm>

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

class Span
{
    private:
        std::multiset<int>  _container;
        unsigned int        _maxSize;
    public:
        Span();                                 // default constructor
        Span(unsigned int N);                   // param constructor
        Span(const Span& inst);                 // copy constructor
        Span&   operator=(const Span& inst);    // copy assignment operator    
        ~Span();                                // destructor

        // subject
        void            addNumber(int number);
        int             shortestSpan() const;
        int             longestSpan() const;


        // my own
        void            fillContainer();
        unsigned int    getMaxSize() const;
        void            printContainer() const;
        void            checkContainer() const;
};

# endif

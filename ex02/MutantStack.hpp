/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:31:04 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/12 16:18:14 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <ctime>

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

template < typename T >
class   MutantStack : public std::stack<T>
{
    public:

        MutantStack()   //  --- Default Constructor --- //
        {
            std::cout << GREEN << "MutantStack Default constructor called" << RESET << std::endl;
        }

        MutantStack(const MutantStack& inst)   // --- Copy Constructor --- //
        {
            *this = inst;
            std::cout << YELLOW << "MutantStack Copy constructor called" << RESET << std::endl;
        }
        
        MutantStack&    operator=(const MutantStack& inst) // --- Copy assignment operator --- //
        {
            if (this != &inst)
                this->c = inst.c;
            std::cout << CYAN << "MutantStack Copy assignment operator called" << RESET << std::endl;
            return *this;
        }

        ~MutantStack()  // --- Destructor --- //
        {
            std::cout << RED << "MutantStack Destructor called" << RESET << std::endl;
        }
        
        typedef typename    std::stack<T>::container_type::iterator                 iterator;
        typedef typename    std::stack<T>::container_type::const_iterator           const_iterator;
        typedef typename    std::stack<T>::container_type::reverse_iterator         reverse_iterator;
        typedef typename    std::stack<T>::container_type::const_reverse_iterator   const_reverse_iterator;

        iterator    begin()
        {   return this->c.begin(); }
        
        iterator    end()
        {   return this->c.end();   }

        const_iterator  begin() const
        {   return this->c.begin(); }

        const_iterator  end() const
        {   return this->c.end();   }

        reverse_iterator    rbegin()
        {   return this->c.rbegin();    }

        reverse_iterator    rend()
        {   return this->c.rend();  }
        
        const_reverse_iterator  rbegin() const
        {   return this->c.rbegin();    }

        const_reverse_iterator  rend() const
        {   return this->c.rend();    }
};

# endif
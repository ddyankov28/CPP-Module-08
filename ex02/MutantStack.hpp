/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:31:04 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/11 15:29:22 by ddyankov         ###   ########.fr       */
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
        typedef typename    std::deque<T>::iterator                 iterator;
        typedef typename    std::deque<T>::const_iterator           const_iterator;
        typedef typename    std::deque<T>::reverse_iterator         reverse_iterator;
        typedef typename    std::deque<T>::const_reverse_iterator   const_reverse_iterator;

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
        {   return this->c.rbegin();    }
};

# endif
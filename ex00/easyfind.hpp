/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:37:37 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/13 09:26:36 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <ctime>
# include <stdexcept>
# include <vector>
# include <deque>
# include <list>

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

template < typename T >
void   easyFind(const T& ctr, int toFind)
{
    typename T::const_iterator it;
    
    it = find(ctr.begin(), ctr.end(), toFind);
    if (it == ctr.end())
        throw std::out_of_range("Number was not found in the container");
    std::cout << GREEN << "The Number " << toFind << " was found at position "; 
    std::cout << std::distance(ctr.begin(), it) << RESET << std::endl;
}

# endif

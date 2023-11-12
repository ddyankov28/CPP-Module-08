/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:37:21 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/12 14:38:36 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

int main()
{
    std::vector<int>    intVector;
    std::deque<int>     intDeque;
    std::list<int>      intList;
    int n;
    std::list<int>::const_iterator it;
    std::srand(std::time(NULL));
    
    for (int i = 0; i < 25; i++)
    {
        n = rand() % 51;
        intVector.push_back(n);
        intDeque.push_front(n);
        intList.push_front(n);
    }
    for (unsigned int i = 0; i < intVector.size(); i++)
        std::cout << intVector.at(i) << " ";
    std::cout << std::endl;LINE;
    for (unsigned int i = 0; i < intDeque.size(); i++)
        std::cout << intDeque.at(i) << " ";
    std::cout << std::endl;LINE;
    intList.sort();
    for (it = intList.begin(); it != intList.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;LINE;
    try
    {
        easyFind(intVector, 42);
    }
    catch(std::exception& e)
    {
        std::cerr << URED << "Exception with Vector: " << e.what() << RESET << std::endl;
    }
    try
    {
        easyFind(intDeque, 42);
    }
    catch(std::exception& e)
    {
        std::cerr << URED << "Exception with Deque: " << e.what() << RESET << std::endl;
    }
    try
    {
        easyFind(intList, 42);
    }
    catch(std::exception& e)
    {
        std::cerr << URED << "Exception with List: " << e.what() << RESET << std::endl;
    }
    return 0;
}

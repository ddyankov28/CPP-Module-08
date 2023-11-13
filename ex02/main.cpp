/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:30:54 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/13 09:44:22 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int main()
{   
    MutantStack<int>    s1;LINE;

    for(int i = 0; i < 10; i++)
        s1.push(i * 3);
    
    //  --- Normal iterator --- //
    std::cout << GREEN << "Checking the normal iterator" << RESET << std::endl;
    MutantStack<int>::iterator  itBegin = s1.begin();
    MutantStack<int>::iterator  itEnd = s1.end();
    while (itBegin != itEnd)
    {
        *itBegin *= 2; 
        std::cout << *itBegin << " ";
        itBegin++;
    }
    std::cout << std::endl;LINE;

    //  --- Const iterator ---  //
    std::cout << GREEN << "Checking the const iterator" << RESET << std::endl;
    MutantStack<int>::const_iterator    itConstBegin = s1.begin();
    MutantStack<int>::const_iterator    itConstEnd = s1.end();
    while (itConstBegin != itConstEnd)
    {
        // *itConstBegin *= 2;   trying to change the status of the object
        std::cout << *itConstBegin << " ";
        itConstBegin++;
    }
    std::cout << std::endl;LINE;

    //  --- Reverse iterator ---  //
    std::cout << GREEN << "Checking the reverse iterator" << RESET << std::endl;
    MutantStack<int>::reverse_iterator  itReverseBegin = s1.rbegin();
    MutantStack<int>::reverse_iterator  itReverseEnd = s1.rend();
    while (itReverseBegin != itReverseEnd)
    {
        *itReverseBegin /= 2;
        std::cout << *itReverseBegin << " ";
        itReverseBegin++;
    }
    std::cout << std::endl;LINE;

    //  ---Coonst Reverse iterator --- //
    std::cout << GREEN << "Checking the const reverse iterator" << RESET << std::endl;
    MutantStack<int>::const_reverse_iterator    itConstReverseBegin = s1.rbegin();
    MutantStack<int>::const_reverse_iterator    itConstReverseEnd = s1.rend();
    while (itConstReverseBegin != itConstReverseEnd)
    {
        // *itConstReverseBegin *= 2;  trying to change the status of the object
        std::cout << *itConstReverseBegin << " ";
        itConstReverseBegin++;
    }
    std::cout << std::endl;LINE;
    
    /*MutantStack<int>    mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);*/
    return 0;
}
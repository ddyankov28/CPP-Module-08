/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:23:52 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/12 16:44:29 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int main()
{
    {
        Span    one;
        std::cout << one.getMaxSize() << std::endl;
        try
        {
            one.shortestSpan();
        }
        catch (std::exception& e)
        {
            std::cerr << URED << "Exception: " << e.what() << RESET << std::endl;
        }
    }LINE;
    {
        Span    three(5);
        Span    two(three);
        std::cout << "The Max Size of the container is " << two.getMaxSize() << std::endl;
        try
        {
            two.addNumber(54);
            two.addNumber(52);
            two.addNumber(6);
            two.addNumber(1);
            two.addNumber(4);
            two.printContainer();
            std::cout << "Shortest Span is: " << two.shortestSpan() << std::endl;
            std::cout << "Longest Span is: " << two.longestSpan() << std::endl;
            two.addNumber(123);     // to throw the exception
        }
        catch(std::exception& e)
        {
            std::cerr << URED << "Exception: " << e.what() << RESET << std::endl;
        }
    }LINE;
    {
        Span    big(20000);
        std::cout << "The Max Size of the container is " << big.getMaxSize() << std::endl;
        try
        {
            big.fillContainer();
            std::cout << "Shortest Span is: " << big.shortestSpan() << std::endl;
            std::cout << "Longest Span is: " << big.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << URED << "Exception: " << e.what()  << RESET << std::endl;
        }
    }LINE;
    std::cout << "Program ends here" << std::endl;
    return 0;
}
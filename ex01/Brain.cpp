/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:01:13 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 21:22:10 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "default";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
}

Brain   &Brain::operator=(const Brain &rhs)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = rhs._ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, const std::string &idea)
{
    if (i >= 0 && i < 100)
        _ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
    if (i >= 0 && i < 100)
        return (_ideas[i]);
    return ("");
}

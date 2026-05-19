/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:49:25 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 21:45:47 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
        _type = rhs._type;
    std::cout << "Dog assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Bark Bark" << std::endl;
}
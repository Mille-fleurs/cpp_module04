/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:49:25 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 22:25:18 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    _dogBrain = new Brain;
	std::cout << "Default Contsructor is Called for Cat!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    _dogBrain = new Brain(*other._dogBrain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete _dogBrain;
        _dogBrain = new Brain(*rhs._dogBrain);
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete _dogBrain;
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Bark Bark" << std::endl;
}
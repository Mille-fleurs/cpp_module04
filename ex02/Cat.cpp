/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:49:20 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 21:46:42 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    _catBrain = new Brain;
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    _catBrain = new Brain(*other._catBrain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete this->_catBrain;
        _catBrain = new Brain(*rhs._catBrain);
        std::cout << "Cat assignment operator called" << std::endl;
    }
    return (*this);
}

Cat::~Cat()
{
    delete _catBrain;
    std::cout << "Cat destructor called" << std::endl;
}

Brain *Cat::getBrain(void) const
{
    return (_catBrain);
}

void    Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}
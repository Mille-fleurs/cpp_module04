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

Cat::Cat() : AAnimal("Cat")
{
    _catBrain = new Brain;
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
    _catBrain = new Brain(*other._catBrain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        Brain *tmp = new Brain(*rhs._catBrain);
        AAnimal::operator=(rhs);
        delete _catBrain;
        _catBrain = tmp;
    }
    std::cout << "Cat assignment operator called" << std::endl;
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
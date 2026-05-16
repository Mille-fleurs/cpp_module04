/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:49:17 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 20:00:23 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//  std::string type;
// public:
//     Animal();
//     Animal(std::string type);
//     Animal(const Animal &other);
//     Animal &operator=(const Animal &rhs);
//     virtual ~Animal();

//     std::string getType() const;
//     virtual void    makeSound() const;

Animal::Animal() : _type("Default")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal " << _type << " constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
        _type = rhs._type;
    std::cout << "Animal assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (_type);
}

void    Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

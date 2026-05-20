/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:49:28 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 21:32:54 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_dogBrain;
public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &rhs);
    ~Dog();

    Brain *getBrain(void) const;
    virtual void    makeSound() const;
};

#endif
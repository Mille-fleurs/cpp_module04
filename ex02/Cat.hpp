/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:49:23 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 22:25:32 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain *_catBrain;
public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &rhs);
    ~Cat();

    Brain *getBrain(void) const;
    virtual void    makeSound() const;
};

#endif
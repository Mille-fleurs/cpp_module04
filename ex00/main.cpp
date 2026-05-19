/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:49:31 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 20:46:46 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "\n--- Normal Classes Tests ---\n" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout <<"\n--- Wrong Classes Tests ---\n" << std::endl;
    const WrongAnimal *meta2 = new WrongAnimal();
    const WrongAnimal *wc1 = new WrongCat();
    const WrongCat *wc2 = new WrongCat();
    std::cout << wc1->getType() << " " << std::endl;
    std::cout << meta2->getType() << " " << std::endl;
    std::cout << wc2->getType() << " " << std::endl;
    wc1->makeSound();
    meta2->makeSound();
    wc2->makeSound();

    delete meta;
    delete i;
    delete j;
    delete meta2;
    delete wc2;
    return (0);
}

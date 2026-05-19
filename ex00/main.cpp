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
    std::cout << "\n--- Animal polymorphism test ---\n" << std::endl;

    const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    std::cout << meta->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout <<"\n--- WrongAnimal test ---\n" << std::endl;

    WrongCat wrongCat;
    const WrongAnimal *wrong = &wrongCat;

    std::cout << wrong->getType() << std::endl;
    
    wrong->makeSound();
    wrongCat.makeSound();

    return (0);
}

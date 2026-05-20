/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:49:31 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 22:25:11 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    std::cout << "\n---- Basic polymorphism + virtual destructor ----\n";

    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    dog->makeSound();
    cat->makeSound();
    delete dog;
    delete cat;

    std::cout << "\n---- Array of animals ----\n";

    Animal  *animals[4];
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Animal " << i << " : [" << animals[i]->getType() << "] : ";
        animals[i]->makeSound(); 
    }
    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n---- Deep copy scope test ----\n";
    Dog Momo;
    {
        Dog tmp = Momo;
        std::cout << "tmp goes out of scope:\n";
    }
    std::cout << Momo.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\n---- Copy constructor test ----\n";

    Dog originalDog;
    Dog copiedDog(originalDog);
    Cat originalCat;
    Cat copiedCat(originalCat);

    std::cout << "\n---- Assignment operator test ---\n";
    
    Dog dog1;
    Dog dog2;
    dog1 = dog2;
    Cat cat1;
    Cat cat2;
    cat1 = cat2;

    std::cout << "\n---- End of main ----\n";
    return (0);
}

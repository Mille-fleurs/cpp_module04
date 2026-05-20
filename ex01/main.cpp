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
    
    std::cout << "\n---- Copy constructor test ----\n";

    Cat originalCat;
    Cat copiedCat(originalCat);

    std::cout << "\n---- Deep copy test ----\n";
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Original idea");
    Dog copiedDog(originalDog);
    originalDog.getBrain()->setIdea(0, "Changed idea");
    std::cout << "Original: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy: " << copiedDog.getBrain()->getIdea(0)<< std::endl;

    std::cout << "\n---- Assignment operator test ---\n";
    
    Cat cat1;
    Cat cat2;
    cat2 = cat1;

    std::cout << "\n---- Deep copy assignment test ---\n";

    Dog dog1;
    Dog dog2;
    dog1.getBrain()->setIdea(0, "Dog1 idea");
    dog2 = dog1;
    dog1.getBrain()->setIdea(0, "Dog1 changed");
    std::cout << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n---- End of main ----\n";
    return (0);
}

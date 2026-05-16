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
    std::cout << "\n---- Basic construction/destruction ----\n";
    std::cout << "\n// Creating animals //\n";
    const Animal *cat = new Cat();
    const Animal *dog = new Dog();
    std::cout << "\n// Deleting animals //\n";
    delete dog;
    delete cat;

    std::cout << "\n---- Array of animals (half dogs, half cats) ----\n";
    Animal  *animals[4];
    std::cout << "\n// Creating animals //\n";
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();
    std::cout << "\n// Animal sounds //\n" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Animal" << i << " : [" << animals[i]->getType() << "] : ";
        animals[i]->makeSound(); 
    }
    std::cout << "\n// Deleting animals //\n";
    for (int i = 0; i < 4; i++)
        delete animals[i];
    
    std::cout << "\n---- Deep copy test ----\n";
    Dog originalDog;
    std::cout << "\n// Copying dog //\n";
    Dog copiedDog(originalDog);
    Cat originalCat;
    std::cout << "\n// Copying dog //\n";
    Cat copiedCat(originalCat);

    std::cout << "\n---- Assignment operator test ---\n";
    Dog dog1;
    Dog dog2;
    dog1 = dog2;
    Cat cat1;
    Cat cat2;
    cat1 = cat2;

    return (0);
}

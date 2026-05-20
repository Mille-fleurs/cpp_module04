/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chitoupa <chitoupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:00:58 by chitoupa          #+#    #+#             */
/*   Updated: 2026/05/16 21:29:43 by chitoupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string _ideas[100];
public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &rhs);
    ~Brain();

    void    setIdea(int i, const std::string &idea);
    std::string getIdea(int i) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:06:08 by sle-huec          #+#    #+#             */
/*   Updated: 2022/11/02 17:59:33 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string>

void	upp_str(char *arg)
{
	std::string upp_str;
	for (int i = 0; arg[i] != '\0'; i++)
	{
		upp_str+=toupper(arg[i]);
	}
	std::cout << upp_str;
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++)
		upp_str(av[i]);
	std::cout << std::endl;
	return 0;
}
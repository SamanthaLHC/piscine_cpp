/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:39:26 by samantha          #+#    #+#             */
/*   Updated: 2022/11/14 16:58:43 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <limits>
#include <stdlib.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _count_user(0), _user_cmd(""), _flag_max(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

//==============================================================================
//           handler input
//==============================================================================

std::string PhoneBook::get_handler_input(void) const
{
	return this->_user_cmd;
}

void PhoneBook::set_handler_input(void)
{
	std::cout << "\033[1;33mContact handler: you can either type ADD, SEARCH or EXIT\033[0m" << std::endl;
	std::getline(std::cin, _user_cmd);
}

//==============================================================================
//           cmd add
//==============================================================================

void PhoneBook::cmd_add()
{
	if (this->_count_user == 8)
	{
		this->_flag_max = 1;
		this->_count_user = 0;
	}

	this->_contacts_in_rep[this->_count_user].set_name();
	this->_contacts_in_rep[this->_count_user].set_lastname();
	this->_contacts_in_rep[this->_count_user].set_surname();
	this->_contacts_in_rep[this->_count_user].set_phone_number();
	this->_contacts_in_rep[this->_count_user].set_darkest_secret();

	this->_count_user++;
}

//==============================================================================
//           check input in display contact
//==============================================================================
int PhoneBook::check_index_input(int idx)
{
	int max = 0;
	if (this->_flag_max == 0)
		max = this->_count_user;
	else
		max = 8;
	if (idx >= 1 && idx <= max)
		return 1;
	return -1;
}

//==============================================================================
//           cmd search
//==============================================================================

int PhoneBook::cmd_search()
{
	int idx_input = 0;

	while (idx_input == 0)
	{
		std::cout << "\033[1;34mEnter the contact's number you want to display:\033[0m" << std::endl;
		std::cin >> idx_input;
		if (std::cin.eof() == true)
		{
			std::cout << "\033[1;33mAll contacts are lost.\033[0m" << std::endl;
			return -1;
		}
		else if (std::cin.good() == false)
		{
			std::cin.clear();
			idx_input = 0;
			std::string trash;
			std::cin >> trash;
			std::cout << "\033[1;31mBad input: only enter a DIGIT included in the range.\033[0m" << std::endl;
			continue;
		}
		std::cin.ignore();
		if (check_index_input(idx_input) < 0)
		{
			idx_input = 0;
			std::cout << "\033[1;31mBad input: only enter a number included in the range.\033[0m" << std::endl;
			continue;
		}
		else
		{
			std::cout << this->_contacts_in_rep[idx_input - 1].get_name() << std::endl;
			std::cout << this->_contacts_in_rep[idx_input - 1].get_lastname() << std::endl;
			std::cout << this->_contacts_in_rep[idx_input - 1].get_surname() << std::endl;
			std::cout << this->_contacts_in_rep[idx_input - 1].get_phone_number() << std::endl;
			std::cout << this->_contacts_in_rep[idx_input - 1].get_darkest_secret() << std::endl;
			return 0;
		}
	}
	return 0;
}
//==============================================================================
//          troncate str
//==============================================================================

void PhoneBook::troncate_and_print_str(std::string field)
{
	field.resize(9);
	std::cout << std::setw(10) << field + "."
			  << "|";
}

//==============================================================================
//          print contact
//==============================================================================

void PhoneBook::print_contact()
{
	int max = 0;
	if (this->_flag_max == 0)
		max = this->_count_user;
	else
		max = 8;

	for (int i = 0; i < max; i++)
	{
		std::cout << std::setw(10) << i + 1 << std::setfill(' ') << "|";
		if (this->_contacts_in_rep[i].get_name().length() > 10)
			troncate_and_print_str(this->_contacts_in_rep[i].get_name());
		else
			std::cout << std::setw(10) << this->_contacts_in_rep[i].get_name() << std::setfill(' ') << "|";
		if (this->_contacts_in_rep[i].get_lastname().length() > 10)
			troncate_and_print_str(this->_contacts_in_rep[i].get_lastname());
		else
			std::cout << std::setw(10) << this->_contacts_in_rep[i].get_lastname() << std::setfill(' ') << "|";
		if (this->_contacts_in_rep[i].get_surname().length() > 10)
		{
			troncate_and_print_str(this->_contacts_in_rep[i].get_surname());
			std::cout << std::endl;
		}
		else
			std::cout << std::setw(10) << this->_contacts_in_rep[i].get_surname() << std::setfill(' ') << "|"
					  << std::endl;
	}
}

//==============================================================================
//           user's actions execution
//==============================================================================

int PhoneBook::exec_user_cmd()
{
	if (this->_user_cmd == "ADD")
		this->cmd_add();
	else if (this->_user_cmd == "SEARCH")
	{
		if (this->_count_user > 0)
		{
			print_contact();
			if (cmd_search() < 0)
			{
				std::cin.ignore();
				return -1;
			}
		}
		else
			std::cout << "\033[1;34mNo entries in the phonebook. You should enter ADD and fill the fields.\033[0m" << std::endl;
	}
	else if (this->_user_cmd == "EXIT" || std::cin.eof() == true)
	{
		std::cout << "\033[1;33mAll contacts are lost.\033[0m" << std::endl;
		return -1;
	}
	else
		std::cout << "\033[1;31monly ADD, SEARCH or EXIT must be typed\033[0m" << std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:19:10 by sle-huec          #+#    #+#             */
/*   Updated: 2022/11/14 15:52:40 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <iostream>

Contact::Contact(void) : _name(""), _lastname(""), _surname(""), _phone_number(""),
						_dark_secret("") {
	return;
}

Contact::~Contact(void){
	return;
}

//==============================================================================
//           name
//==============================================================================

std::string Contact::get_name(void)const
{
	return this->_name;
}

void Contact::clear_name(void)
{
	this->_name = "";
}

void Contact::set_name(void)
{
	clear_name();
	while (this->_name.length() == 0 && std::cin.eof() == false)
	{
		std::cout << "\033[1;32mEnter your name:\033[0m" << std::endl;		
		std::getline(std::cin, _name);
	}
}

//==============================================================================
//           lastname
//==============================================================================

std::string Contact::get_lastname(void)const
{
	return this->_lastname;
}

void Contact::clear_lastname(void)
{
	this->_lastname = "";
}

void Contact::set_lastname(void)
{
	clear_lastname();
	while (this->_lastname.length() == 0 && std::cin.eof() == false)
	{
		std::cout << "\033[1;32mEnter your lastname:\033[0m" << std::endl;
		std::getline(std::cin, _lastname);
	}
}

//==============================================================================
//           surname
//==============================================================================

std::string Contact::get_surname(void)const
{
	return this->_surname;
}

void Contact::clear_surname(void)
{
	this->_surname = "";
}

void Contact::set_surname(void)
{
	clear_surname();
	while (this->_surname.length() == 0 && std::cin.eof() == false)
	{
		std::cout << "\033[1;32mEnter your surname:\033[0m" << std::endl;
		std::getline(std::cin, _surname);
	}
}

//==============================================================================
//           phone_number
//==============================================================================

std::string Contact::get_phone_number(void)const
{
	return this->_phone_number;
}

void Contact::clear_phone_number(void)
{
	this->_phone_number = "";
}

void Contact::set_phone_number(void)
{
	clear_phone_number();
	while (this->_phone_number.length() == 0 && std::cin.eof() == false)
	{	
		std::cout << "\033[1;32mEnter your phone number:\033[0m"<< std::endl;
		std::getline(std::cin, _phone_number);
	}
}

//==============================================================================
//           darkest_secret
//==============================================================================

std::string Contact::get_darkest_secret(void)const
{
	return this->_dark_secret;
}

void Contact::clear_darkest_secret(void)
{
	this->_dark_secret = "";
}

void Contact::set_darkest_secret(void)
{
	clear_darkest_secret();
	while (this->_dark_secret.length() == 0 && std::cin.eof() == false)
	{
		std::cout << "\033[1;32mWhat is your darkest secret?\033[0m" << std::endl;
		std::getline(std::cin, _dark_secret);
	}
}

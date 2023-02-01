/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:14:31 by sle-huec          #+#    #+#             */
/*   Updated: 2022/11/14 16:25:05 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef CONTACT_H
# define CONTACT_H

class Contact{

public:
	Contact(void);
	~Contact();

	void set_name(void);
	std::string get_name(void)const;
	void clear_name(void);

	void set_lastname(void);
	std::string get_lastname(void)const;
	void clear_lastname(void);
	
	void set_surname(void);
	std::string get_surname(void)const;
	void clear_surname(void);
	
	void set_phone_number(void);
	std::string get_phone_number(void)const;
	void clear_phone_number(void);
	
	void set_darkest_secret(void);
	std::string get_darkest_secret(void)const;
	void clear_darkest_secret(void);

private:
	std::string _name;
	std::string _lastname;
	std::string _surname;
	std::string _phone_number;
	std::string _dark_secret;	
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:50:52 by sle-huec          #+#    #+#             */
/*   Updated: 2022/11/14 16:28:29 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>
#include <string>

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {
	
public:

	PhoneBook(void);
	~PhoneBook();

	void set_handler_input(void);
	int exec_user_cmd();

private:

	int	_count_user;
	std::string _user_cmd;
	int _flag_max;

	Contact _contacts_in_rep[8];
	
	void cmd_add();
	void print_contact();
	int cmd_search();
	void cmd_exit();
	void troncate_and_print_str(std::string field);
	int check_index_input(int idx);
	std::string get_handler_input(void)const;
};

#endif
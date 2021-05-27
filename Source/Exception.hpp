#pragma once

#include <string>
#include <exception>

struct Exception : public std::exception
{
	public:

	Exception(std::string message) : message(message) {}

	const char* what() const throw()
	{
	   return message.c_str();
	}

	private:

	std::string message;
};
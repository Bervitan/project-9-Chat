#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "Message.h"

struct UserLoginExp : public std::exception
{
	const char* what() const noexcept override { return "error: login is busy "; }
};

struct UserNameExp : public std::exception
{
	const char* what() const noexcept override { return "error: username is busy"; }
};

class Chat
{
	bool isChatWork_ = false;
	std::vector<User> users_;
	std::vector<Message> messages_;
	std::shared_ptr<User> currentUser_ = nullptr;

	void login();
	void signUp();
	void showChat() const;
	void showAllUersName() const;
	void addMessage();
	std::vector<User>& getAllUsers() { return users_; }
	std::vector<Message>& getAllMessage() { return messages_; }
	std::shared_ptr<User> getUserByLogin(const std::string& login) const;
	std::shared_ptr<User> getUserByName(const std::string& name) const;

public:

	void start();
	bool isChatWork() const { return isChatWork_; }
	std::shared_ptr<User> getCurrentUser() const { return currentUser_; }
	void showLoginMenu();
	void showUserMenu();

};
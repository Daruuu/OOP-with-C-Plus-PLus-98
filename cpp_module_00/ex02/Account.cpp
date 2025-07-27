#include "Account.hpp"

/*
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] index:2;amount:957;created
[19920104_091532] index:3;amount:432;created
[19920104_091532] index:4;amount:1234;created
[19920104_091532] index:5;amount:0;created
[19920104_091532] index:6;amount:754;created
[19920104_091532] index:7;amount:16576;created

[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
*/
static void	_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm* tmPtr = std::localtime(&now);
	// std::ostringstream oss;

	std::cout << '['
		<< std::setw(4) << std::setfill('0') << (tmPtr->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << (tmPtr->tm_mon + 1)
		<< std::setw(2) << std::setfill('0') << tmPtr->tm_mday
		<< '_'
		<< std::setw(2) << std::setfill('0') << tmPtr->tm_hour
		<< std::setw(2) << std::setfill('0') << tmPtr->tm_min
		<< std::setw(2) << std::setfill('0') << tmPtr->tm_sec
		<< ']';
}


Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts = _nbAccounts + 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	// [19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< initial_deposit << ";created" << std::endl;
}

/*
static void	displayAccountsInfos( void )
{
	// _displayTimestamp();
	// std::cout << << std::endl;

}
*/

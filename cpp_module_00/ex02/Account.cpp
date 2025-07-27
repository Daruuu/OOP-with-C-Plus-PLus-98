#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits= 0;
int	Account::_totalNbWithdrawals= 0;

void	Account::_displayTimestamp( void )
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
	_nbAccounts ++;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	// [19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
	<< initial_deposit << ";created" << std::endl;
}

/*
static void	displayAccountsInfos( void )
{
	// _displayTimestamp();
	// std::cout << << std::endl;

}
*/

/*
static int	getNbAccounts( void )
{
	return 0;
}

static int	getTotalAmount( void )
{
	return 0;
}
static int	getNbDeposits( void )
{
	return 0;
}

static int	getNbWithdrawals( void )
{
	return 0;
}

static void	displayAccountsInfos( void )
{
}
*/

Account::Account(void)
{
	// _accountIndex = 0;
	// _amount=0;
	// _nbDeposits=0;
	// _nbWithdrawals=0;
}

/*
Account::~Account( void )
{

}
void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{
	return false;
}

int		Account::checkAmount( void ) const
{
	return 0;
}

void	Account::displayStatus( void ) const
{

}
*/


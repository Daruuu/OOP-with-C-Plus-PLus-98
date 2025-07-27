#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits= 0;
int	Account::_totalNbWithdrawals= 0;

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm* tmPtr = std::localtime(&now);

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
	_nbAccounts++;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	// [19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
		<< _amount << ";created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:"
	<< _totalAmount << ";deposits" << _totalNbDeposits << ";withdrawals:"
	<< _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

int	Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

Account::Account(void)
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

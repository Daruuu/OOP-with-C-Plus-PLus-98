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

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< " accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

Account::Account( int initial_deposit )
{
	++_nbAccounts;
	// _totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	// [19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created"
				<< std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
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

//	TODO: end understand this function
void	Account::makeDeposit( int deposit )
{
	int	previous_amount = _amount;
	_amount += deposit;
	++_nbDeposits;
	_totalAmount += deposit;
	++_totalNbDeposits;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";p_amount:" << previous_amount
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

//	verify is hace minimum money to extract
//	if the account not have minimum money : declined the opeation
//	if has money:
//		- update the values in the account
//		- update the global values (_totalAmount, _totalNbWithdrawals)
//		- show a log of changes
//	return TRUE if completed the substract of money

bool	Account::makeWithdrawal( int withdrawal )
{
	//	1. check if enough balance
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout	<< " index:" << _accountIndex
					<< ";p_amount;" << _amount
					<< ";withdrawal:refused" << _amount
					<< std::endl;
		return false;
	}

	int	previous_amount = _amount;

	//	3. update current account state
	_amount -= withdrawal;
	_nbWithdrawals++;

	//	4. update static variables
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	//	5. print log with updated values
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";p_amount;" << previous_amount
				<< ";withdrawals:" << withdrawal
				<< ";amount;" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return true;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}


Account::Account(void)
{
	Account::_displayTimestamp();

	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed" << std::endl;
}

#include <iostream>
#include <ctime>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (_nbAccounts); }
int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::_displayTimestamp( void ) {
    std::time_t now = std::time(NULL);
    std::tm *tm = std::localtime(&now);

    char timestamp[256];
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", tm);

    std::cout << "[" << timestamp << "] ";
}

void Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _totalNbDeposits++;
    _totalAmount += deposit;

    this->_nbDeposits++;
    this->_amount += deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount(void) const { return this->_amount; }

bool Account::makeWithdrawal(int withdrawal) {
    if (this->checkAmount() < withdrawal) {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
        return false;
    }

    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;

    this->_nbWithdrawals++;
    this->_amount -= withdrawal;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

Account::Account(void) : _accountIndex(getNbAccounts()), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {}

Account::Account(int initial_deposit) : _accountIndex(getNbAccounts()), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

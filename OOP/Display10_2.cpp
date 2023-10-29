struct CDAccount {
	double balance;
	double interestRate;
	int term;
};

int main() {
	CDAccount account;
	account.balance = 1000.00;
	account.interestRate = 4.7;
	account.term = 11;
}
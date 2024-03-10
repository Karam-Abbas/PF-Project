#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

void Entry();
void Signup();
void Login();
void TableDecider();
void OrdinaryTable(int &bal ,int p_num);
void GoldenTable(int& bal, int p_num);
void choice(int& bal, int p_num);
int rollingAmount();
int rollingAmountfor1();
int rollingAmountfor2();
int playerTurns();
float GST(int bal);

int main() {
	
	cout << "---------------------Welcome to GameHouse---------------------"<<endl;

	Entry();

	cout << "Enter the Initial Balance:" ;
	int initial_balance = 0;
    cin >> initial_balance;

	TableDecider();

	
	int count = 5;
	while(count>0)           //This loop is for the number of rounds basically
	{
		cout << "---------- This is round " << count << "----------" << endl;
		int playerNumber;
		playerNumber = playerTurns();
		cout << "You are Player " << playerNumber << endl;     //Here we are generating player number


		cout << "Your round begins" << endl;
		count--;
		if (initial_balance > 0)                      // ordinaryTable function calling
		{
			OrdinaryTable(initial_balance, playerNumber);
			cout << "Your updated balance is:" << initial_balance << endl;
		}
		else
		{
			cout << "Insufficient balance for next round";
		}

		
	}

	int playerNumber_forgt;
	playerNumber_forgt = playerTurns();
	int count_gt = 3;
	
	cout << "Do you want to play on golden table(Y)and for FURTHER CHOICES(N)?(Y/N):";

	char tb_ans;
	cin >> tb_ans;
	if (tb_ans == 'y' || tb_ans == 'Y')
	{
		while (count_gt > 0)
		{
			count_gt--;
			cout << "----------Round of golden table-" << count_gt << "----------"<<endl;
			if (initial_balance > 1500)
			{
				GoldenTable(initial_balance, playerNumber_forgt);
			}
			else
			{
				cout << "Insufficient balance for golden table";
			}

		}
	}
	else if (tb_ans == 'n' || tb_ans == 'N') 
    {
		choice(initial_balance, playerNumber_forgt);
	}
	else
	{
		cout << "Thanks for choosing us....." << endl;
	}
	cout << "Your NET balance is:" << initial_balance << endl;
	float gst_balance = 0.0;
	gst_balance = GST(initial_balance);
	float final_balance = 0.0;
	final_balance = initial_balance - gst_balance;
	cout << "After GST deduction your balance is " << final_balance << endl;

	system("pause");
	return 0;
}

void Entry() {
	cout << "Is it your first time(Y/N):";
	char ans;
	cin >> ans;
	if (ans == 'Y'|| ans == 'y')
	{
		cout << " Plz sign up then: " << endl;
			Signup();
	}
	else if (ans == 'N'|| ans == 'n')
	{
		cout << " Plz Log in then: " << endl;
		Login() ;
	}
}

void Signup() {

	string name;
	cout << "Enter your name :" ;
	cin.ignore();
	getline (cin, name);

	cout << "Enter your CNIC :" ;
	int CNIC;
	cin >> CNIC;

	string Address;
	cout << "Enter your Address :" ;
	cin.ignore();
	getline (cin, Address);

	cout << "Sign up successful!!!!!" << endl;
	cout << "Welcome to Gameroom" << endl;

}
void Login() {

	string CNIC;
	cout << "Enter CNIC for confirmation :";
	cin.ignore();
	getline (cin, CNIC);

	string CNIC1 = "123456";
	string  CNIC2 = "987654";
	string CNIC3 = "753159";

	if ( CNIC == CNIC1)
	{
		cout << "Log in Successfull!!!!" << endl;
	}
	else if (CNIC == CNIC2)
	{
		cout << "Log in Successfull!!!!" << endl;
	}
	else if ( CNIC == CNIC3)
	{
		cout << "Log in Successfull!!!!" << endl;
	}
	else {
		cout << "User not found!!!" << endl;
		cout << "Plz create a new account....." << endl;
		Signup();
	}

}

int playerTurns()
{
	int playerno;
	
	playerno = (rand() % 3) + 1;
	return playerno;
}

void TableDecider() 
{
	int tableNumber;
	
	tableNumber = (rand() % 6)+1;
	cout << "You will be playing at Table No " << tableNumber << " with 2 players " << endl;
}
int rollingAmount() 
{
	
	int rolling;
	
	rolling = (rand() % 10)+1;
	return rolling;
}
int rollingAmountfor1()
{

	int rolling;
	
	rolling = (rand() % 3)+1;
	return rolling;
}
int rollingAmountfor2()
{

	int rolling;
	
	rolling = (rand() % 4)+1;
	return rolling;
}
void OrdinaryTable(int &bal, int p_num)
{
	int betting_Amount = 0;
	int betting_number = 0;
	int rolling = rollingAmount();
	
	
		if (p_num == 1 )
		{
			cout << "Betting Number (0 - 10): ";
			cin >> betting_number;


			cout << "Betting Amount : ";
			cin >> betting_Amount;
			int remaining_amount = bal - betting_Amount;

			int rolling1 = rollingAmountfor1();
			int rolling2 = rollingAmountfor2();

			cout << "Player 2 bet's on :" << rolling1;
			cout << endl;
			cout << "Player 3 bet's on :" << rolling2;
			cout << endl;
			cout << "Number on the Rolling: " << rolling << endl;
			
			if (betting_number == rolling)
			{
				cout << "Player" << p_num << " Wins... " << endl;
			
				cout << "Congratulations... You have won... " << endl;
				int amount_won = 0;
				amount_won = betting_Amount * 2;
				bal = remaining_amount + amount_won;
			}
			else
			{
				bal = remaining_amount;
				cout << "Alas....You Lost(Better Luck Next Time)" << endl;
			}
			
		}

		else if (p_num == 2)
		{
			int rolling1 = rollingAmountfor1();
			int rolling2 = rollingAmountfor2();
			cout << "Player 1 bet's on :" << rolling1;
			cout << endl;

			cout << "Betting Number (0 - 10): ";
			cin >> betting_number;

			cout << "Betting Amount : ";
			cin >> betting_Amount;
			int remaining_amount = bal - betting_Amount;

			cout << "Player 3 bet's on :" << rolling2;
			cout << endl;

			cout << "Number on the Rolling: " << rolling << endl;

			if (betting_number == rolling)
			{
				cout << "Player" << p_num << " Wins... " << endl;
				
				cout << "Congratulations... You have won... " << endl;
				int amount_won = 0;
				amount_won = betting_Amount * 2;
				bal = remaining_amount + amount_won;
			}
			else
			{
				bal = remaining_amount;
				cout << "Alas....You Lost(Better Luck Next Time)" << endl;
			}
			
		}
		else if (p_num == 3)
		{
			int rolling1 = rollingAmountfor1();
			int rolling2 = rollingAmountfor2();
			cout << "Player 1 bet's on :" << rolling1;
			cout << endl;
			cout << "Player 2 bet's on :" << rolling2;
			cout << endl;

			cout << "Betting Number (0 - 10): ";
			cin >> betting_number;


			cout << "Betting Amount : ";
			cin >> betting_Amount;
			int remaining_amount = bal - betting_Amount;


			cout << "Number on the Rolling: " << rolling << endl;

			if (betting_number == rolling)
			{
				cout << "Player" << p_num << " Wins... " << endl;
				
				cout << "Congratulations... You have won... " << endl;
				int amount_won = 0;
				amount_won = betting_Amount * 2;
				bal = remaining_amount + amount_won;
			}
			else
			{
				bal = remaining_amount;
				cout << "Alas....You Lost(Better Luck Next Time)" << endl;
			}
			
		}
			
	
}

void GoldenTable(int& bal, int p_num)
{
	int betting_Amount = 0;
	int betting_number = 0;
	int rolling = rollingAmount();


		if (p_num == 1)
		{
			cout << "Betting Number (0 - 10): ";
			cin >> betting_number;


			cout << "Betting Amount : ";
			cin >> betting_Amount;
			int remaining_amount = bal - betting_Amount;

			int rolling1 = rollingAmountfor1();
			int rolling2 = rollingAmountfor2();

			cout << "Player 2 bet's on :" << rolling1;
			cout << endl;
			cout << "Player 3 bet's on :" << rolling2;
			cout << endl;
			cout << "Number on the Rolling: " << rolling << endl;

			if (betting_number == rolling)
			{
				cout << "Player" << p_num << " Wins... " << endl;

				cout << "Congratulations... You have won... " << endl;
				int amount_won = 0;
				amount_won = betting_Amount * 2;
				bal = remaining_amount + amount_won;
			}
			else
			{
				bal = remaining_amount;
				cout << "Alas....You Lost(Better Luck Next Time)" << endl;
			}

		}

		else if (p_num == 2)
		{
			int rolling1 = rollingAmountfor1();
			int rolling2 = rollingAmountfor2();
			cout << "Player 1 bet's on :" << rolling1;
			cout << endl;

			cout << "Betting Number (0 - 10): ";
			cin >> betting_number;

			cout << "Betting Amount : ";
			cin >> betting_Amount;
			int remaining_amount = bal - betting_Amount;

			cout << "Player 3 bet's on :" << rolling2;
			cout << endl;

			cout << "Number on the Rolling: " << rolling << endl;

			if (betting_number == rolling)
			{
				cout << "Player" << p_num << " Wins... " << endl;

				cout << "Congratulations... You have won... " << endl;
				int amount_won = 0;
				amount_won = betting_Amount * 2;
				bal = remaining_amount + amount_won;
			}
			else
			{
				bal = remaining_amount;
				cout << "Alas....You Lost(Better Luck Next Time)" << endl;
			}

		}
		else if (p_num == 3)
		{
			int rolling1 = rollingAmountfor1();
			int rolling2 = rollingAmountfor2();
			cout << "Player 1 bet's on :" << rolling1;
			cout << endl;
			cout << "Player 2 bet's on :" << rolling2;
			cout << endl;

			cout << "Betting Number (0 - 10): ";
			cin >> betting_number;


			cout << "Betting Amount : ";
			cin >> betting_Amount;
			int remaining_amount = bal - betting_Amount;


			cout << "Number on the Rolling: " << rolling << endl;

			if (betting_number == rolling)
			{
				cout << "Player" << p_num << " Wins... " << endl;

				cout << "Congratulations... You have won... " << endl;
				int amount_won = 0;
				amount_won = betting_Amount * 2;
				bal = remaining_amount + amount_won;
			}
			else
			{
				bal = remaining_amount;
				cout << "Alas....You Lost(Better Luck Next Time)" << endl;
			}

		}
			
	
	
}

void choice(int& bal, int p_num)
{
	cout << "do you want to play again ON ordinary table?(Y/N):";
	char ans;
	cin >> ans;
	if (ans == 'Y' || ans == 'y')
	{
		OrdinaryTable(bal, p_num);
	}
	else if (ans == 'N' || ans == 'n')
	{
		cout << "Thanks for choosing us....." << endl;
	}
	else
	{
		cout << "Unrecognized variable  entered";
	}
}
	

float GST(int bal) 
{
 //GST RATIO IS 5% and 5/100=0.05 soo,

	float final_balance = bal * 0.05;
	return final_balance;

}
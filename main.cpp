#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

class Player;

class Player{
    public:
        Player(std::string fname, std::string lname, int balance);
        ~Player();

        void withdraw(int amount);
        void deposit(int amount);

        int bet();

        void set_fname(std::string fname);
        void set_lname(std::string lname);

        std::string get_fname();
        std::string get_lname();
        int get_balance();

        void update_balance(int amount);

    private:
        std::string fname;
        std::string lname;
        int balance;
};

//A constructor for the player class
Player::Player(std::string fname, std::string lname, int balance){
    this->fname = fname;
    this->lname = lname;
    this->balance = balance;
}

Player::~Player(){

}

//Withdraws money from the players account
void Player::withdraw(int amount){
    if (amount <= this->balance){
        this->balance -= amount;
        std::cout << "$" << amount << " has been withdrawn. You now have $" << this->balance << " in your account." << std::endl;
    }
    else{
        std::cout << "You are requesting to withdraw more money than you have." << std::endl;
    }
}

//Deposits money into the player's account
void Player::deposit(int amount){
    if (amount <= 0){
        std::cout << "\nYou can't deposit this amount of money." << std::endl;
    }
    else{
        this->balance += amount;
        std::cout << "\n$" << amount << " has been deposited. You now have $" << this->balance << " in your account." << std::endl;
    }
}

//Sets the player's first name
void Player::set_fname(std::string fname){
    this->fname = fname;
}

//Sets the player's last name
void Player::set_lname(std::string lname){
    this->lname = lname;
}

//Returns the player's first name
std::string Player::get_fname(){
    return this->fname;
}

//Returns the player's last name
std::string Player::get_lname(){
    return this->lname;
}

//Returns the player's balance value
int Player::get_balance(){
    return this->balance;
}

//Updates the player's balance
void Player::update_balance(int amount){
    this->balance += amount;
}

//A class which takes in a player's bet
int Player::bet(){

    std::cout << "Input the amount of money you will bet with: ";

    int bet;
    std::cin >> bet;

    while(!std::cin || (bet < 0 || bet > this->balance)){
        if(bet > this->balance){
            std::cout << "You are betting more money than you have!" << std::endl;
        }

        else{
            std::cout << "Please enter a valid value!" << std::endl;
        }
        
        std::cin.clear();

        std::cin.ignore();

        std::cout << "Enter: ";

        std::cin >> bet;
    }

    return bet;
}

//Calculates a sum from an array
int get_sum(int array[], uint32_t size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        if(array[i] == 0){
            break;
        }
        else{
            sum += array[i];
        }

    }

    return sum;
}

//Prints numbers from an array
void print_nums(int array[], uint32_t size){
    for (int i = 0; i < size; i++){
        if(array[i] == 0){
            break;
        }
        else{
            std::cout << array[i] << " ";
        }

    }
}

//Displays the title screen to the user
std::string titleScreen(){
    std::cout << " _____________________________________________ \n"
              << "|          WELCOME TO JINHA'S CASINO          |\n"
              << "|                                             |\n"
              << "|   'P' to Play                'S' to Sign Up |\n"
              << "|                                             |\n"
              << "|   'A' to Add Credits        'W' to Withdraw |\n"
              << "|                                             |\n"
              << "|   'C' to Check Balance      'E' to Exit     |\n"
              << "|                                             |\n"
              << "|_____________________________________________|" << std::endl;
    
    std::cout << "\nEnter Your Selection: ";

    std::string selection;
    std::cin >> selection;

    std::cout << "" << std::endl;

    if (selection == "P" || selection == "S" || selection == "A" || selection == "W" || selection == "C" || selection == "E" )
    {
        return selection;
    }
    else
    {
        return "F";
    }
}

//Displays the Play Screen to the user
int playScreen(Player &player){

    int selection;

    std::cout << "Hi, " + player.get_fname() + " " + player.get_lname() + "!" << std::endl;
    std::cout << "\nWhat game would you like to play today?" << std::endl;

    std::cout << "\n(1) Higher or Lower" << std::endl;
    std::cout << "\n(2) Guess the number" << std::endl;
    std::cout << "\n(3) Black Jack" << std::endl;
    std::cout << "\n(4) Roulette" << std::endl;

    std::cout << "\nEnter: ";

    std::cin >> selection;

    while(!std::cin){

        std::cout << "\nPlease enter a valid value!" << std::endl;
        
        std::cin.clear();

        std::cin.ignore();

        std::cout << "Enter: ";

        std::cin >> selection;
    }
    std::cout << "\n";

    return selection;
}

//Displays the withdraw screen to the user
void withdrawScreen(Player &player){
    std::cout << " _____________________________________________\n" 
              << "|  Please Enter the Desired Amount of Credits |\n"
              << "|_____________________________________________|" << std::endl;

    std::cout << "Enter: ";

    int credits;

    std::cin >> credits;

    while(!std::cin){
        std::cout << "" << std::endl;

        std::cout << "Please enter a valid value!" << std::endl;
        
        std::cin.clear();

        std::cin.ignore();

        std::cout << "Enter: ";

        std::cin >> credits;
    }
    std::cout << "\n";

    player.withdraw(credits);
}

//Displays the fund adding screen to the user
void addFundsScreen(Player &player){
    std::cout << " _____________________________________________\n" 
              << "|  Please Enter the Desired Amount of Credits |\n" 
              << "|_____________________________________________|" << std::endl;

    std::cout << "" << std::endl;

    std::cout << "Enter: ";

    int credits;

    std::cin >> credits;

    while(!std::cin){
        std::cout << "" << std::endl;

        std::cout << "Please enter a valid value!" << std::endl;

        std::cin.clear();

        std::cin.ignore();

        std::cout << "Enter: ";

        std::cin >> credits;
    }

    player.deposit(credits);
}

//Displays the sign-up screen to the user
void signupScreen(Player &player){
    std::string fname;

    std::string lname;

    std::cout << " _____________________________________________ \n" 
              << "|   Please Fill in the Following Information  |\n" 
              << "|_____________________________________________|" << std::endl;

    std::cout << "First name: ";

    std::cin >> fname;

    std::cout << "\nLast name: ";

    std::cin >> lname;

    player.set_fname(fname);

    player.set_lname(lname);

    std::cout << "\n";
}

//Displays the game selection screen to the user
std::string gameScreen(std::string title){
    std::cout << "Welcome to " + title + "!" << std::endl;
    std::cout << "(P) Play         (I) Info" << std::endl;

    std::cout << "\nEnter: ";

    std::string choice;

    std::cin >> choice;

    while(choice != "P" && choice != "I"){
        std::cout << "" << std::endl;

        std::cout << "Please enter a valid value!" << std::endl;
        
        std::cin.clear();

        std::cin.ignore();

        std::cout << "Enter: ";

        std::cin >> choice;
    }
    std::cout << "\n";

    return choice;

}

//Simulates the higher/lower game
void playHigherLower(Player &player){
    std::string choice = gameScreen("Higher or Lower");

    if (choice == "I"){
        std::cout << "Two numbers will be randomly generated from 1-100.\n";
        std::cout << "The first number will be shown to you.\n Guess if the second number is greater, equal to, or less than the first number." << std::endl;
        std::cout << "Guess right and you win two times the number of credits you bet with." << std::endl;
        std::cout << "Guess wrong and you earn no credits." << std::endl;

    }else if(choice == "P"){
        int bet = player.bet();

        int first_num = rand() % 100;

        int second_num = rand() % 100;

        std::cout << "\nThe first number is: " << first_num << std::endl;

        std::cout << "\nIs the second number higher (h), lower (l), or equal (e) to the first number: ";
        std::string input;

        std::cin >> input;

        while(input != "h" && input != "l" && input != "e"){

            std::cout << "\nPlease enter a valid value!" << std::endl;
            
            std::cin.clear();

            std::cin.ignore();

            std::cout << "Enter: ";

            std::cin >> input;
        }
        std::cout << "\n";

        

        if((first_num < second_num) && input == "h"){
            std::cout << "You are correct! The second number was " << second_num << std::endl;

            player.update_balance(bet);

            std::cout << "\n" << bet*2 << " has been added to your account.\n";

        }else if((first_num > second_num) && input == "l"){
            std::cout << "You are correct! The second number was " << second_num << std::endl;

            player.update_balance(bet);
            std::cout << "\n" << bet*2 << " has been added to your account.\n";

        }else if((first_num == second_num) && input == "e"){
            std::cout << "You are correct! The second number was " << second_num << std::endl;

            player.update_balance(bet);

            std::cout << "\n" << bet*2 << " has been added to your account.\n";
        }else{
            std::cout << "Incorrect. The second number was " << second_num << std::endl;

            player.update_balance(0 - bet);

            std::cout << "\n" << bet << " has been subtracted from your account.\n";
        }
    std::cout << "\nYou now have $" << player.get_balance() << " in your account.\n";
    }

    return;
}

//Simulates a number-guessing game
void playGuessNum(Player &player){
    std::string choice = gameScreen("Higher or Lower");

    if (choice == "I"){
        std::cout << "One number will be randomly generated from 1-10.\n";
        std::cout << "If you guess the right number, \nyou will receive 10 times the amount of credits you bet with.\n";
        std::cout << "If you guess wrong, you don't get anything back.\n" << std::endl;

    }
    else if(choice == "P"){
        int bet = player.bet();

        int rand_num = 1 + rand() % 10;

        std::cout << "\nEnter your guess (1-10): ";
        int input;

        std::cin >> input;

        while(!std::cin){

            std::cout << "\nPlease enter a valid value!" << std::endl;
            
            std::cin.clear();

            std::cin.ignore();

            std::cout << "Enter: ";

            std::cin >> input;
        }
        std::cout << "\n";

        if(input == rand_num){
            std::cout << "You were correct! The number is " << rand_num << "! \n" << std::endl;

            player.update_balance(bet);

            std::cout << bet * 2 << " has been added to your account. \n" << std::endl; 
        }
        else{
            std::cout << "You were wrong! The number is " << rand_num << "! \n" << std::endl;

            player.update_balance(0 - bet);

            std::cout << "\n" << bet << " has been subtracted from your account.\n";
        }

    std::cout << "\nYou now have $" << player.get_balance() << " in your account.\n";
    }
}

//Receives the bet for a roulette game
int rouletteBetNum(){
    int bet_num;
    std::cin >> bet_num;

    while (!std::cin || (bet_num < 1 || bet_num > 36)){
        std::cout << "" << std::endl;

        std::cout << "Please enter a valid value!" << std::endl;
        
        std::cin.clear();

        std::cin.ignore();

        std::cout << "Enter: ";

        std::cin >> bet_num;
    }

    return bet_num;
}

//Simulates a Roulette wheel game
void playRoulette(Player & player){
    std::string choice = gameScreen("Roulette");

    if (choice == "I"){
        std::cout << "A random number will be drawn from 1 to 36.\n"; //Bet one -> paid 37
        std::cout << "Every even number is black and odd number is red.\n";
        std::cout << "A single number bet pays 35 to 1.\n";
        std::cout << "A double number bet pays 17 to 1.\n";
        std::cout << "A triple number bet pays 11 to 1.\n";
        std::cout << "You can bet red or black which pays 1 to 1.\n";
        std::cout << "You can bet odd or even which pays 1 to 1.\n";
        std::cout << "You can bet the first 18 numbers or the last 18 numbers which pays 1 to 1.\n";
    }

    else if(choice == "P"){
        int bet = player.bet();

        int rand_num = 1 + rand() % 36;

        std::cout << "Which type of bet will you make...\n";
        std::cout << "\n(1) Single Number Bet (35:1 payout)";
        std::cout << "\n(2) Double number bet (17:1 payout)";
        std::cout << "\n(3) Triple number bet (11:1 payout)";
        std::cout << "\n(4) Red or Black (1:1 payout)";
        std::cout << "\n(5) Odd or Even (1:1 payout)";
        std::cout << "\n(6) First 18 or Last 18 (1:1 payout)\n";

        int choice;

        std::cout << "\nEnter: ";
        std::cin >> choice;

        while (!std::cin || (choice < 1 || choice > 6)){
            std::cout << "" << std::endl;

            std::cout << "Please enter a valid value!" << std::endl;
            
            std::cin.clear();

            std::cin.ignore();

            std::cout << "Enter: ";

            std::cin >> choice;
        }
        std::cout << "\n";

        if (choice == 1){
            std::cout << "Choose your single number bet from 1 to 36: ";

            int bet_num = rouletteBetNum();
            
            if(rand_num == bet_num){
                std::cout << "You are correct!" << " The number is " << rand_num << "\n";

                player.update_balance(35*bet);

                std::cout << "$"<< 35*bet + bet << " has been added to your account.\n" << std::endl;
            }

            else{
                std::cout << "You are incorrect!" << " The number is " << rand_num << "\n";

                player.update_balance(0-bet);

                std::cout << "$"<< bet << " has been taken away from account.\n" << std::endl;
            }
        }
        else if(choice == 2){
            int bet_num_arr[2];

            std::cout << "Choose your first number from 1 to 36: ";

            bet_num_arr[0] = rouletteBetNum();

            std::cout << "Choose your second number from 1 to 36: ";

            bet_num_arr[1] = rouletteBetNum();

            if(bet_num_arr[0] == rand_num || bet_num_arr[1] == rand_num){
                std::cout << "You are correct!" << " The number is " << rand_num << "\n";

                player.update_balance(17*bet);

                std::cout << "$"<< 17*bet + bet << " has been added to your account.\n" << std::endl;
            }
            else{
                std::cout << "You are incorrect!" << " The number is " << rand_num << "\n";

                player.update_balance(0-bet);

                std::cout << "$"<< bet << " has been taken away from account.\n" << std::endl;
            }
        }
        else if (choice == 3){
            int bet_num_arr[3];

            std::cout << "Choose your first number from 1 to 36: ";

            bet_num_arr[0] = rouletteBetNum();

            std::cout << "Choose your second number from 1 to 36: ";

            bet_num_arr[1] = rouletteBetNum();

            std::cout << "Choose your third number from 1 to 36: ";

            bet_num_arr[2] = rouletteBetNum();

            if(bet_num_arr[0] == rand_num || bet_num_arr[1] == rand_num || bet_num_arr[2] == rand_num){
                std::cout << "You are correct!" << " The number is " << rand_num << "\n";

                player.update_balance(11*bet);

                std::cout << "$"<< 11*bet + bet << " has been added to your account.\n" << std::endl;
            }
            else{
                std::cout << "You are incorrect!" << " The number is " << rand_num << "\n";

                player.update_balance(0-bet);

                std::cout << "$"<< bet << " has been taken away from account.\n" << std::endl;
            }
        }
        else if(choice == 4){
            std::cout << "Will the color be Red or Black: ";

            std::string color;
            std::string true_color;

            std::cin >> color;

            while(!std::cin || (color != "Red" && color != "Black")){
                std::cout << "\n\nPlease enter a valid value!" << std::endl;

                std::cin.clear();

                std::cin.ignore();
                
                std::cout << "Enter: ";
                
                std::cin >> color;
            }
            std::cout << "\n";

            if(rand_num % 2 == 0){
                true_color = "Black";
            }
            else{
                true_color = "Red";
            }

            if(true_color == color){
                std::cout << "You are correct!" << " The number is " << rand_num << " and the color is " << true_color << "\n";

                player.update_balance(2*bet);

                std::cout << "$"<< 2*bet + bet << " has been added to your account.\n" << std::endl;
            }

            else{
                std::cout << "You are incorrect!" << " The number is " << rand_num << " and the color is " << true_color << "\n";

                player.update_balance(0-bet);

                std::cout << "$"<< bet << " has been taken away from account.\n" << std::endl;
            }
        }
        else if(choice == 5){
            std::cout << "Will the number be Odd or Even: ";

            std::string type;
            std::string true_type;

            std::cin >> type;

            while(!std::cin || (type != "Odd" && type != "Even")){
                std::cout << "\n\nPlease enter a valid value!" << std::endl;

                std::cin.clear();

                std::cin.ignore();
                
                std::cout << "Enter: ";
                
                std::cin >> type;
            }
            std::cout << "\n";

            if(rand_num % 2 == 0){
                true_type = "Even";
            }
            else{
                true_type = "Odd";
            }

            if(true_type == type){
                std::cout << "You are correct!" << " The number is " << rand_num << " and the type is " << true_type << "\n";

                player.update_balance(2*bet);

                std::cout << "$"<< 2*bet + bet << " has been added to your account.\n" << std::endl;
            }

            else{
                std::cout << "You are incorrect!" << " The number is " << rand_num << " and the type is " << true_type << "\n";

                player.update_balance(0-bet);

                std::cout << "$"<< bet << " has been taken away from account.\n" << std::endl;
            }
        }
        else if(choice == 6){
            std::cout << "Will the number be in the first (f) or second (s) half: ";

            std::string type;
            std::string true_type;

            std::cin >> type;

            while(!std::cin || (type != "f" && type != "s")){
                std::cout << "\n\nPlease enter a valid value!" << std::endl;

                std::cin.clear();

                std::cin.ignore();
                
                std::cout << "Enter: ";
                
                std::cin >> type;
            }
            std::cout << "\n";

            if(rand_num <= 18){
                true_type = "f";
            }
            else{
                true_type = "s";
            }

            if(true_type == type){
                std::cout << "You are correct!" << " The number is " << rand_num << "\n";

                player.update_balance(2*bet);

                std::cout << "$"<< 2*bet + bet << " has been added to your account.\n" << std::endl;
            }

            else{
                std::cout << "You are incorrect!" << " The number is " << rand_num << "\n";

                player.update_balance(0-bet);

                std::cout << "$"<< bet << " has been taken away from account.\n" << std::endl;
            }
        }
    std::cout << "\nYou now have $" << player.get_balance() << " in your account.\n";
    }
}

//Simulates a Black Jack game
void playBlackJack(Player &player){
    std::string choice = gameScreen("Black Jack");

    if (choice == "I"){
        std::cout << "Two numbers between (1 & 11) will be randomly given to you and the dealer.\n";
        std::cout << "If the sum of both of your numbers is 21, you win.\n";
        std::cout << "If the sum of the dealer's numbers are 21, they win.\n";
        std::cout << "If the sum of the dealer's numbers are over 21, you win\n";
        std::cout << "If your numbers don't sum to 21, you have the \noption to ask for another number or hold.\n";
        std::cout << "If you ask for another number, you receive another random number.\n";
        std::cout << "If you choose to hold, the dealer will then add more numbers until their sum is \n greater than or equal to 21.\n";
        std::cout << "Losing gives you no credits, winning gets you three times the amount you bet." << std::endl;
    }
    else if(choice == "P"){
        int bet = player.bet();

        int d_nums[21] = {};
        
        d_nums[0] = 1 + rand() % 10;

        d_nums[1] = 1 + rand() % 10;

        int d_index = 2;

        int u_nums[21] = {};

        u_nums[0] = 1 + rand() % 10;

        u_nums[1] = 1 + rand() % 10;

        int user_index = 2;

        bool u_hold = false;

        std::cout << "The dealer's numbers are: ";

        print_nums(d_nums, 21);

        std::cout << "\nYour numbers are: ";

        print_nums(u_nums, 21);

        std::cout << "\n";

        while ((get_sum(d_nums, 21) < 21) && (get_sum(u_nums, 21) < 21)){
            if (u_hold == false){
                std::cout << "Would you like to hold (h) or get another number (n)?\n";
                std::cout << "Enter: ";

                std::string input;

                std::cin >> input;

                while(input != "h" && input != "n"){

                    std::cout << "\nPlease enter a valid value!" << std::endl;
                    
                    std::cin.clear();

                    std::cin.ignore();

                    std::cout << "Enter: ";

                    std::cin >> input;
                }
                std::cout << "\n";

                if(input == "h"){
                    u_hold = true;
                    continue;
                }

                else{
                    u_nums[user_index] = 1 + rand() % 10;
                    user_index++;
                }

            }
            else{
                d_nums[d_index] = 1 + rand() % 10;
                d_index++;
            }

            std::cout << "\nThe dealer's numbers are: " << std::endl;

            print_nums(d_nums, 21);

            std::cout << "\nYour numbers are: ";

            print_nums(u_nums, 21);

            std::cout << "\n";

        }

        int u_sum = get_sum(u_nums, 21);

        int d_sum = get_sum(d_nums, 21);
        
        if(u_sum == 21 && d_sum == 21){
            std::cout << "Both the dealer and the user have a sum of 21.\n" << std::endl;

            player.update_balance(bet);

            std::cout << "Your original bet has been added back to your account. \n" << std::endl;
        }

        else if(u_sum == 21){
            std::cout << "Congrats you won!\n" << std::endl;
            player.update_balance(bet*2);

            std::cout << bet * 3 << " has been added to your account. \n" << std::endl; 
        }

        else if(u_sum > 21){
            std::cout <<  "You lost! \n" << std::endl;

            player.update_balance(0 - bet);

            std::cout << bet << " has been subtracted from your account.\n" << std::endl;
        }

        else if(d_sum == 21){
            std::cout <<  "You lost! The dealer got a sum of 21! \n" << std::endl;

            player.update_balance(0 - bet);

            std::cout << bet << " has been subtracted from your account.\n" << std::endl;
        }

        else if(d_sum > 21){
            std::cout << "Congrats you won! The dealer got a sum of over 21!\n" << std::endl;
            player.update_balance(bet*2);

            std::cout << bet * 3 << " has been added to your account. \n" << std::endl; 
        }



    std::cout << "\nYou now have $" << player.get_balance() << " in your account.\n";
    }

}

//Selects and runs a game depending on the user's choice
void gameSelection(int gameType, Player &player){
    if (gameType == 1){
        playHigherLower(player);
    }
    else if(gameType == 2){
        playGuessNum(player);
    }
    else if(gameType == 3){
        playBlackJack(player);
    }
    else if(gameType == 4){
        playRoulette(player);
    }
    else{
        std::cout << "That input is not valid.\n" << std::endl;
    }
}

//Displays the check balance screen
void check_balance(Player &player){
    std::cout << "\n" << player.get_fname() << " " << player.get_lname() << std::endl;

    std::cout << "\nYour balance is currently: $" << player.get_balance() << std::endl;
}

int main(){

    Player player("", "", 0);
    srand ( time(NULL) );

    while (true)
    {
        std::string choice = titleScreen();

        if(choice == "P")
        {
            if (player.get_fname().empty() && player.get_lname().empty()){

                std::cout << "Please sign up and add credits before playing." << std::endl;

            }

            else if(player.get_balance() == 0){
                std::cout << "Please add credits to your account before playing." << std::endl;
            }
            else{
                int gameType = playScreen(player);
                gameSelection(gameType, player);
            }
        }
        
        else if (choice == "S") 
        {
            if (player.get_fname().empty() && player.get_lname().empty() && player.get_balance() == 0){

                signupScreen(player);

            }
            else{
                std::cout << "You have already signed up." << std::endl;
            }
        }

        else if (choice == "A"){
            if (player.get_fname().empty() && player.get_lname().empty() && player.get_balance() == 0){

                std::cout << "Please sign up before adding credits." << std::endl;

            }

            else{
                addFundsScreen(player);
            }
        }

        else if (choice == "W"){
            if (player.get_fname().empty() && player.get_lname().empty() && player.get_balance() == 0){

                std::cout << "Please sign up before withdrawing." << std::endl;

            }

            else{
                withdrawScreen(player);
            }
        }
        else if (choice == "C"){
            check_balance(player);
        }
        else if (choice == "E")
        {
            std::cout << "Thank you for playing!\n\n";
            break;
        }
        else
        {
            std::cout << "Please enter a valid selection." << std::endl;
            continue;
        }
    }
    return 0;
}
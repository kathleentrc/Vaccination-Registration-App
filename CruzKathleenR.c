/*********************************************************************************************************	
This is	to certify that	this project is	my own work, based on my personal efforts in studying and applying 
the concepts learned. I have constructed the functions and their respective algorithms and corresponding
code by	myself. The	program	was	run, tested, and debugged by my	own	efforts. I further certify that	I have 
not copied in part or whole or otherwise plagiarized the work of other students and/or persons.	
                                                            Kathleen Therese R. Cruz,	DLSU ID # 12206067
*********************************************************************************************************/

#include <stdio.h>      // Standard Input Output
#include <stdlib.h>     // Standard Library
#include <string.h>     // String Library
#include <conio.h>      // Console Input Output
#define USERS 100       // Max user record
#define MAX 50          // Max questions and answers from chatbot
#define ADMIN1_ID 1989  // Admin 1 ID

/* typedef for string literals */
typedef char String6[7];
typedef char String10[11];
typedef char String11[12];
typedef char String20[21];
typedef char String30[31];
typedef char String80[81];

/* Structure for vaccine dose information */
struct doseTag{
    String11 dose;
    String10 vaccine;
    String10 location;
};

/* Structure for appointment information */
struct appointmentTag{
    int ID;
    String20 name;
    String10 location;
    String10 vaccine;
    String11 date;
    String6 time;
    String10 dose;
    int canceled;
};

/* Structure for user information */
struct userTag{
    int ID;
    String10 password;
    String20 name;
    String30 address;
    long long int contact;
    String10 sex;
    struct doseTag first;
    struct doseTag second;
    struct doseTag booster;
    int deleted;
    struct appointmentTag appointment;
} user[USERS];

/* Structure for admin information */
struct adminTag{
    int ID;
    String10 password;
} admin_Kath;


/*  PrintHorizontalBorder is a function that prints a border design using ASCII symbols
    @param num - number of times to print the ASCII symbol '═'
    @return nothing since it is a void function
*/
void
PrintHorizontalBorder(int num)
{
    int i;
    
    printf(" ");

    for(i = 0; i < num; i++)
        printf("%c", 205);          // 205 is the numerical equivalent of the ASCII symbol '═'
    
    printf(" ");
}

/*  DisplayLaunch is a function that prints the program name along with its border design using ASCII symbols
    @return nothing since it is a void function
*/
void
DisplayLaunch()
{
    int i;

    printf("\n\n    %c", 201);      // TOP CORNER BORDER 
    for(i = 0; i < 43; i++)         // TOP HORIZONTAL BORDER 
        printf("%c", 205);
    printf("%c\n    ", 187);        // TOP VERTICAL BORDER
    
    printf("%c VACCINATION REGISTRATION WITH CHATBOT APP %c\n", 186, 186);

    printf("    %c", 200);          // BOTTOM CORNER BORDER 
    for(i = 0; i < 43; i++)         // BOTTOM HORIZONTAL BORDER 
        printf("%c", 205);
    printf("%c\n   ", 188);         // BOTTOM VERTICAL BORDER 

    printf("\t   %c Program by: Kathleen Cruz %c\n\n\n", 4, 4);
}

/*  DisplayMenu is a function that prints the main menu options
    @return nothing since it is a void function
*/
void 
DisplayMenu()
{
    PrintHorizontalBorder(18);
    printf(" MENU OPTIONS ");
    PrintHorizontalBorder(18);
    printf("\n");
    printf("  [1] Vaccination Registration Menu\n");
    printf("  [2] Data Management Menu\n");
    printf("  [3] Exit Program\n");
    PrintHorizontalBorder(52);
    printf("\n");
}

/*  DisplayMenu is a function that prints the vaccination registration menu options
    @return nothing since it is a void function
*/
void
DisplayVaxxRegistration()
{
    PrintHorizontalBorder(10);
    printf(" VACCINATION REGISTRATION MENU");
    PrintHorizontalBorder(10);
    printf("\n");
    printf("  [1] User Registration\n");
    printf("  [2] Vaccination Appointment\n");
    printf("  [3] ChatBot (FAQs)\n");
    printf("  [4] Exit\n");
    PrintHorizontalBorder(52);
    printf("\n");
}

/*  DisplayDataManagement is a function that prints the data management menu options
    @return nothing since it is a void function
*/
void
DisplayDataManagement()
{
    PrintHorizontalBorder(14);
    printf(" DATA MANAGEMENT MENU ");
    PrintHorizontalBorder(14);
    printf("\n");
    printf("  [1] User                      [4] Export\n");
    printf("  [2] Appointment               [5] Import\n");
    printf("  [3] ChatBot                   [6] Exit\n");
    PrintHorizontalBorder(52);
    printf("\n");
}

/*  DisplayEditUserDetails is a function that prints the edit user menu options
    @return nothing since it is a void function
*/
void
DisplayEditUserDetails()
{
    printf("\n");
    PrintHorizontalBorder(20);
    printf(" EDIT USER DETAILS ");
    PrintHorizontalBorder(20);
    printf("\n");
    printf("  [1] User ID                   [8] First Dose Location\n");
    printf("  [2] Name                      [9] Second Dose\n");
    printf("  [3] Address                   [10] Second Dose Vaccine\n");
    printf("  [4] Contact                   [11] Second Dose Location\n");
    printf("  [5] Sex                       [12] Booster Dose\n");
    printf("  [6] First Dose                [13] Booster Dose Vaccine\n");
    printf("  [7] First Dose Vaccine        [14] Booster Dose Location\n");
    PrintHorizontalBorder(61);
    printf("\n");
}

/*  DisplayEditAppointment is a function that prints the edit appointment menu options
    @return nothing since it is a void function
*/
void
DisplayEditAppointment()
{
    printf("\n");
    PrintHorizontalBorder(9);
    printf(" EDIT APPOINTMENT ");
    PrintHorizontalBorder(9);
    printf("\n");
    printf("  [1] Application ID\n");
    printf("  [2] Name\n");
    printf("  [3] Location\n");
    printf("  [4] Vaccine\n");
    printf("  [5] Date and Time\n");
    PrintHorizontalBorder(40);
    printf("\n");
}

/*  DisplayManageAppointment is a function that prints the manage appointment menu options
    @return nothing since it is a void function
*/
void
DisplayManageAppointment()
{
    printf("\n");
    PrintHorizontalBorder(6);
    printf(" MANAGE APPOINTMENT MENU ");
    PrintHorizontalBorder(6);
    printf("\n");
    printf("  [1] Cancel Appointment\n");
    printf("  [2] Edit Appointment Details\n");
    PrintHorizontalBorder(41);
    printf("\n");
}

/*  DisplayUser is a function that prints the user menu options
    @return nothing since it is a void function
*/
void
DisplayUser()
{
    printf("\n");
    PrintHorizontalBorder(20);
    printf(" USER MENU ");
    PrintHorizontalBorder(19);
    printf("\n");
    printf("  [1] Add New User\n");
    printf("  [2] View All Users\n");
    printf("  [3] Edit User Details\n");
    printf("  [4] Delete User\n");
    printf("  [5] Exit\n");
    PrintHorizontalBorder(52);
    printf("\n");
}

/*  DisplayAppointment is a function that prints the appointment menu options
    @return nothing since it is a void function
*/
void
DisplayAppointment()
{
    printf("\n");
    PrintHorizontalBorder(6);
    printf(" APPOINTMENT MENU ");
    PrintHorizontalBorder(7);
    printf("\n");
    printf("  [1] Add New Appointment\n");
    printf("  [2] View All Appointments\n");
    printf("  [3] Edit Appointment\n");
    printf("  [4] Delete Appointment\n");
    printf("  [5] Exit\n");
    PrintHorizontalBorder(33);
    printf("\n");
}

/*  DisplayAppMenu is a function that prints the vaccination appointment menu options
    @return nothing since it is a void function
*/
void
DisplayAppMenu()
{
    printf("\n");
    PrintHorizontalBorder(6);
    printf(" VACCINATION APPOINTMENT MENU ");
    PrintHorizontalBorder(6);
    printf("\n");
    printf("  [1] Appointment Request\n");
    printf("  [2] Manage Appointment\n");
    printf("  [3] Exit Menu\n");
    PrintHorizontalBorder(44);
    printf("\n");
}

/*  DisplayChatbotMenu is a function that prints the chatbot menu options
    @return nothing since it is a void function
*/
void
DisplayChatbotMenu()
{
    printf("\n");
    PrintHorizontalBorder(12);
    printf(" CHATBOT MENU ");
    PrintHorizontalBorder(12);
    printf("\n");
    printf("   [1] Add New Question and Answer\n");
    printf("   [2] View All Questions and Answers\n");
    printf("   [3] Edit Questions and Answers\n");
    printf("   [4] Delete Questions and Answers\n");
    printf("   [5] Exit\n");
    PrintHorizontalBorder(38);
    printf("\n");
}

/*  GetInput is a function that gets input from user/admin
    @return input from scanf() function
    Pre-condition: The user/admin should only input integers
*/
int
GetInput()
{
    int input;

    printf("  %c Choose your option: ", 175);
    scanf("%d", &input);

    printf("\n\n");

    return input;
}

/*  DisplayRequest is a function that takes in two string literals and asks the admin if they wish to request another task
    @param task - a string that describes a specific task (e.g. add, edit, delete)
    @param task - a string that describes a specific option (e.g. user, appointment)
    @return input from scanf() function
    Pre-condition: The user/admin should only input integers
*/
int
DisplayRequest(String10 task, String20 option)
{
    int input;

    printf(" Do you wish to %s another %s?\n", task, option);
    printf(" [1] Yes\n");
    printf(" [2] No\n");

    printf(" %c Input: ", 175);
    scanf("%d", &input);
    
    return input;
}

/*  DisplayImport is a function that prints out a text with border designs around it
    @return nothing since it is a void function
*/
void
DisplayImport()
{
    printf("\n");
    PrintHorizontalBorder(11);
    printf(" IMPORT FILE ");
    PrintHorizontalBorder(11);
    printf("\n");
}

/*  DisplayExport is a function that prints out a text with border designs around it
    @return nothing since it is a void function
*/
void
DisplayExport()
{
    printf("\n");
    PrintHorizontalBorder(11);
    printf(" EXPORT FILE ");
    PrintHorizontalBorder(11);
    printf("\n");
}

/*  DisplayError is a function that prints out an error message
    @param input - the variable that stores the input from the admin
    @return input from scanf() function
*/
int
DisplayError(int input)
{
    printf(" ERROR: File does not exist!\n");
    printf(" [1] Try again\n");
    printf(" [0] Exit\n %c Input:", 175);
    scanf("%d", &input);

    return input;
}

/*  RemoveTrailingNewLine is a function that prevents a trailing new line from getting string input
    @return nothing since it is a void function
    Pre-condition: The function should be placed before or after getting a string to avoid a trailing new line
*/
void
RemoveTrailingNewLine()
{
    String30 temp;
    fgets(temp, sizeof(String30), stdin);
}

/*  isValidID is a function that checks if a user ID is within the range and does not match with the admin ID
    @param ID - ID input from user
    @return 0 if invalid; 1 if valid
    Pre-condition: ID input should be a positive integer
*/
int
isValidID(int ID)
{
    int isValid = 0;

    if(1 <= ID && ID <= 9999999999)             // max of 10 digits, excluding 0
        if(ID != ADMIN1_ID)                     // ADMIN1_ID is 1989
            isValid = 1;

    return isValid;
}

/*  isUniqueUserID is a linear search function to check if an ID is unique
    @param key - the ID to be searched
    @return 1 if unique; 0 if not unique
    Pre-condition: The function will only search up to 100 users
*/
int
isUniqueUserID(int key)
{
    int isUnique = 1;
    int i = 0;

    do{
        if(user[i].ID == key)
           isUnique = 0;
        else
            i++;                     
    }while(isUnique && i < USERS);   // USERS is the maximum number of users (100)

    return isUnique;
}

/*  isUniqueAppID is a linear search function to check if an app ID is unique
    @param key - the app ID to be searched
    @return 1 if unique; 0 if not unique
    Pre-condition: The function will only search up to 100 users
*/
int
isUniqueAppID(int key)
{
    int isUnique = 1;
    int i = 0;

    do{
        if(user[i].appointment.ID == key)
           isUnique = 0;
        else
            i++;
    }while(isUnique && i < USERS);    

    return isUnique;
}

/*  InputID is a function that prompts for user ID input
    @param *ID - a pointer that stores the address of a user ID
    @return nothing since it is a void function
    Pre-condition: The ID input should be unique
*/
void 
InputID(int * ID)
{
    int tempID; 

    do{
        printf(" User ID:   ");
        scanf("%d", &tempID);   // temporarily store ID in tempID

        if(!isValidID(tempID) || !isUniqueUserID(tempID))            // check if ID is valid and if it is unique
            printf("%c Error: ID has been taken! Try Again.\n", 16); // 16 = ASCII SYMBOL: ►

    }while(!isValidID(tempID) || !isUniqueUserID(tempID));           // continue asking for input until ID is valid and unique     

    *ID = tempID;               // once it is valid and unique, store tempID to *ID
}

/*  InputAppID is a function that prompts for app ID input
    @param *ID - a pointer that stores the address of an app ID
    @return nothing since it is a void function
    Pre-condition: The app ID input should be unique
*/
void
InputAppID(int * ID)
{
    int tempID;

    do{
        printf(" App ID:    ");
        scanf("%d", &tempID);   // temporarily store app ID in tempID

        if(!isValidID(tempID) || !isUniqueAppID(tempID))             // check if app ID is valid and if it is unique
            printf("%c Error: ID has been taken! Try Again.\n", 16); // 16 = ASCII SYMBOL: ►

    }while(!isValidID(tempID) || !isUniqueAppID(tempID));           // continue asking for input until ID is valid and unique     

    *ID = tempID;               // once it is valid and unique, store tempID to *ID
}

/*  InputPassword is a function that prompts for password input
    @param password - stores the password input
    @return nothing since it is a void function
*/
void
InputPassword(String10 password)
{
    int i = 0;          
    int isValid = 1;    
    
    printf(" Password:  ");

    /* This loop masks the password using asterisks */
    do{
        password[i] = getch();      // getch() is used to mask the password

        if(password[i] == '\r')     // '\r' = carriage return (result of hitting the enter key)
            isValid = 0;
        else
        {
            printf("*");
            i++;
        }// end else
    }while(isValid);

    /* Check if password is too long */
    if(i > 10)
    {
        printf("\n%c Error: Password is too long! Try again.\n", 16); // 16 = ASCII SYMBOL: ►
        InputPassword(password);    
    }// end if

    /* Check if password is too weak */
    if(strcmp(password, "password\r") == 0 || strcmp(password, "Password\r") == 0 || strcmp(password, "PASSWORD\r") == 0)
    {
        printf("\n%c Error: Password is too weak! Try again.\n", 16); // 16 = ASCII SYMBOL: ►
        InputPassword(password);    
    }// end if
    else if(strcmp(password, "123456789\r") == 0 || strcmp(password, "1111111\r") == 0)
    {
        printf("\n%c Error: Password is too weak! Try again.\n", 16); // 16 = ASCII SYMBOL: ►
        InputPassword(password);  
    }// end else if
    else if(strcmp(password, "qwerty\r") == 0 || strcmp(password, "QWERTY\r") == 0 || strcmp(password, "Qwerty\r") == 0)
    {
        printf("\n%c Error: Password is too weak! Try again.\n", 16); // 16 = ASCII SYMBOL: ►
        InputPassword(password);
    }// end else if

    /* Store null byte at the end of password string */
    password[i] = '\0';
}

/*  InputName is a function that prompts for name input
    @param name - stores the name input
    @return nothing since it is a void function
    Pre-condition: The name should only consist of characters and it should not be an empty string
*/
void
InputName(String20 * name)
{
    printf(" Name:      ");     // scanf is used instead of fgets to avoid the '\n' at the end of string
    scanf("%20[^\n]", *name);   // "%20[^\n]" means scan until 20 characters and stop as soon at it encounters the first newline
}

/*  InputAddress is a function that prompts for address input
    @param address - stores the address input
    @return nothing since it is a void function
    Pre-condition: The address should only consist of characters and numbers and it should not be an empty string
*/
void
InputAddress(String30 * address)
{
    printf(" Address:   ");
    scanf("%30[^\n]", *address);    // "%30[^\n]" means scan until 30 characters and stop as soon at it encounters the first newline
}

/*  IsValidContact is a function that checks if the contact input is valid
    @param contact - takes in the contact input
    @return 1 if valid; -1 if invalid
    Pre-condition: The contact should start with 9 after the leading zero and it should be a positive integer
*/
int
IsValidContact(long long int contact)
{
    if(9000000000 <= contact && contact <= 9999999999)  // check if the contact starts with zero and has 10 digits (leading zero excluded)
        return 1;

    return -1;
}

/*  InputContact is a function that prompts for contact input
    @param *contact - is a pointer that stores the address of contact input
    @return nothing since it is a void function
    Pre-condition: The leading zero cannot be scanned, therefore getch() is used
*/
void
InputContact(long long int * contact)
{
    int isValid;

    do{
        printf(" Contact:   ");
        getch();                            // getch() is temporarily used to accept leading zero in contact number 
        printf("0");
        scanf("%I64d", &*contact);          // GNU supports %l64d as a format specifier for long long int

        isValid = IsValidContact(*contact); // check if contact input is valid

        if(isValid == -1)
            printf("%c Error: Invalid contact number. Please try again.\n", 16); // 16 = ASCII SYMBOL: ►

    }while(isValid == -1);                  // continue asking for input until it is a valid contact number
}

/*  isValidSex is a function that checks if sex input is valid or not
    @param input - takes in the sex input
    @return 0 if invalid; 1 if valid
    Pre-condition: Input should only consist of characters
*/
int
isValidSex(String10 input)
{
    int isValid = 0;

    if(strcmp(input, "Female") == 0 || strcmp(input, "Male") == 0)  // compare the input string
        isValid = 1;                                                // return 1 if it matches with either "Female" or "Male"
    
    return isValid;
}

/*  isValidSex is a function that prompts for sex input
    @param *sex - is a pointer that stores the address of sex input
    @return 0 if invalid; 1 if valid
    Pre-condition: Input should only consist of characters
*/
void
InputSex(String10 * sex)
{
    do{
        printf(" Sex:       ");
        scanf("%10s", *sex);    // only scan up to 10 characters max for input validation

        if(!isValidSex(*sex))   // check if sex is valid
            printf("%c Error: Invalid input. Please try again.\n", 16); // 16 = ASCII SYMBOL: ►

    }while(!isValidSex(*sex));  // continue asking for sex input until it is valid
}

/*  ExtractYear is a function that extracts a year from a string and returns its equivalent integer (numerical)
    @param date - a string that is a date with format: "YYYY-MM-DD"
    @return the integer year equivalent; -1 if it is an invalid year
    Pre-condition: The date should be a numeric string (e.g. "2022-02-22")
*/
int
ExtractYear(String11 date)
{
    // When did COVID vaccines become available in the Philippines?
    // Ans: 2021 (so only consider dates after this (inclusive))

    if(date[0] == '2' && date[1] == '0' && date[2] == '2')  // check if the first three characters are '2', '0', and '2' respectively
    {
        if(date[3] == '1')                                  // check last digit of string
            return 2021;                                    // return integer equivalent
        else if(date[3] == '2')
            return 2022;
        else if(date[3] == '3')
            return 2023;
    }// end if
        
    return -1; // if the year does not match with any of the conditions above, return -1
}

/*  ExtractDigit is a function that takes in a single digit from a character and returns its numerical equivalent
    @param char1 - character that is a number (e.g. '2', '9')
    @return the integer equivalent of the number
    Pre-condition: The character should be a number (e.g. '2', '9')
*/
int
ExtractDigit(char char1)
{
    int i;

    for(i = 48; i <= 57; i++)   // 48 is the ASCII equivalent of '0', 57 is the ASCII equivalent of '9'
        if(char1 == i)          // loop until '0' to '9', then check if the character is equal to the current ASCII equivalent
            return i-48;        // subtract 48 to its current index to get its integer equivalent
                                
    return -1;                  // return -1 if character parameter is invalid
}

/*  ConcatenateDigits is a function that concatenates two integer single digits
    @param char1 - integer that is a single number (e.g. 3, 1)
    @param char2 - integer that is a single number (e.g. 3, 1)
    @return the integer equivalent of the concatenated number
    Pre-condition: The parameters should be a single number (e.g. 3, 1)
*/
int
ConcatenateDigits(int digit1, int digit2)
{
    int i;                      // concantenating two digits (example): 
                                // digit1 = 3
                                // digit2 = 1 
                                // ... when concatenated, it becomes 31

    for(i = 0; i <= 9; i++)     // loop from 0 to 9
    {
        if(digit1 == i)         // if digit matches with the current index
            digit1 += (9*i);    // add digit1 to 9 multiplied by index, example: digit1 = 3+(9*3)
    }// end for                 // therefore, answer is 30 ... digit 1 is now equal to 30
                    
    return digit1 += digit2;    // add digit 1 to digit 2, example:
                                // 30 + 1 = 31
                                // therefore, when you concatenate 3 and 1, it becomes 31
                                // (this function will be used to extract the date and month from a string)
}

/*  IsValidDate is a function that checks for date input validation
    @param date - string that contains the date input to be checked
    @return 1 if date string is valid; -1 if invalid
    Pre-condition: The date should have a format of "YYYY-MM-DD"
*/
int
IsValidDate(String11 date)
{
    // 0 1 2 3 4 5 6 7 8 9    |    INDICES
    // Y Y Y Y - M M - D D    |    STRING

    int year = ExtractYear(date);
    int month = ConcatenateDigits(ExtractDigit(date[5]), ExtractDigit(date[6]));
    int day = ConcatenateDigits(ExtractDigit(date[8]), ExtractDigit(date[9]));

    if(year != -1)  // check if year is valid
    {
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {   // if the month input falls on a month with 31 days, check if the day input is in between 1-31 days
            if(1 <= day && day <= 31)
                return 1;
        }// end if
        else if(month == 2)
        {   // if the month input falls on february, check if the day input is in between 1-28 days
            if(1 <= day && day <= 28)
                return 1;
        }// end else if
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {   // if the month input falls on a month with 30 days, check if the day input is in between 1-30 days
            if(1 <= day && day <= 30)
                return 1;
        }// end else if
    }// end if
    else if(strcmp(date, "N/A") == 0)   // N/A is also valid because date input is optional
        return 1;
    
    return -1;                          // if the date does not match with any of the conditions above, return -1
}

/*  InputDose is a function that prompts for date input regarding user dose
    @param *dose - string that holds the address of vaccination dose
    @return nothing since it is a void function
    Pre-condition: The date should either be a string with numerical values and dashes or 'N/A' only
*/
void
InputDose(String11 * dose)
{
    int isValid; 

    do{
        printf(" Dose (YYYY-MM-DD):  ");    
        scanf("%11s", *dose);               // dose should have up to 11 characters only (null byte excluded)

        isValid = IsValidDate(*dose);       // check if date is valid

        if(isValid == -1)                   
            printf("%c Error: Invalid date. Please try again.\n", 16);

    }while(isValid == -1);                  // continue asking for input if date input is invalid
}

/*  InputVaccine is a function that prompts for vaccine input
    @param *vaccine - string that holds the address of user vaccine
    @return nothing since it is a void function
    Pre-condition: Vaccine should only consist of characters in the alphabet or 'N/A'
*/
void
InputVaccine(String10 * vaccine)
{
    printf(" Vaccine:            ");
    scanf("%10s", *vaccine);            // vaccine should have up to 10 characters only (null byte excluded)
}

/*  InputVaccine is a function that prompts for location input
    @param *location - string that holds the address of vaccination location
    @return nothing since it is a void function
    Pre-condition: Location should be a string of 10 characters and it should not have any spaces
*/
void
InputLocation(String10 * location)
{
    printf(" Location:           ");
    scanf("%10s", *location);           // location should have up to 10 characters only (null byte excluded)
}

/*  IsValidTime is a function that checks if time input is valid
    @param time - string that holds vaccination time
    @return 1 if time is valid; -1 if invalid
    Pre-condition: Time should be in 24-hour format
*/
int
IsValidTime(String6 time)
{
    // 0 1 2 3 4      |     INDICES
    // 0 0 : 0 0      |     TIME IN 24-HOUR FORMAT

    int time1 = ConcatenateDigits(ExtractDigit(time[0]), ExtractDigit(time[1])); // get integer equivalent of the digits BEFORE the colon
    int time2 = ConcatenateDigits(ExtractDigit(time[3]), ExtractDigit(time[4])); // get integer equivalent of the digits AFTER the colon
    
    if(0 <= time1 && time1 <= 24)       // check if the concatenated digit before the colon is between 0 and 24
        if(0 <= time2 && time2 < 60)    // check if the concatenated digit after the colon is between 0 and 60
            return 1;                   

    return -1;                          // return -1 if time is invalid
}

/*  InputTime is a function that prompts for time input
    @param *time - string that holds the address of time input
    @return nothing since it is a void function
    Pre-condition: Time should be a string of 6 characters and it should be in 24-hour format
*/
void
InputTime(String6 * time)
{
    int isValid;

    do{
        printf(" Time (24-Hour):                ");
        scanf("%6s", *time);                // scan up to 6 characters for input validation

        isValid = IsValidTime(*time);       // check if time is valid

        if(isValid == -1)
            printf("%c Error: Invalid time. Please try again.\n", 16);

    }while(isValid == -1);                  // continue asking for time input if time is invalid
}

/*  IsValidDose is a function that checks if appointment dose if valid
    @param dose - string that holds dose input from user
    @return 1 if valid; -1 if invalid
*/
int
IsValidDose(String10 dose)
{
    if((strcmp(dose, "First") == 0) || (strcmp(dose, "Second") == 0) || (strcmp(dose, "Booster") == 0)) // input should strictly be any of these
        return 1;

    return -1;
}

/*  InputWhatDose is a function that prompts for dose input
    @param *dose - string that holds the address of dose input from user
    @return nothing since it is a void function
    Pre-condition: Dose should be up to 10 characters only and it will be checked for input validation
*/
void
InputWhatDose(String10 * dose)
{
    int isValid; 

    do{
        printf(" Dose (First, Second, Booster): ");
        scanf("%10s", *dose);               // scan up to 10 characters for input validation

        isValid = IsValidDose(*dose);       // check if dose is valid

        if(isValid == -1)
            printf("%c Error: Invalid input. Please try again.\n", 16);

    }while(isValid == -1);                  // continue asking for dose input if it is invalid
    
}

/*  SearchID is a function that searches for user ID using linear search
    @param key - user ID to be searched
    @param n - total number of user IDs
    @return index of where the user ID is found; -1 if not found
*/
int
SearchID(int key, int n)
{
    int i = 0;
    
    for(i = 0; i < n; i++)
        if(user[i].ID == key)
            return i;           // return index if found
    
    return -1;                  // return -1 if not found
}

/*  SearchAppID is a function that searches for app ID using linear search
    @param key - app ID to be searched
    @param n - total number of app IDs
    @return index of where the app ID is found; -1 if not found
*/
int
SearchAppID(int key, int n)
{
    int i = 0;
    
    for(i = 0; i < n; i++)
        if(user[i].appointment.ID == key)
            return i;           // return index if found

    return -1;                  // return -1 if not found
}

/*  UserSignIn is a function that prompts for login from user
    @param index - index of the user
    @return index if login is successful; -1 if unsuccessful (after three attempts)
    Pre-condition: The program automatically terminates after three unsuccessful attempts
*/
int
UserSignIn(int index)
{
    int i;
    int tempID;
    int isCorrect = 0;
    int attempts = 3;       // total number of login attempts
    String10 tempPassword;  // temporarily stores password of user

    while(attempts > 0 && !isCorrect)   // continue the loop as long as there are still attempts left AND login incorrect
    {
        printf("                  ");   // spaces used to center the login function on the screen
        for(i = 0; i < 18; i++)         // border design using ASCII symbols
            printf("%c", 196);
        printf("\n                   %c USER SIGN-IN %c \n                  ", 175, 174);
        for(i = 0; i < 18; i++)         // border design using ASCII symbols
            printf("%c", 196);

        printf("\n                  User ID:  ");
        scanf("%d", &tempID);                               // get id and password input
        printf("                 ");                        // spaces to center the design
        InputPassword(tempPassword);

        index = SearchID(tempID, index);                    // linear search

        if(strcmp(user[index].password, tempPassword) == 0) // check if password matches with user id
        {
            isCorrect = 1;                                  // break the loop once login attempt is correct
            printf("\n\n                  [LOGIN SUCCESSFUL]\n\n\n");
        }// end if
        else
        {
            attempts--;                                     // otherwise, decrement the number of attempts left
            printf("\n\n                 [INCORRECT PASSWORD]\n\n\n");
        }// end else
    }// end while

    if(isCorrect == 1)
        return index;
    else
        return -1;
}

/*  AdminSignIn is a function that prompts for login from admin
    @param admin_Kath - admin of the program
    @return 1 if login is successful; -1 if unsuccessful (after three attempts)
    Pre-condition: The program automatically terminates after three unsuccessful attempts
*/
int
AdminSignIn(struct adminTag admin_Kath)
{
    int i;
    int tempID;
    int isCorrect = 0;
    int attempts = 3;
    String10 tempPassword;

    while(attempts > 0 && !isCorrect)       // continue the loop as long there are still attempts left AND login is incorrect
    {
        printf("                  ");       // spaces to center the design on screen
        for(i = 0; i < 18; i++)
            printf("%c", 196);
        printf("\n                  %c ADMIN SIGN-IN %c \n                  ", 175, 174);
        for(i = 0; i < 18; i++)
            printf("%c", 196);
        
        printf("\n                  Admin ID:  ");
        scanf("%d", &tempID);                       // get id and password input
        printf("                 ");
        InputPassword(tempPassword);

        /* check if password matches with admin 1 */
        if(tempID == admin_Kath.ID)
        {
            if(strcmp(admin_Kath.password, tempPassword) == 0)
            {
                isCorrect = 1;               // break the loop once login is successful
                printf("\n\n                  [LOGIN SUCCESSFUL]\n\n\n");
            }// end if
            else
            {
                attempts--;                  // decrement the number of attempts if login is incorrect
                printf("\n\n                 [INCORRECT PASSWORD]\n\n\n");
            }// end else
        }// end if
        else
        {
            attempts--;                  // if the ID input does not match with any of the admin IDs, display "INCORRECT ADMIN ID"
            printf("\n\n                 [INCORRECT ADMIN ID]\n\n\n");
        }// end else
    }

    return isCorrect;   // return 1 if login is successful, otherwise return -1
}

/*  RegisterUser is a function that prompts for user registration
    @param *index - index of user
    @return nothing since it is a void function
*/
void
RegisterUser(int * index)
{   // PrintHorizontalBorder() is called for adding a divider design
    printf("\n");
    PrintHorizontalBorder(6);   
    printf(" WELCOME TO USER REGISTRATION! ");
    PrintHorizontalBorder(6);
    printf("\n");

    InputID(&user[*index].ID);
    InputPassword(user[*index].password);
    RemoveTrailingNewLine();
    printf("\n");
    InputName(&user[*index].name);
    RemoveTrailingNewLine();
    InputAddress(&user[*index].address);
    InputContact(&user[*index].contact);
    InputSex(&user[*index].sex);
    PrintHorizontalBorder(10);

    printf(" FIRST DOSE INFORMATION ");
    PrintHorizontalBorder(9);
    printf("\n");
    InputDose(&user[*index].first.dose);
    InputVaccine(&user[*index].first.vaccine);
    InputLocation(&user[*index].first.location);
    PrintHorizontalBorder(9);

    printf(" SECOND DOSE INFORMATION ");
    PrintHorizontalBorder(9);
    printf("\n");
    printf(" Type N/A if you have not received a dose yet.\n");
    InputDose(&user[*index].second.dose);
    InputVaccine(&user[*index].second.vaccine);
    InputLocation(&user[*index].second.location);
    PrintHorizontalBorder(9);

    printf(" BOOSTER DOSE INFORMATION ");
    PrintHorizontalBorder(8);
    printf("\n");
    printf(" Type N/A if you have not received a dose yet.\n");
    InputDose(&user[*index].booster.dose);
    InputVaccine(&user[*index].booster.vaccine);
    InputLocation(&user[*index].booster.location);
    PrintHorizontalBorder(45);
    printf("\n\n      [User Registration is Successful]\n\n\n");
    user[*index].appointment.canceled = 1; // this will be set automatically to 1 because the user has just registered and they have no appointment yet
}

/*  EditUserInfo is a function that edits a user's information
    @param n - total number of successfully registered users
    @return nothing since it is a void function
*/
void
EditUserInfo(int n)
{
    int edit_again = 1;
    int input;
    int ID;
    int index = 0;

    while(edit_again == 1)          // continue to loop if the admin decides to edit again
    {
        printf("  %c Enter User ID: ", 175);
        scanf("%d", &ID);           // get user ID

        index = SearchID(ID, n);    // search user ID using linear search

        if(index != -1)             // if index if found, display the following:
        {
            DisplayEditUserDetails();
            input = GetInput();     // choose user information to be edited

            switch(input)
            {
                case 1: InputID(&user[index].ID); break;
                case 2: RemoveTrailingNewLine(); InputName(&user[index].name); break;
                case 3: RemoveTrailingNewLine(); InputAddress(&user[index].address); break;
                case 4: InputContact(&user[index].contact); break;
                case 5: InputSex(&user[index].sex); break;
                case 6: InputDose(&user[index].first.dose); break;
                case 7: InputVaccine(&user[index].first.vaccine); break;
                case 8: InputLocation(&user[index].first.location); break;
                case 9: InputDose(&user[index].second.dose); break;
                case 10: InputVaccine(&user[index].second.vaccine); break;
                case 11: InputLocation(&user[index].second.location); break;
                case 12: InputDose(&user[index].booster.dose); break;
                case 13: InputVaccine(&user[index].booster.vaccine); break;
                case 14: InputLocation(&user[index].booster.location); break;
            }// end switch
            printf("\n [User Information has been edited]\n");
        }else
            printf(" %c Error: Invalid ID!\n\n", 175);

        printf("\n Do wish to edit another user?\n");
        printf(" [1] Yes\n");
        printf(" [2] No\n");

        edit_again = GetInput();
    }
}

/*  DeleteUser is a function that deletes a user
    @param *delete1 - takes in the user ID
    @param *delete2 - takes in the "deleted" member of userTag struct
    @return nothing since it is a void function
    Pre-condition: The ID to be deleted must be searched first if it exists before it gets passed on this function
*/
void
DeleteUser(int * delete1, int * delete2)
{
    *delete1 = 0;    // set ID to 0 if the admin decides to delete a user to avoid similar IDs in the future
    *delete2 = 1;    // set the deleted member to 1
    printf(" [User has been successfully deleted]\n");
}

/*  EditAppointment is a function that edits a user's appointment
    @param index - user appointment index to be edited
    @return nothing since it is a void function
    Pre-condition: The app ID has been already searched in the main function if it exists or not
*/
void
EditAppointment(int index)
{
    int edit_again = 1;
    int input;

    while(edit_again == 1)          // continue the loop if the user/admin wishes to edit an appointment again
    {
        DisplayEditAppointment();   
        input = GetInput();         // get appointment information to be edited
        printf("\n");

        switch(input)
        {
            case 1: InputAppID(&user[index].appointment.ID); break;
            case 2: RemoveTrailingNewLine(); InputName(&user[index].appointment.name); break;
            case 3: InputLocation(&user[index].appointment.location); break;
            case 4: InputVaccine(&user[index].appointment.vaccine); break;
            case 5: InputDose(&user[index].appointment.date); InputTime(&user[index].appointment.time); break;
        }// end switch

        printf(" [Appointment has been successfully edited]\n");

        printf("\n Do wish to edit this appointment again?\n");
        printf(" [1] Yes\n");
        printf(" [2] No\n");

        edit_again = GetInput();

        printf("\n");
    }
}

/*  CancelAppointment is a function that deletes a user's appointment
    @param user[] - struct of the user
    @param index - index of the user
    @return nothing since it is a void function
    Pre-condition: The app ID to be deleted must be searched first if it exists before it gets passed on this function
*/
void
CancelAppointment(struct userTag user[], int index)
{
    user[index].appointment.ID = 0;         // set ID to zero to avoid similar app IDs in the future
    user[index].appointment.canceled = 1;   // set canceled member to 1
    printf(" [Appointment has been successfully cancelled]\n");
}

/*  SetAppointment is a function that sets a vaccination appointment
    @param *index - pointer that stores the address of the index of the user
    @return nothing since it is a void function
    Pre-condition: The user must be registered first in order to book an appointment
*/
void
SetAppointment(int * index)
{   // PrintHorizontalBorder() is called to print a divider design
    printf("\n");
    PrintHorizontalBorder(6);
    printf(" WELCOME TO APPOINTMENT BOOKING! ");
    PrintHorizontalBorder(6);
    printf("\n");
    InputAppID(&user[*index].appointment.ID);
    RemoveTrailingNewLine(); 
    InputName(&user[*index].appointment.name);
    PrintHorizontalBorder(7);

    printf(" SET YOUR APPOINTMENT DETAILS ");
    PrintHorizontalBorder(8);
    printf("\n");
    RemoveTrailingNewLine(); 
    InputLocation(&user[*index].appointment.location);
    RemoveTrailingNewLine(); 
    InputVaccine(&user[*index].appointment.vaccine);
    InputDose(&user[*index].appointment.date);
    PrintHorizontalBorder(10);

    printf(" BOOK YOUR TIME AND DOSE ");
    PrintHorizontalBorder(10);
    printf("\n");
    InputTime(&user[*index].appointment.time);
    InputWhatDose(&user[*index].appointment.dose);
    PrintHorizontalBorder(47);
    printf("\n\n      [Appointment Booking is Successful]\n\n");
    user[*index].appointment.canceled = 0;
}

/*  OpenAppointmentMenu is a function that opens the different options of the appointment menu, depending on user input
    @param index - integer that stores the current index of user
    @param input - integer that stores appointment sub-menu input from user
    @return the index of user
*/
int
OpenAppointmentMenu(int index, int input)
{
    switch(input)
    {
        case 1: SetAppointment(&index);
                index++;                        // if the user decides to set an appointment, index will be incremented
                break;
        case 2: DisplayManageAppointment();
                input = GetInput();

                if(input == 1)
                    CancelAppointment(user, index);  
                else if(input == 2)
                    EditAppointment(index);
                    
                break;
    } 

    return index;
}

/*  SwapStruct is a function that swaps two structures with the same number of members
    @param *x - pointer that stores the address of the first struct to be swapped
    @param *y - pointer that stores the address of the second struct to be swapped
    @return nothing since it is a void function
    Pre-condition: The structs to be swapped should have the same number of members
*/
void
SwapStruct(struct userTag * x, struct userTag * y)
{
    struct userTag temp;    // declare a temp struct for swapping

    temp = *x;              // swap the structs
    *x = *y;
    *y = temp;
}

/*  SelectionSort is a function that sorts the users in ascending order based on their user ID
    @param user[] - array of users
    @param n - total number of registered users
    @return nothing since it is a void function
*/
void
SelectionSort(struct userTag user[], int n)
{
    int i;
    int j;
    int min;

    for(i = 0; i < n-1; i++)    // continue to compare until n-1 users
    {
        min = i;                // do selection sort

        for(j = i+1; j < n; j++)
        {
            if(user[min].ID > user[j].ID)   
                min = j;
        }// end for

        SwapStruct(&user[i], &user[min]); // swap the structs
    }// end for
}

/*  GetFileName is a pointer function that prompts for file name input and thereafter displays a progress bar 
    @param file - string that holds the file name
    @return the file name string
*/
char *
GetFileName(String30 file)
{
    int i;
    int j;

    printf("  %c File name: ", 175);    // 175 is an arrow ASCII symbol
    scanf("%s", file);                  // get file name input

    printf("  %c Locating File. Please Wait...\n\n ", 175); 

    for(i = 0; i < 25; i++)             // number of progress bars to print
    {
        for(j = 0; j < 100000000; j++); // (second loop for delay) NOTE: this loop does not execute 
                                        // anything, hence the semicolon at the end
        
        printf("%c", 219);              // 219 is a single progress bar in ASCII symbol
    }// end for

    printf(" 100%%\n\n");               // print 100% after printing the progress bars
        
    return file;
}

/*  ImportUserRecord is a function that imports a list of users
    @param *fp - is a file pointer
    @param index - current index of user
    @return the updated index
    Pre-condition: There is a separate function for checking if the file exists or not
*/
int
ImportUserRecord(FILE * fp, int index)
{
    int input;
    int zero;
    String30 temp;

    fp = fopen("Users.txt", "r");  // open file in read mode
                                   
    do{ // scan the content of the file
        fscanf(fp, "%d %s", &user[index].ID, user[index].password);
        fgets(temp, sizeof(String20), fp);  // scan trailing new line to remove it
        fscanf(fp, "%[^\n]", user[index].name);
        fgets(temp, sizeof(String20), fp);  // scan trailing new line to remove it
        fscanf(fp, "%[^\n]", user[index].address);
        fscanf(fp, "%1d%I64d", &zero, &user[index].contact); // zero is used to scan leading zero
        fscanf(fp, "%s", user[index].sex); 
        fscanf(fp, "%s %s %s", user[index].first.location, user[index].first.dose, user[index].first.vaccine);
        fscanf(fp, "%s %s %s", user[index].second.location, user[index].second.dose, user[index].second.vaccine);
        fscanf(fp, "%s %s %s", user[index].booster.location, user[index].booster.dose, user[index].booster.vaccine);
        user[index].appointment.canceled = 1;   // appointment is automatically canceled unless they decide to set an appointment for themselves

        if(isValidID(user[index].ID) == 1)  // if the ID is valid (for input validation only), it will only ask the 
        {   // DISPLAY USER INFORMATION     // admin if the user should be added to the list of users in the array
            printf("\n");                   
            PrintHorizontalBorder(13);
            printf(" USER INFORMATION ");
            PrintHorizontalBorder(13);
            printf("\n  USER ID:   %d\n", user[index].ID);
            printf("  PASSWORD:  %s\n", user[index].password);
            printf("  NAME:      %s\n", user[index].name);
            printf("  ADDRESS:   %s\n", user[index].address);
            printf("  CONTACT:   0%I64d\n", user[index].contact);
            PrintHorizontalBorder(10);
            printf(" FIRST DOSE INFORMATION ");
            PrintHorizontalBorder(10);
            printf("\n  LOCATION:  %s\n", user[index].first.location);
            printf("  DOSE:      %s\n", user[index].first.dose);
            printf("  VACCINE:   %s\n", user[index].first.vaccine);
            PrintHorizontalBorder(9);
            printf(" SECOND DOSE INFORMATION ");
            PrintHorizontalBorder(10);
            printf("\n  LOCATION:  %s\n", user[index].second.location);
            printf("  DOSE:      %s\n", user[index].second.dose);
            printf("  VACCINE:   %s\n", user[index].second.vaccine);
            PrintHorizontalBorder(9);
            printf(" BOOSTER DOSE INFORMATION ");
            PrintHorizontalBorder(9);
            printf("\n  LOCATION:  %s\n", user[index].booster.location);
            printf("  DOSE:      %s\n", user[index].booster.dose);
            printf("  VACCINE:   %s\n", user[index].booster.vaccine);
            PrintHorizontalBorder(46);

            printf("\n\n Do you wish to import this record?\n");
            printf(" [1] Yes\n");
            printf(" [2] No\n\n");
            input = GetInput();

            if(input == 1)  // if the record is imported, it will be stored in the array 
                index++;    // and the index will be incremented for the next users
        }// end if
        
    }while(!feof(fp));      // continue the loop until end of file is reached

    fclose(fp);             // close the file

    return index;           // return the updated index
}

/*  ImportAppointment is a function that imports a list of appointments
    @param *fp - is a file pointer
    @param index - current index of user
    @param *appind - pointer that holds the address of the current app index
    @return updated *appind
    Pre-condition: There is a separate function for checking if the file exists or not. The appointment should already have a registered user
*/
int
ImportAppointment(FILE * fp, int index, int *appind)
{
    int input;
    int tempID;
    int tempID2;
    int app_index = 0;
    String30 temp;

    fp = fopen("Appointment.txt", "r"); // open file in read mode
    
    do{
        fscanf(fp, "%d %d", &tempID, &tempID2);
        app_index = SearchID(tempID2, index);   // search if user ID exists already, otherwise the record would not be imported
        fgets(temp, sizeof(String20), fp);      // remove trailing new line
        user[app_index].appointment.ID = tempID;
        fscanf(fp, "%[^\n]", user[app_index].appointment.name);
        fgets(temp, sizeof(String20), fp);
        fscanf(fp, "%[^\n]", user[app_index].appointment.location);
        fgets(temp, sizeof(String20), fp);
        fscanf(fp, "%[^\n]", user[app_index].appointment.vaccine);
        fgets(temp, sizeof(String20), fp);
        fscanf(fp, "%[^\n]", user[app_index].appointment.date);
        fgets(temp, sizeof(String20), fp);
        fscanf(fp, "%[^\n]", user[app_index].appointment.time);
        fgets(temp, sizeof(String20), fp);
        fscanf(fp, "%[^\n]", user[app_index].appointment.dose);
        user[app_index].appointment.canceled = 0;

        printf("\n");
        PrintHorizontalBorder(14);
        printf(" APPOINTMENT RECORD ");
        PrintHorizontalBorder(14);
        printf("\n  APPLICATION ID:  %d\n", user[app_index].appointment.ID);
        printf("  USER ID:         %d\n", tempID2);
        printf("  NAME:            %s\n", user[app_index].appointment.name);
        PrintHorizontalBorder(15);
        printf(" BOOKING DETAILS ");
        PrintHorizontalBorder(16);
        printf("\n  DATE:            %s\n", user[app_index].appointment.date);
        printf("  LOCATION:        %s\n", user[app_index].appointment.location);
        printf("  TIME:            %s\n", user[app_index].appointment.time);
        PrintHorizontalBorder(13);
        printf(" VACCINATION DETAILS ");
        PrintHorizontalBorder(14);
        printf("\n  VACCINE:         %s\n", user[app_index].appointment.vaccine);
        printf("  DOSE:            %s\n", user[app_index].appointment.dose);
        PrintHorizontalBorder(50);

        printf("\n\n\n Do you wish to import this record?\n");
        printf(" [1] Yes\n");
        printf(" [2] No\n");
        input = GetInput();

        if(input == 1)
            *appind += 1;   // add 1 each time the admin imports a record
            
    }while(!feof(fp));      // continue asking if the appointment should be added to the list of entries until the end of file

    fclose(fp);             // close the file

    return *appind;         // return the updated app index
}

/*  ImportChatbot is a function that imports a list of questions and answers from the chatbot text file
    @param *fp - is a file pointer
    @param question - an array of strings that holds the chatbot questions
    @param answer - an array of strings that holds the chatbot answers
    @param index - parameter that holds the current index of the chatbot questions and answers
    @return updated index of chatbot
    Pre-condition: There is a separate function for checking if the file exists or not
*/
int
ImportChatbot(FILE * fp, String80 question[], String80 answer[], int index)
{
    int input; 
    String80 temp;

    fp = fopen("Chatbot.txt", "r");

    while(!feof(fp))    // continue scanning the file until the end of file
    {
        fscanf(fp, "%[^\n]", question[index]);
        fgets(temp, sizeof(String80), fp);
        fscanf(fp, "%[^\n]", answer[index]);
        fgets(temp, sizeof(String80), fp);

        PrintHorizontalBorder(88);
        printf("\n  QUESTION: %s\n", question[index]);
        PrintHorizontalBorder(88);
        printf("\n  ANSWER: %s\n", answer[index]);
        PrintHorizontalBorder(88);

        printf("\n Do you wish to import this?\n");
        printf(" [1] Yes\n");
        printf(" [2] No\n");
        
        input = GetInput();

        if(input == 1)
            index++;        // increment chatbot index if the admin wishes to import a chatbot question and answer

    }// end while

    fclose(fp);             // close the file

    return index;           // return updated index
}

/*  AddQuestionsAndAnswers is a function that adds a list of questions and answers
    @param question - an array of strings that holds the chatbot questions
    @param answer - an array of strings that holds the chatbot answers
    @param index - parameter that holds the current index of the chatbot questions and answers
    @return updated index of chatbot
*/
int
AddQuestionsAndAnswers(String80 question[], String80 answer[], int index)
{
    int add_again;
    String80 temp_q;
    String80 temp_a;

    do{
        PrintHorizontalBorder(85);

        printf("\n  NEW QUESTION\n");
        printf("   Q: ");
        RemoveTrailingNewLine();
        scanf("%[^\n]", temp_q);            // add a new question
        strcpy(question[index], temp_q);

        PrintHorizontalBorder(85);          // divider border design

        printf("\n  NEW ANSWER\n");
        printf("   A: ");
        RemoveTrailingNewLine();
        scanf("%[^\n]", temp_a);            // add an answer to the question
        strcpy(answer[index], temp_a);

        PrintHorizontalBorder(85);          // divider border design
        index++;                            // increment chatbot index each time the admin adds a question and answer

        printf("\n [Successfully added]\n");
        printf("\n Do you wish to add another question?\n");
        printf(" [1] Yes\n");
        printf(" [0] No\n");
        add_again = GetInput();           
            
    }while(add_again == 1); // if the admin wishes to add another question, the loop will continue

    return index;           // return updated chatbot index
}

/*  SearchChatbotIndex is a linear search function for chatbot index
    @param key - index to be found
    @param n - total number of questions and answers
    @return the index if found; -1 if not found
*/
int
SearchChatbotIndex(int key, int n)
{
    int i = 0;
    
    for(i = 0; i < n; i++)
        if(key == i)
            return i;
    
    return -1;
}

/*  EditQuestionsAndAnswers is a function that allows the admin to edit a question and answer from the list of chatbot entries
    @param question - an array of strings that holds the chatbot questions
    @param answer - an array of strings that holds the chatbot answers
    @param n - total number of questions and answers
    @return nothing since it is a void function
*/
void 
EditQuestionsAndAnswers(String80 question[], String80 answer[], int n)
{   
    int index;  
    int edit_again;

    do{
        PrintHorizontalBorder(80);              // divider border design
        printf("\n Enter Index:   ");
        scanf("%d", &index);                    // get index to edit

        index = SearchChatbotIndex(index, n);   // linear search the index

        if(index != -1)                         // if the index exists, edit the question and answer
        {
            RemoveTrailingNewLine();
            PrintHorizontalBorder(80);

            printf("\n Edit Question: ");
            scanf("%[^\n]", question[index]);
            RemoveTrailingNewLine();
            PrintHorizontalBorder(80);

            printf("\n Edit Answer:   ");
            scanf("%[^\n]", answer[index]);
            PrintHorizontalBorder(80);

            printf("\n [Question and Answer Successfully Edited]\n\n");
        }// end if
        else
            printf(" [Error: Invalid Index]\n\n\n");

        printf(" Do you wish to edit another question?\n");
        printf(" [1] Yes\n");
        printf(" [2] No\n");
        printf(" %c Input: ", 175);
        scanf("%d", &edit_again); 

    }while(edit_again == 1);    // continue the loop if the admin wishes to edit another question

    printf("\n");
}

/*  DeleteChatbotInfo is a function that deletes the an entry from the list of chatbot questions and answers
    @param question - an array of strings that holds the chatbot questions
    @param answer - an array of strings that holds the chatbot answers
    @param n - total number of questions and answers
    @return n (updated number of questions and answers)
*/
int
DeleteChatbotInfo(String80 question[], String80 answer[], int n)
{   
    int i;
    int delete_ind;
    int delete_again;

    do{
        printf(" %c Enter Index to Delete: ", 175);
        scanf("%d", &delete_ind);                           // get index to delete
        delete_ind = SearchChatbotIndex(delete_ind, n);     // search if the index exists

        if(delete_ind != -1)                                // if it exists, delete the question and answer with that index
        {
            for(i = delete_ind; i < n; i++)                 // start the loop with the index to be deleted
            {                                               // shift the array by replacing the current index with the previous one
                strcpy(question[i], question[i+1]);         
                strcpy(answer[i], answer[i+1]);
            }// end for
            n--;                                            // decrement n by 1 because an entry was deleted

            printf(" [Succesfully Deleted]\n\n");
        }// end if
        else
            printf(" [Error: Invalid Index]\n\n\n");

        printf(" Do you wish to delete another question and answer?\n");
        printf(" [1] Yes\n");
        printf(" [0] No\n");
        delete_again = GetInput();

    }while(delete_again == 1);          // continue the loop if the admin wishes to delete another entry

    return n;                           // return the update number of questions/answers
}

/*  ExecuteChatbot is a function that executes the chatbot feature of the program
    @param question - an array of strings that holds the chatbot questions
    @param answer - an array of strings that holds the chatbot answers
    @param index - total number of questions and answers
    @return nothing since it is a void function
    Pre-condition: The list of questions and answers must be imported first before executing the chatbot
*/
void
ExecuteChatbot(String80 question[], String80 answer[], int index)
{   
    int i;
    int isFound;
    int continue_loop = 0;
    String80 temp;

    printf("\n  %c", 201);      // border design using ASCII symbols

    for(i = 0; i < 43; i++)
        printf("%c", 205);      // border design using ASCII symbols

    printf("%c", 187);          // border design using ASCII symbols

    printf("\n  %c Hi, this is VacciBot, how may I help you? %c \n  ", 186, 186);

    printf("%c", 200);          // border design using ASCII symbols

    for(i = 0; i < 43; i++)
        printf("%c", 205);      // border design using ASCII symbols

    printf("%c", 188);          // border design using ASCII symbols

    do{
        isFound = 0;

        printf("\n  %c Type Here: ", 175);
        RemoveTrailingNewLine();
        scanf("%[^\n]", temp);                      // type a question

        for(i = 0; i < index && !isFound; i++)      // search the question in the array of questions
            if(strcmp(question[i], temp) == 0)
                isFound = 1;

        if(isFound == 1)
            printf("  %c VacciBot: %s\n", 175, answer[i-1]);    // display the answer to the question
        else
            printf("  %c VacciBot: Sorry, I don't know the answer. Please type another question.\n\n", 175);
        
        printf("\n\n ");
        PrintHorizontalBorder(12);
        printf(" CHATBOT MENU ");
        PrintHorizontalBorder(12);
        printf("\n");
        printf("   [1] Ask another question\n");
        printf("   [0] Exit VacciBot\n ");
        PrintHorizontalBorder(38);
        printf("\n ");
        continue_loop = GetInput();

    }while(continue_loop == 1);     // continue the loop if the user wishes to ask another question
                                    // otherwise, exit the chatbot feature

    printf("\n\n");
}

/*  OverwriteUserFile is a function that overwrites the user text file when exported
    @param *fp - is a file pointer
    @param index - current index of the list of users
    @param user[] - array of registered users
    @return nothing since it is a void function
*/
void
OverwriteUserFile(FILE * fp, int index, struct userTag user[])
{   
    int i;
    String30 temp;

    strcpy(temp, " ");              // intialize an emptry string to temp

    fp = fopen("Users.txt", "w");   // open file in write mode

    if(fp != NULL)                  // if the file exists, overwrite the file
    {
        for(i = 0; i < index; i++)
        {
            if(user[i].deleted != 1 && strcmp(user[i].name, "") != 0)   // the users that were not deleted in the 
            {                                                           // current run will be printed on the text file
                fprintf(fp, "%d %s\n", user[i].ID, user[i].password);
                fprintf(fp, "%s\n", user[i].name);
                fprintf(fp, "%s\n", user[i].address);
                fprintf(fp, "0%I64d\n", user[i].contact);
                fprintf(fp, "%s\n", user[i].sex);
                fprintf(fp, "%s %s %s\n", user[i].first.location, user[i].first.dose, user[i].first.vaccine);
                fprintf(fp, "%s %s %s\n", user[i].second.location, user[i].second.dose, user[i].second.vaccine);
                fprintf(fp, "%s %s %s", user[i].booster.location, user[i].booster.dose, user[i].booster.vaccine);

                if(i != index-1)            // DO NOT print a new line on the file once end of array is reached
                    fprintf(fp, "\n\n");    // this condition is used to avoid printing a trailing new line at the end of file
            }// end if
        }// end for
    }// end if

    fclose(fp); // close the file
}

/*  OverwriteAppFile is a function that overwrites the appointment text file when exported
    @param *fp - is a file pointer
    @param index - current index of the list of appointments
    @return nothing since it is a void function
*/
void
OverwriteAppFile(FILE * fp, int index)
{
    int i;

    fp = fopen("Appointment.txt", "w"); // open the file in write mode

    if(fp != NULL)                      // if the file exists, overwrite the file
    {
        for(i = 0; i < index; i++)
        {
            if(user[i].appointment.canceled != 1)   // only display entries that were not canceled in the current run
            {
                fprintf(fp, "%d %d\n", user[i].appointment.ID, user[i].ID);
                fprintf(fp, "%s\n", user[i].appointment.name);
                fprintf(fp, "%s\n", user[i].appointment.location);
                fprintf(fp, "%s\n", user[i].appointment.vaccine);
                fprintf(fp, "%s\n", user[i].appointment.date);
                fprintf(fp, "%s\n", user[i].appointment.time);
                fprintf(fp, "%s", user[i].appointment.dose);

                if(i != index-1)            // DO NOT print a new line on the file once end of array is reached
                    fprintf(fp, "\n\n");    // this condition is used to avoid printing a trailing new line at the end of file
            }// end if
        }// end for
    }// end if

    fclose(fp); // close the file
}

/*  OverwriteChatbotFile is a function that overwrites the chatbot text file when exported
    @param *fp - is a file pointer
    @param question - an array of strings that holds the chatbot questions
    @param answer - an array of strings that holds the chatbot answers
    @param index - total number of questions and answers
    @return nothing since it is a void function
*/
void
OverwriteChatbotFile(FILE * fp, String80 question[], String80 answer[], int index)
{   
    int i;

    fp = fopen("Chatbot.txt", "w"); // open the file in write mode

    if(fp != NULL)                  // if the file exists, overwrite the chatbot text file
    {
        for(i = 0; i < index; i++)
        {
            fprintf(fp, "%s\n", question[i]);
            fprintf(fp, "%s", answer[i]);

            if(i != index-1)        // DO NOT print a new line on the file once end of array is reached
                fprintf(fp, "\n");  // this condition is used to avoid printing a trailing new line at the end of file
        }// end for
    }// end if
    
    fclose(fp); // close the file
}

/*  PrintUserTable is a function that prints a table of users using ASCII symbols and sorts their IDs in ascending order 
    @param *n - is the number of users to print
    @return nothing since it is a void function
*/
void
PrintUserTable(int * n)
{
    int i;
    int ind;

    // Center the table using spaces
    printf("                                  L I S T   O F\n                                 ");                          // ASCII symbols when put together:
    printf("%c %c%c%c%c%c%c%c%c%c%c%c%c%c\n", 203, 203, 201, 205, 187, 201, 205, 187, 203, 205, 187, 203, 205, 187);       // ╦ ╦╔═╗╔═╗╦═╗╔═╗ 1st printf()
    printf("                                 ");                                                                           // ║ ║╚═╗║╣ ╠╦╝╚═╗ 2nd printf()
    printf("%c %c%c%c%c%c%c %c%c%c%c%c%c\n", 186, 186, 200, 205, 187, 186, 185, 204, 203, 188, 200, 205, 187);             // ╚═╝╚═╝╚═╝╩╚═╚═╝ 3rd printf()
    printf("                                 ");                                
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 188, 200, 205, 188, 200, 205, 188, 202, 200, 205, 200, 205, 188); 
    
    SelectionSort(user, *n);    // sort user IDs in ascending order

    for(ind = 0; ind < *n; ind++)
    {
        if(user[ind].deleted != 1 && user[ind].ID != 0) // only display entries that were not deleted
        {
            printf("\n   ");

            for(i = 0; i < 71; i++)  // make a table using ASCII symbols and place them in a loop
            {
                printf("%c", 205);

                if(i == 35)
                    printf("%c", 203);
            }// end for

            printf("\n     USER ID                           %c    %d", 186, user[ind].ID);
            printf("\n     NAME                              %c    %s", 186, user[ind].name);
            printf("\n     ADDRESS                           %c    %s", 186, user[ind].address);
            printf("\n     CONTACT                           %c    0%I64d", 186, user[ind].contact);
            printf("\n     SEX                               %c    %s", 186, user[ind].sex);
            printf("\n     FIRST DOSE                        %c    %s", 186, user[ind].first.dose);
            printf("\n     FIRST DOSE VACCINE                %c    %s", 186, user[ind].first.vaccine);
            printf("\n     FIRST DOSE LOCATION               %c    %s", 186, user[ind].first.location);
            printf("\n     SECOND DOSE                       %c    %s", 186, user[ind].second.dose);
            printf("\n     SECOND DOSE VACCINE               %c    %s", 186, user[ind].second.vaccine);
            printf("\n     SECOND DOSE LOCATION              %c    %s", 186, user[ind].second.location);
            printf("\n     BOOSTER DOSE                      %c    %s", 186, user[ind].booster.dose);
            printf("\n     BOOSTER DOSE VACCINE              %c    %s", 186, user[ind].booster.vaccine);
            printf("\n     BOOSTER DOSE LOCATION             %c    %s", 186, user[ind].booster.location);

            printf("\n   ");

            for(i = 0; i < 71; i++) // make a table using ASCII symbols and place them in a loop
            {
                printf("%c", 205);

                if(i == 35)
                    printf("%c", 202);
            }// end for
        }// end if
    }// end for

    printf("\n\n\n");
}

/*  PrintAppointment is a function that prints a table of appointments using ASCII symbols
    @param n - is the number of appointments to print
    @return nothing since it is a void function
*/
void
PrintAppointment(int n)
{
    int i;
    int ind;

    // Center the table using spaces
    printf("                              A P P O I N T M E N T\n                                 ");           // ASCII symbols when put together:
    printf("%c%c%c%c%c%c%c%c %c  %c%c%c\n", 201, 203, 187, 201, 205, 187, 201, 187, 203, 201, 205, 187);        // ╔╦╗╔═╗╔╗ ╦  ╔═╗ 1st printf()
    printf("                                 ");                                                                //  ║ ╠═╣╠╩╗║  ║╣  2nd printf()
    printf(" %c %c%c%c%c%c%c%c  %c%c\n", 186, 204, 205, 185, 204, 202, 187, 186, 186, 185);                     //  ╩ ╩ ╩╚═╝╩═╝╚═╝ 3rd printf()
    printf("                                 ");                                
    printf(" %c %c %c%c%c%c%c%c%c%c%c%c\n   ", 202, 202, 202, 200, 205, 188, 202, 205, 188, 200, 205, 188);     
    
    SelectionSort(user, n);

    for(ind = 0; ind < n; ind++) 
    {
        if((user[ind].appointment.canceled != 1) && (user[ind].deleted != 1)) // only display entries that were not canceled
        {
            for(i = 0; i < 71; i++) // make a table using ASCII symbols and place them in a loop
            {
                printf("%c", 205);

                if(i == 35)
                    printf("%c", 203);
            }// end for

            printf("\n     APPLICATION ID                    %c    %d", 186, user[ind].appointment.ID);
            printf("\n     NAME                              %c    %s", 186, user[ind].appointment.name);
            printf("\n     LOCATION                          %c    %s", 186, user[ind].appointment.location);
            printf("\n     VACCINE                           %c    %s", 186, user[ind].appointment.vaccine);
            printf("\n     DATE                              %c    %s", 186, user[ind].appointment.date);
            printf("\n     TIME                              %c    %s", 186, user[ind].appointment.time);

            printf("\n   ");

            for(i = 0; i < 71; i++) // make a table using ASCII symbols and place them in a loop
            {
                printf("%c", 205);

                if(i == 35)
                    printf("%c", 202);
            }// end for 

            printf("\n   ");
        }// end if
    }// end for

    printf("\n\n\n");
}

/*  PrintChatbotInfo is a function that prints a list of chatbot entries using ASCII symbols
    @param question - an array of strings that holds the chatbot questions
    @param answer - an array of strings that holds the chatbot answers
    @param n - is the number of chatbot entries to print
    @return nothing since it is a void function
*/
void
PrintChatbotInfo(String80 question[], String80 answer[], int n)
{
    int i;

    printf("                                       C H A T B O T\n                                         ");
    printf("%c  %c%c%c%c%c%c%c\n", 203, 203, 201, 205, 187, 201, 203, 187);     // ASCII symbols when put together:
    printf("                                         ");                        // ╦  ╦╔═╗╔╦╗ 1st printf()
    printf("%c  %c%c%c%c %c\n", 186, 186, 200, 205, 187, 186);                  // ║  ║╚═╗ ║  2nd printf()
    printf("                                         ");                        // ╩═╝╩╚═╝ ╩  3rd printf()
    printf("%c%c%c%c%c%c%c %c\n", 202, 205, 188, 202, 200, 205, 188, 202);  

    for(i = 0; i < n; i++)
    {
        PrintHorizontalBorder(88);
        printf("\n   [INDEX #%d]\n\n", i);
        printf("   QUESTION: %s\n", question[i]);
        printf("   ANSWER: %s", answer[i]);

        if(i != n-1)        // DO NOT print a new line when end of entry is reached
            printf("\n");
    }// end for

    printf("\n");
    PrintHorizontalBorder(88);
    printf("\n\n");
}

/*  CheckFile is a function that checks if a file exists or not
    @param *fp - a file pointer
    @param filename - string that holds the file name
    @return 1 if file exists; -1 if it does not exist
*/
int
CheckFile(FILE * fp, String30 filename)
{
    fp = fopen(filename, "r");  // open the file in read mode
    
    if(fp != NULL)              // check if the file exists
        return 1;
 
    fclose(fp);                 // close the file

    return -1;                  
}

/*  DisplayTerminateProgram is a displays that the program has been terminated
    @return nothing since it is a void function
*/
void
DisplayTerminateProgram()
{
    printf("\n [Program Terminated]\n ");
    system("PAUSE");
    printf("\n\n          Thank you for using the program!");
    DisplayLaunch();
}

/* Main Function */
int
main()
{   
    /* VARIABLE DECLARATION */
    int index = 0;
    int app_index = 0;
    int chatbot_index = 0;
    int isFound = 0;
    int admin_in = 0;
    int user_in = 0;
    int tempID;
    int menu_input;
    int app_input;
    int submenu_input;
    int data_management_input;
    int open_main_menu = 1;
    int open_data_management = 1;
    int login = 0;
    int again = 0;
    int terminate_program = 0;
    String30 filename;
    FILE * fp = 0;
    String80 question[MAX];
    String80 answer[MAX];

    /* INITIALIZE ADMIN DETAILS */
    admin_Kath.ID = ADMIN1_ID;
    strcpy(admin_Kath.password, "temp");
    
    system("CLS");                      // clear screen at the start of program

    while(!terminate_program)           // the program/while loop ends if (1) the user or admin decides to exit the program;
    {                                   // or (2) after three unsuccessful attempts from login function
        if(open_main_menu == 1)
        {
            DisplayLaunch();            // display program name
            DisplayMenu();              // display main menu

            menu_input = GetInput();    // get main menu input and store it in "menu_input"
            open_main_menu = 0;         // reset "open_main_menu" to zero and set it to 1 if and only if the user decides to exit on the sub-menus
            user_in = 0;                // the "in" variable prevents asking the admin for their ID and password each 
            admin_in = 0;               // time they enter the data management menu. it will only reset back to zero if 
                                        // the admin decides to exit the data management menu.
        }// end if

        /*******************************************************************/
        /*                       M A I N   M E N U                         */
        /*******************************************************************/
        switch(menu_input)             
        {
            case 1: if(user_in == 0)                                    // case 1 is Vaccination Registration Menu
                        DisplayVaxxRegistration();                      
                    break; // break for switch case 1                                              
            case 2: if(admin_in == 0)                                   // case 2 is Data Management Menu
                    {                   
                        login = AdminSignIn(admin_Kath);                // admin login

                        if(login == 0)                                  // if the AdminSignIn() function returns 0 after three unsucessful login attempts,
                            terminate_program = 1;                      // then the "terminate_program" variable breaks the while loop on its next iteration
                        else                                            // otherwise, the admin successfully enters the data management menu
                            admin_in = 1;
                    }// end if
                    break;  // break for switch case 2
            case 3: terminate_program = 1;                              // case 3 means exit the program
                    break;  // break for switch case 3               
        }// end switch
        
        switch(menu_input)
        {
            /*******************************************************************/
            /*          V A X X   R E G I S T R A T I O N   M E N U            */
            /*******************************************************************/
            case 1: if(user_in == 0)                            // if the user hasn't entered this menu,
                        submenu_input = GetInput();             // get sub-menu input
                    
                    if(submenu_input == 1)                      // USER REGISTRATION MENU       
                    {
                        RegisterUser(&index);                   
                        index++;                                // increment the user index each time a new user registers
                    }// end if
                    else if(submenu_input == 2)                 // VAXX APPOINTMENT MENU       
                    {
                        if(user_in == 0)                        // if the user hasn't entered this menu, 
                        {                                       // prompt a user login on the screen
                            login = UserSignIn(index);          
                            
                            if(login != -1)                     // "NOT EQUAL TO -1" means login is SUCCESSFUL
                            {                                   
                                DisplayAppMenu();               

                                app_input = GetInput();         // app_input is the sub-menu input of the user from appointment menu
                                OpenAppointmentMenu(login, app_input);         

                                user_in = 1;                    // set "user_in" to 1 so that when they exit the appointment menu, 
                            }                                   // they will be redirectred to the vaxx registration menu, and NOT the main menu
                            else if(login == -1)                // "EQUAL TO -1" means login is UNSUCCESSFUL
                                terminate_program = 1;          // after three unsuccessful attempts, the program terminates
                        }// end if
                        else if(user_in == 1)                   // if the user has already entered this menu,
                        {                                       // automatically redirect them to the appointment menu
                            DisplayAppMenu();                   // without needing to login again
                            app_input = GetInput();
                            OpenAppointmentMenu(login, app_input);
                        }// end else if

                        if(app_input == 3)                      // if the user decides to press [3], which is exit appointment menu,
                            user_in = 0;                        // they have to login again if they choose this menu on the next iteration
                    }// end else if
                    else if(submenu_input == 3)                 // CHATBOT MENU  
                        ExecuteChatbot(question, answer, chatbot_index);
                    else if(submenu_input == 4)                 // EXIT VAXX REGISTRATION MENU 
                        open_main_menu = 1;                     // if the user decides to exit vaxx reg menu, they will be redirected to the main menu
                    
                    break;                                      // break for switch case 1
            
            /*******************************************************************/
            /*            D A T A   M A N A G E M E N T    M E N U             */
            /*******************************************************************/
            case 2: if(admin_in == 1)                              // if the admin has successfully entered their correct ID and password,
                    {                                              // they will get access to the data management menu
                        if(open_data_management == 1) 
                        {
                            DisplayDataManagement();               
                            submenu_input = GetInput();            // get sub-menu input from the data management menu
                            open_data_management = 1;
                        }                                  
                    
                    /* DISPLAY OPTIONS FOR DATA MANAGEMENT SUB-MENUS */
                    switch(submenu_input)                       
                    {
                        case 1: DisplayUser();                     // display user menu
                                open_data_management = 0;          // DO NOT open data management if the admin hasn't exited the user menu yet
                                break;  
                        case 2: DisplayAppointment();              // display appointment menu
                                open_data_management = 0;          // DO NOT open data management if the admin hasn't exited the app menu yet
                                break;
                        case 3: DisplayChatbotMenu();              // display chatbot menu
                                open_data_management = 0;          // DO NOT open data management if the admin hasn't exited the chatbot menu yet
                                break;
                        case 6: OverwriteUserFile(fp, index, user); // save the set of users and set of schedules.
                                OverwriteAppFile(fp, index);
                                open_main_menu = 1;                 // case 6 means exit data management menu, therefore it will redirect the admin to the main menu
                                break;
                    }// end switch

                    // numerical input is no longer needed if the admin wishes to (1) export; (2) import; (3) exit
                    // (it will only ask the admin for the file name if they decide to export/import)
                    if(submenu_input != 4 && submenu_input != 5 && submenu_input != 6)
                        data_management_input = GetInput();

                    /*******************************************************************/
                    /*                      U S E R   M E N U                          */
                    /*******************************************************************/
                    if(submenu_input == 1 && data_management_input == 1)  // ADD NEW USER
                    {
                        do{
                            RegisterUser(&index);
                            index++;                                          // increment the index each time a new user registers
                            again = DisplayRequest("add", "user");            // the DisplayRequest() function returns input from admin if they wish to add another user
                            printf("\n");                                     
                        }while(again == 1);                                   // "again" is a variable that continues the loop if the admin decides to add another user
                        again = 0;                                            // it will reset back to zero so that it may be used again for another loop on the next iteration
                    }// end if   
                    else if(submenu_input == 1 && data_management_input == 2) // VIEW USERS
                        PrintUserTable(&index);                         
                    else if(submenu_input == 1 && data_management_input == 3) // EDIT USER
                        EditUserInfo(index);
                    else if(submenu_input == 1 && data_management_input == 4) // DELETE USER
                    {
                        do{
                            printf(" %c Enter User ID: ", 175);               // input ID to delete
                            scanf("%d", &tempID);
                            tempID = SearchID(tempID, index);                 // search if the ID exists using linear search
                            
                            if(tempID != -1)                                  // if it exists, delete the user
                                DeleteUser(&user[tempID].ID, &user[tempID].deleted);
                            else                                              // otherwise, display "Invalid ID"
                                printf(" %c Error: Invalid ID!\n\n", 175);
                            
                            again = DisplayRequest("delete", "user");         // prompt the admin if they wish to delete another user
                        }while(again == 1);                                   // the loop breaks if and only if the admin does not want to delete another user
                        again = 0;
                    }// end else if
                    else if(submenu_input == 1 && data_management_input == 5) // exit user menu
                        open_data_management = 1;                             // if the admin wishes to exit, redirect them to the data management menu
                    
                    /*******************************************************************/
                    /*                 A P P O I N T M E N T   M E N U                 */
                    /*******************************************************************/
                    if(submenu_input == 2 && data_management_input == 1)                    // ADD APPOINTMENT
                    {   
                        do{
                            printf("\n              APPOINTMENT BOOKING\n");
                            printf(" %c Set an appointment for (ENTER USER ID): ", 175);
                            scanf("%d", &tempID);                                           // enter app ID
                            tempID = SearchID(tempID, index);                               // search if user ID exists
                            
                            if(tempID != -1)                                                // if it exists, book a new appointment for that user
                            {
                                SetAppointment(&tempID);
                                app_index++;                                                // increment "app_index" to determine the total number of successful bookings
                            }           
                            else
                                printf(" Error: User ID not found.");                       // otherwise, display "User ID not found."

                            again = DisplayRequest("add", "appointment");                   // ask if the admin wishes to add another appointment again
                            printf("\n\n");

                        }while(again == 1);
                        again = 0;
                    }// end else if
                    else if(submenu_input == 2 && data_management_input == 2)               // VIEW APPOINTMENTS
                        PrintAppointment(index);
                    else if(submenu_input == 2 && data_management_input == 3)               // EDIT APPOINTMENT
                    {   
                        do{
                            printf(" Enter App ID: ");                                      
                            scanf("%d", &tempID);                                           // enter app ID
                        
                            isFound = SearchAppID(tempID, index);                           // search if app ID exists using linear search
                            
                            if(isFound == -1)                                               
                                printf(" %c Error: Application ID#%d Not Found", 175, tempID);
                            else                                                            // if ID is found, edit their appointment 
                                EditAppointment(isFound);

                            again = DisplayRequest("edit", "appointment");                  // ask if the admin wishes to edit another appointment

                            printf("\n\n");
                        }while(again == 1);
                        again = 0;
                    }// end else if
                    else if(submenu_input == 2 && data_management_input == 4)               // CANCEL APPOINTMENT
                    {   
                        do{
                            printf(" Enter App ID: ");
                            scanf("%d", &tempID);                                           // input app ID

                            tempID = SearchAppID(tempID, index);                            // search if app ID exists using linear search

                            if(tempID != -1)
                                CancelAppointment(user, tempID);                            // cancel appointment if the ID exists
                            else
                                printf(" Error: Invalid ID!\n\n");

                            again = DisplayRequest("cancel", "appointment");                // ask admin if they wish to cancel another appointment
                            
                        }while(again == 1);
                        again = 0;
                    }// end else if
                    else if(submenu_input == 2 && data_management_input == 5)               // EXIT
                        open_data_management = 1;                                           // redirect admin to the data management menu
                    
                    /*******************************************************************/
                    /*                    C H A T B O T   M E N U                      */
                    /*******************************************************************/
                    if(submenu_input == 3 && data_management_input == 1)                    // ADD QUESTIONS AND ANSWERS
                        chatbot_index = AddQuestionsAndAnswers(question, answer, chatbot_index);
                    else if(submenu_input == 3 && data_management_input == 2)               // DISPLAY THE LIST OF CHATBOT QUESTIONS AND ANSWERS
                        PrintChatbotInfo(question, answer, chatbot_index);
                    else if(submenu_input == 3 && data_management_input == 3)               // EDIT QUESTIONS AND ANSWERS
                        EditQuestionsAndAnswers(question, answer, chatbot_index);
                    else if(submenu_input == 3 && data_management_input == 4)               // DELETE A QUESTION AND ANSWER
                        chatbot_index = DeleteChatbotInfo(question, answer, chatbot_index);
                    else if(submenu_input == 3 && data_management_input == 5)               // EXIT CHATBOT MENU
                        open_data_management = 1;                                           // redirect admin to the data management menu
                    
                    /*******************************************************************/
                    /*                          E X P O R T                            */
                    /*******************************************************************/
                    if(submenu_input == 4)                                                  // if sub-menu is 4, the admin chose to export a file
                    {
                        do{
                            again = 0;
                            DisplayExport();
                            GetFileName(filename);                                          // get file name to export

                            if(CheckFile(fp, filename) == 1)                                // check if the text file exists using CheckFile() function
                            {                                                               // check if the filename inputted earlier matches with the saved files
                                if(strcmp(filename, "Users.txt") == 0)
                                    OverwriteUserFile(fp, index, user);                     // overwrite the file if the admin decides to export 
                                else if(strcmp(filename, "Appointment.txt") == 0)
                                    OverwriteAppFile(fp, index);
                                else if(strcmp(filename, "Chatbot.txt") == 0)
                                    OverwriteChatbotFile(fp, question, answer, chatbot_index);

                                printf("\n [DATA EXPORTED SUCCESSFULLY]\n\n\n");            
                            }// end if
                            else if(CheckFile(fp, filename) == -1)                          // if the file does not exist, ask the admin if they wish to try again or exit the export option
                                again = DisplayError(again);

                        }while(again == 1);  
                    }// end if

                    /*******************************************************************/
                    /*                          I M P O R T                            */
                    /*******************************************************************/
                    if(submenu_input == 5)                                                  // if the sub-menu is 5, the admin chose to import a file
                    {
                        do{
                            again = 0;
                            DisplayImport();
                            GetFileName(filename);                                          // get file name

                            if(CheckFile(fp, filename) == 1)                                // check if the file exists
                            {
                                if(strcmp(filename, "Users.txt") == 0)                      // check if the file name matches with the saved files
                                    index = ImportUserRecord(fp, index);                    // if it matches, import the chosen file
                                else if(strcmp(filename, "Appointment.txt") == 0)
                                    app_index = ImportAppointment(fp, index, &app_index);
                                else if(strcmp(filename, "Chatbot.txt") == 0)
                                    chatbot_index = ImportChatbot(fp, question, answer, chatbot_index); 

                                printf("\n [DATA IMPORTED SUCCESSFULLY]\n\n\n");
                            }// end if
                            else if(CheckFile(fp, filename) == -1)                          // otherwise, ask the admin they wish to try again or exit the import menu
                                again = DisplayError(again);

                        }while(again == 1);
                    }// end if
                    
                    }// end case 2 
                    break; // break for switch case 2
        }// end switch
    }// end while

    DisplayTerminateProgram();     // display that the program was terminated once the user/admin wishes to exit the program 
                                   // or after three unsuccesful attemps from the login functions                                                  

    return 0;

}// end main
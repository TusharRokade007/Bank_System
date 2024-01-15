#include "Validate.h"
#include <stdio.h>

#define MAX 50
typedef struct Bank {
  char bankName[MAX];
  char IFSCCode[MAX];
  char accountNumber[MAX];
  char accountHolderName[MAX];
  int age;
  char gender[MAX];
  char DOB[MAX];
  char Address[MAX];
  char city[MAX];
  char typeOfAccount[MAX];
  double balance;
  char panCardNumber[MAX];
  char aadharCardNumber[MAX];
} Bank;

char *generateAccountNumber(char accountHolderName[]) {
  srand(time(NULL));
  char accountNumber[8];
  accountNumber[0] = accountHolderName[0];
  accountNumber[1] = '\0';

  for (int i = 0; i < strlen(accountHolderName); i++) {
    if (accountHolderName[i] == ' ') {
      char ch = accountHolderName[i + 1];
      ch = toupper(ch);
      char str1[2] = {ch, '\0'};
      // char str2[2] = "";
      // strcpy(str2, str1);

      strcat(accountNumber, str1);
    }
  }
  char random[MAX];
  sprintf(random, "%d", rand() % 900 + 100);
  return strcat(accountNumber, random);
}
Bank createAccount() {
  getchar();
  Bank b;
  int age;
  char accountHolderName[MAX], address[MAX], city[MAX], panCard[MAX],
      aadharCard[MAX], dob[MAX];
  int flagAccountName = 0, flagAge = 0, flagCity = 0, flagPanCard = 0,
      flagAadhar = 0, flagDob = 0, genderChoice, accountTypeChoice;
  double balance;
  strcpy(b.bankName, "HDFC Bank");
  strcpy(b.IFSCCode, "HDFC00001234");

  // account holder name
  do {
    printf("Enter Account Holder Name: ");
    fgets(accountHolderName, MAX, stdin);
    accountHolderName[strlen(accountHolderName) - 1] = '\0';
    if (isValidName(accountHolderName)) {
      flagAccountName = 1;
      strcpy(b.accountHolderName, accountHolderName);
    } else {
      flagAccountName = 0;
    }
  } while (flagAccountName != 1);

  // account Number
  strcpy(b.accountNumber, generateAccountNumber(accountHolderName));

  // age

  do {
    printf("Enter Age: ");
    int age_status = scanf("%d", &age);
    if (age_status == 1 && isValidAge(age)) {
      flagAge = 1;
      b.age = age;
    } else {
      flagAge = 0;
      while (getchar() != '\n')
        ;
    }
  } while (flagAge != 1);

  // gender
  do {
    printf("Gender\n1.Male\n2.Female");
    printf("\nEnter your choice: ");
    if (scanf("%d", &genderChoice) != 1) {
      getchar();
      continue;
    }

    switch (genderChoice) {
    case 1:
      strcpy(b.gender, "Male");
      break;
    case 2:
      strcpy(b.gender, "Female");
      break;
    default:
      printf("Enter valid choice\n");
    }
  } while (genderChoice != 1 && genderChoice != 2);

  // address
  getchar();
  printf("Enter Address: ");
  fgets(address, MAX, stdin);
  address[strlen(address) - 1] = '\0';
  strcpy(b.Address, address);

  // city
  do {
    printf("Enter City: ");
    fgets(city, MAX, stdin);
    city[strlen(city) - 1] = '\0';
    if (isValidCity(city)) {
      flagCity = 1;
      strcpy(b.city, city);
    } else {
      flagCity = 0;
    }
  } while (flagCity != 1);

  // DOB
  do {
    printf("Enter Date of Birth(dd/mm/yyyy): ");
    fgets(dob, MAX, stdin);
    dob[strlen(dob) - 1] = '\0';
    if (isValidDOB(dob)) {
      flagDob = 1;
      strcpy(b.DOB, dob);
    } else {
      flagDob = 0;
    }
  } while (flagDob != 1);
  // type of account

  // do {
  //   printf("Account type\n1.Saving\n2.Current");
  //   printf("\nEnter your choice: ");
  //   // if (scanf("%d",&accountTypeChoice) != 1) {
  //   //   getchar();
  //   //   continue;
  //   // }
  //   scanf("%d", &accountTypeChoice);
  //   switch (accountTypeChoice) {
  //   case 1:
  //     strcpy(b.typeOfAccount, "Saving");
  //     break;
  //   case 2:
  //     strcpy(b.typeOfAccount, "Current");
  //     break;
  //   default:
  //     printf("Enter valid choice\n");
  //     getchar();
  //   }
  // } while (accountTypeChoice != 1 && accountTypeChoice != 2);
  while (1) {
    char ch[3];
    printf("Account type\nS for Saving\nC for Current\n");
    printf("Enter your choice: ");
    scanf("%s", ch);
    if ((strcmp(ch, "S") == 0) || (strcmp(ch, "C") == 0)) {
      if (strcmp(ch, "S") == 0) {
        strcpy(b.typeOfAccount, "Saving");
      }
      if (strcmp(ch, "C") == 0) {
        strcpy(b.typeOfAccount, "Current");
      }

      break;
    }

    else
      continue;
  }
  // balance
  // double bal;
  // printf("Enter Balance: ");
  // scanf("%lf", &b.balance);
  b.balance = 0;
  getchar();

  // Pan Card
  do {

    printf("Enter Pan Card Number: ");
    fgets(panCard, MAX, stdin);
    panCard[strlen(panCard) - 1] = '\0';
    if (isValidPan(panCard)) {

      flagPanCard = 1;
      strcpy(b.panCardNumber, panCard);
    } else {
      flagPanCard = 0;
    }
  } while (flagPanCard != 1);

  // aadhar card
  do {

    printf("Enter Aadhar Card Number: ");
    fgets(aadharCard, MAX, stdin);
    aadharCard[strlen(aadharCard) - 1] = '\0';
    if (isValidAadhar(aadharCard)) {
      flagAadhar = 1;

      strcpy(b.aadharCardNumber, aadharCard);
    } else {
      flagAadhar = 0;
    }
  } while (flagAadhar != 1);

  printf("\nAccount Created Successfully\n");
  printf("Your Account Number is: %s\n", b.accountNumber);
  return b;
}

void displayAccountInfo(Bank b) {
  printf("\n");
  printf("Bank Name      : %s\n", b.bankName);
  printf("IFSC Code      : %s\n", b.IFSCCode);
  printf("Account Number : %s\n", b.accountNumber);
  printf("Name           : %s\n", b.accountHolderName);
  printf("Age            : %d\n", b.age);
  printf("Gender         : %s\n", b.gender);
  printf("Date of Birth  : %s\n", b.DOB);
  printf("Address        : %s\n", b.Address);
  printf("City           : %s\n", b.city);
  printf("Type of Account: %s\n", b.typeOfAccount);
  printf("Balance        : %.2lf\n", b.balance);
  printf("Pan Card Number: %s\n", b.panCardNumber);
  printf("Aadhar Card Number: %s\n", b.aadharCardNumber);
  printf("-------------------------------------\n");
}

void displayAccounts(Bank b[], int index) {
  for (int i = 0; i < index; i++) {
    displayAccountInfo(b[i]);
  }
}

void deposit(char accountNumber[], double amount, Bank b[], int index) {
  if (amount <= 0) {
    printf("\nAmount Should not be Zero or negative");
    return;
  }
  for (int i = 0; i < index; i++) {
    if (strcmp(b[i].accountNumber, accountNumber) == 0) {
      b[i].balance += amount;
      printf("\nAmount deposited successfully\n");
      return;
    }
  }
  printf("\nAccount not found\n");
}

void withdraw(char accountNumber[], double amount, Bank b[], int index) {
  if (amount <= 0) {
    printf("\nAmount Should not be Zero or negative");
    return;
  }
  for (int i = 0; i < index; i++) {
    if (strcmp(b[i].accountNumber, accountNumber) == 0) {
      if (b[i].balance >= amount) {
        b[i].balance -= amount;
        printf("\nAmount withdrawn successfully\n");
        return;
      } else {
        printf("\nInsufficient balance\n");
        return;
      }
    }
  }
  printf("Account not found\n");
}
void balanceEnquiry(char accountNumber[], Bank b[], int index) {
  for (int i = 0; i < index; i++) {
    if (strcmp(b[i].accountNumber, accountNumber) == 0) {
      printf("\nAccount Number: %s\n", b[i].accountNumber);
      printf("Account Holder Name: %s\n", b[i].accountHolderName);
      printf("Balance: %.2lf\n", b[i].balance);
      return;
    }
  }
  printf("\nAccount not found\n");
}

void fundTransfer(char senderAccountNumber[], char receiverAccountNumber[],
                  double amount, Bank b[], int index) {
  int senderFound = 0, receiverFound = 0;
  int senderIndex, receiverIndex;
  if (strcmp(senderAccountNumber, receiverAccountNumber) == 0) {
    printf("Sender and receiver account number cannot be same");
  }
  for (int i = 0; i < index; i++) {
    if (strcmp(b[i].accountNumber, senderAccountNumber) == 0) {
      senderFound = 1;
      senderIndex = i;
    }
    if (strcmp(b[i].accountNumber, receiverAccountNumber) == 0) {
      receiverFound = 1;
      receiverIndex = i;
    }
  }
  if (senderFound && receiverFound) {
    if (b[senderIndex].balance >= amount) {
      b[senderIndex].balance -= amount;
      b[receiverIndex].balance += amount;
      printf("\nFund transfer successful\n");
    } else {
      printf("\nInsufficient balance in sender's account\n");
    }
  }
  if (senderFound == 0) {
    printf("\nYour account not found\n");
  }
  if (receiverFound == 0) {
    printf("\nReceiver's account not found\n");
  }
}

void updateAccountHolderName(Bank b[], int indexOfAccount, char newName[]) {
  strcpy(b[indexOfAccount].accountHolderName, newName);
  printf("\nAccount holder name updated successfully\n");
}
void updateAccountHolderAddress(Bank b[], int indexOfAccount,
                                char newAddress[]) {
  strcpy(b[indexOfAccount].Address, newAddress);
  printf("\nAccount holder address updated successfully\n");
}
void updateAccountHolderDOB(Bank b[], int indexOfAccount, char newDOB[]) {
  strcpy(b[indexOfAccount].DOB, newDOB);
  printf("\nAccount holder DOB updated successfully\n");
}
void updateAccountDetails(char accountNumber[], Bank b[], int index) {
  bool flag = false;
  for (int i = 0; i < index; i++) {
    if (strcmp(b[i].accountNumber, accountNumber) == 0) {
      flag = true;
      printf("\n What do you want to update?\n");
      printf("1. Account Holder Name\n");
      printf("2. Address\n");
      printf("3. DOB\n");
      int choice;
      printf("Enter your choice: ");
      scanf("%d", &choice);
      getchar();
      switch (choice) {
      case 1: {
        char newName[MAX];
        do {
          printf("Enter new account holder name: ");
          fgets(newName, MAX, stdin);
          newName[strlen(newName) - 1] = '\0';
        } while (!isValidName(newName));

        updateAccountHolderName(b, i, newName);
        break;
      }
      case 2: {
        char newAddress[MAX];
        printf("Enter new address: ");
        fgets(newAddress, MAX, stdin);
        newAddress[strlen(newAddress) - 1] = '\0';
        updateAccountHolderAddress(b, i, newAddress);
        break;
      }
      case 3: {
        char newDOB[MAX];
        do {
          printf("Enter new DOB: ");
          fgets(newDOB, MAX, stdin);
          newDOB[strlen(newDOB) - 1] = '\0';
        } while (!isValidDOB(newDOB));
        updateAccountHolderDOB(b, i, newDOB);
        break;
      }
      default:
        printf("\nInvalid choice\n");
      }
    }
  }
  if (flag == false) {
    printf("\nAccount not found\n");
  }
}
void searchByAccountNumber(char accountNumber[], Bank b[], int index) {
  for (int i = 0; i < index; i++) {
    if (strcmp(b[i].accountNumber, accountNumber) == 0) {
      displayAccountInfo(b[i]);
      return;
    }
  }
  printf("\nAccount not found\n");
}

void searchByName(char accountHolderName[], Bank b[], int index) {
  bool flag = false;
  for (int i = 0; i < index; i++) {
    if (strcmp(b[i].accountHolderName, accountHolderName) == 0) {
      displayAccountInfo(b[i]);
      flag = true;
    }
  }
  if (!flag) {
    printf("\nAccount not found\n");
  }
}

void searchByType(char typeOfAccount[], Bank b[], int index) {
  bool flag = false;
  for (int i = 0; i < index; i++) {
    if (strcmp(b[i].typeOfAccount, typeOfAccount) == 0) {
      displayAccountInfo(b[i]);
      flag = true;
    }
    if (!flag) {
      printf("\nAccount not found\n");
    }
  }
}
void search(Bank b[], int index) {
  getchar();
  int choice;
  printf("\nSearch by:\n1.Account Number\n2.Account Holder Name\n3.Type Of "
         "Account");
  printf("\nEnter your choice: ");
  scanf("%d", &choice);
  getchar();
  switch (choice) {
  case 1: {
    printf("Enter Account Number: ");
    char accountNumber[MAX];
    scanf("%s", accountNumber);
    searchByAccountNumber(accountNumber, b, index);
    break;
  }
  case 2: {

    printf("Enter Account Holder Name: ");
    char accountName[MAX];
    fgets(accountName, MAX, stdin);
    accountName[strlen(accountName) - 1] = '\0';
    searchByName(accountName, b, index);
    break;
  }
  case 3: {
    printf("Enter Type Of Account: ");
    char typeOfAccount[MAX];
    scanf("%s", typeOfAccount);
    searchByType(typeOfAccount, b, index);
    break;
  }
  default:
    printf("Invalid choice");
  }
}

int main(void) {
  int size;
  printf("How Many Accounts You Want To Create: ");
  scanf("%d", &size);
  Bank accounts[size];
  int index = 0, choice;

  do {

    printf("\nMENU\n1.Create Account\n2.Update Account "
           "Details\n3.Deposit\n4.Withdraw\n5.Fund Transfer\n6.Search "
           "Detail\n7.Balance Enquiry\n8.Display All Accounts\n9.Exit\n");
    printf("Enter Your Choice: ");
    int status = scanf("%d", &choice);
    if (status != 1) {
      printf("\nInvalid choice\n");
      getchar();
      continue;
    }
    switch (choice) {
    case 1: {
      accounts[index] = createAccount();
      index++;
      break;
    }
    case 2: {
      char accountNumber[MAX];
      printf("Enter Account Number: ");
      scanf("%s", accountNumber);
      updateAccountDetails(accountNumber, accounts, index);
      break;
    }
    case 3: {
      char accNo[MAX];
      printf("Enter Account Number: ");
      scanf("%s", accNo);
      double amount;
      printf("Enter Amount: ");
      int status = scanf("%lf", &amount);
      if (status == 1) {
        deposit(accNo, amount, accounts, index);
      } else {
        printf("\nInvalid Amount\n");
        getchar();
      }
      break;
    }
    case 4: {
      char accNo[MAX];
      printf("Enter Account Number: ");
      scanf("%s", accNo);
      double amount;
      printf("Enter Amount: ");
      int status = scanf("%lf", &amount);
      if (status == 1) {
        withdraw(accNo, amount, accounts, index);
      } else {
        printf("\nInvalid Amount\n");
      }
      break;
    }
    case 5: {
      char senderAccNo[MAX];
      char receiverAccNo[MAX];
      double amount;
      printf("Enter Your Account Number: ");
      scanf("%s", senderAccNo);
      printf("Enter Receiver's Account Number: ");
      scanf("%s", receiverAccNo);
      printf("Enter Amount: ");
      int status = scanf("%lf", &amount);
      if (status == 1) {
        fundTransfer(senderAccNo, receiverAccNo, amount, accounts, index);
      } else {
        printf("\nInvalid Amount\n");
      }
      break;
    }
    case 6: {
      search(accounts, index);
      break;
    }
    case 7: {
      char accNo[MAX];
      printf("Enter Account Number: ");
      scanf("%s", accNo);
      balanceEnquiry(accNo, accounts, index);
      break;
    }
    case 8: {
      displayAccounts(accounts, index);

      break;
    }
    case 9: {
      printf("Thank You");
      break;
    }
    default:
      printf("\nInvalid choice\n");
    }
  } while (choice != 9);

  return 0;
}
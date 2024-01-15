#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool isValidPan(char *pan) {
  if (strlen(pan) != 10) {
    return false;
  }

  for (int i = 0; i < strlen(pan); i++) {
    if (i < 5) {
      if (!isupper(pan[i])) {
        return false;
      }
    }
    if (i >= 5 && i != 9) {
      if (!isdigit(pan[i])) {
        return false;
      }
    }
    if (!isupper(pan[9])) {
      return false;
    }
  }
  return true;
}

bool isValidAadhar(char aadhar[]) {

  if (strlen(aadhar) != 12) {
    return false;
  }
  for (int i = 0; i < strlen(aadhar); i++) {
    if (!isdigit(aadhar[i])) {
      return false;
    }
  }
  return true;
}
bool isValidAge(int age) {
  if (age < 1 || age > 100) {
    return false;
  }
  return true;
}

bool isValidName(char name[]) {
  for (int i = 0; i < strlen(name); i++) {
    if (isalpha(name[i]) == 0 && name[i] != ' ') {
      return false;
    }
  }
  char temp[50];
  strcpy(temp, name);
  char *token = strtok(temp, " ");
  int count = 0;
  while (token != NULL) {

    count++;
    token = strtok(NULL, " ");
  }
  if (count != 3) {
    return false;
  }
  return true;
}

bool isValidCity(char city[]) {
  for (int i = 0; i < strlen(city); i++) {
    if (isdigit(city[i])) {
      return false;
    }
  }
  return true;
}

bool isValidDOB(char dob[]) {
  int day, month, year;
  if (sscanf(dob, "%d/%d/%d", &day, &month, &year) != 3) {
    return false;
  }
  if (year < 1900 || year > 2023 || month < 1 || month > 12 || day < 1 ||
      day > 31) {
    return false;
  }
  return true;
}
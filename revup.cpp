#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>

std::string intended_use{"cheese"};
double requested_loan_amt{2000001};
bool non_profit_business{false};

void get_input(int argc, char **argv) {
  if (argc == 1) {
    intended_use = "debt";
    requested_loan_amt = 200.0;
    non_profit_business = true;
  } else if (argc == 4) {
    // The first CLI parameter is the intended use for the loan.
    intended_use = argv[1];

    // NB: No error checking is done here. User must be careful to only
    // pass valid numbers!
    requested_loan_amt = static_cast<double>(atoi(argv[2]));

    // The final CLI parameter is whether the applicant's business is
    // a non-profit. If the parameter is "true", then the business is
    // a non-profit.
    if (!strcmp("true", argv[3])) {
      non_profit_business = true;
    }
  } else {
    exit(EXIT_FAILURE);
  }
}

void print_horizontal_line(int columns) {
  auto flags = std::cout.flags();
  auto fill = std::cout.fill();
  std::cout << std::setfill('=') << std::setw(columns) << ""
            << "\n";
  std::cout.flags(flags);
  std::cout.fill(fill);
}

std::string format_money(double money) {
  std::stringstream formatted_money{};
  formatted_money << std::fixed << std::setprecision(2) << std::showpoint;
  formatted_money << "$" << money;
  return formatted_money.str();
}

std::string format_percentage(double percentage) {
  std::stringstream formatted_percentage{};
  formatted_percentage << std::fixed << std::setprecision(2) << std::showpoint;
  formatted_percentage << percentage << "%";
  return formatted_percentage.str();
}

std::string bool_to_yes_no(bool value) {
  std::string yes_no{""};
  if (value) {
    yes_no = std::string{"Yes"};
  } else {
    yes_no = std::string{"No"};
  }
  return yes_no;
}

void print_labeled_value(const std::string &label, int label_width,
                         const std::string &value, int value_width) {
  auto flags = std::cout.flags();
  auto fill = std::cout.fill();
  std::cout << std::setfill(' ') << std::left << std::setw(label_width) << label
            << std::right << std::setw(value_width) << value << "\n";
  std::cout.flags(flags);
  std::cout.fill(fill);
}

/*
 * This main fuction determines if the business owner is eligible for the loan, 
 * interest rate, application fee, if there's collateral needed, and if there's a 
 * personal guaranty required. Then it formats and prints the eligibility status, 
 * interest rate, application fee, collateral required, and personal guaranty. a.	
 * If they are not eligible, it just prints the eligibility status
 */

int main(int argc, char **argv) {
  get_input(argc, argv);
  const double NON_PROFIT_INTEREST_RATE = 2.75;
  const double PROFIT_INTEREST_RATE = 3.75;
  const double NO_APP_FEE = 0;
  const double APP_FEE = 100;
  double interestRate = 0;
  double applicationFee = 0;
  bool collateral = false;
  bool status = false;
  bool personalGuaranty = false;

 

  if ((intended_use == "payroll" || intended_use == "rent" ||
      intended_use == "mortgage" || intended_use == "utilities" ||
       intended_use == "ordinary business expenses" || intended_use == "debt") &&
      (requested_loan_amt <= 2000000)) {
        status = true;
    if (non_profit_business) {
       interestRate = NON_PROFIT_INTEREST_RATE;
    } else {
       interestRate = PROFIT_INTEREST_RATE;
    }
    if (requested_loan_amt <= 25000) {
       applicationFee = NO_APP_FEE;
       collateral = false;
       personalGuaranty = false;
    } else if (requested_loan_amt > 200000) {
       applicationFee = APP_FEE;
       collateral = true;
       personalGuaranty = true;
    } else {
       applicationFee = APP_FEE;
       collateral = true;
       personalGuaranty = false;
    }
    print_horizontal_line(80);
    print_labeled_value("Eligibility Status:  ", 75, bool_to_yes_no(status), 5);
    print_labeled_value("Interest Rate: ", 75, format_percentage(interestRate),5);
    print_labeled_value("Application Fee: ", 73, format_money(applicationFee),7);
    print_labeled_value("Collateral Required: ", 77,bool_to_yes_no(collateral), 3);
    print_labeled_value("Personal Guaranty: ", 77,bool_to_yes_no(personalGuaranty), 3);
    print_horizontal_line(80);
  } else {
      status = false;
      print_horizontal_line(80);
      print_labeled_value("Eligibility Status:  ", 77, bool_to_yes_no(status), 3);
      print_horizontal_line(80);
  }


  // Complete the implementation of main according to the specifications in the
  // lab document! Do not remove any code that exists. Simply add additional
  // code to meet the description of RevUp's operation.

  return 0;
}

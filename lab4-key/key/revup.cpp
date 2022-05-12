#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string.h>

std::string intended_use{""};
double requested_loan_amt{0.0};
bool non_profit_business{false};

void get_input(int argc, char **argv) {

  // This is here only for *super* extra sanity checking.
  // We have to be extra defensive here because the student
  // may have updated the initial values of the global
  // variables for testing.
  intended_use = "";
  requested_loan_amt = 0.0;
  non_profit_business = false;

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
    // a non-profit. Make sure to set the variable to "false" in the
    // else case because students may have reset the initial value
    // of the global variables during testing.
    if (!strcmp("true", argv[3])) {
      non_profit_business = true;
    } else {
      non_profit_business = false;
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

const int MAXIMUM_LOAN_CUTOFF{2000000};
const float NONPROFIT_INTEREST_RATE{2.75};
const float FORPROFIT_INTEREST_RATE{3.75};
const int FEE_COLLATERAL_CUTOFF{25000};
const int PERSONAL_GUARANTY_CUTOFF{200000};

/*
 * This program calculates whether a business with the given
 * characteristics meets the SBA's criteria for funding to 
 * support their operations during the pandemic.
 */
int main(int argc, char **argv) {
  get_input(argc, argv);

  bool is_eligible{false};
  double interest_rate{0.0};
  double application_fee{0.0};
  bool collateral{false};
  bool personal_guaranty{false};

  if ((intended_use == "payroll" || intended_use == "rent" ||
       intended_use == "mortgage" || intended_use == "utilities" ||
       intended_use == "debt" ||
       intended_use == "ordinary business expenses") &&
      requested_loan_amt <= MAXIMUM_LOAN_CUTOFF) {
    is_eligible = true;
  }

  if (non_profit_business) {
    interest_rate = NONPROFIT_INTEREST_RATE;
  } else {
    interest_rate = FORPROFIT_INTEREST_RATE;
  }

  if (requested_loan_amt > FEE_COLLATERAL_CUTOFF) {
    application_fee = 100.00;
    collateral = true;
  }

  if (requested_loan_amt > PERSONAL_GUARANTY_CUTOFF) {
    personal_guaranty = true;
  }

  print_horizontal_line(80);
  print_labeled_value("Eligibility Status:", 40, bool_to_yes_no(is_eligible),
                      40);
  if (is_eligible) {
    print_labeled_value("Interest Rate:", 40, format_percentage(interest_rate),
                        40);
    print_labeled_value("Application Fee:", 40, format_money(application_fee),
                        40);
    print_labeled_value("Collateral Required:", 40, bool_to_yes_no(collateral),
                        40);
    print_labeled_value("Personal Guaranty:", 40,
                        bool_to_yes_no(personal_guaranty), 40);
  }
  print_horizontal_line(80);
  return 0;
}

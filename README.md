# Pandemic-Small-Business-Support
CS1021 Lab 4

## Introduction
In addition to the tremendous public health toll that the SARS CoV-2 pandemic ("pandemic") has taken on the world, the steps that officials have taken to stop its spread have caused a tremendous amount of problems for the economy. In particular, [small businesses have been greatly affected](https://www.pnas.org/doi/10.1073/pnas.2006991117). The United States government recognized this problem quickly and extended support to these businesses through the [Small Business Association](https://www.sba.gov/)'s (SBA's) [Economic Injury Disaster Loa](https://www.sba.gov/funding-programs/loans/covid-19-relief-options/covid-19-economic-injury-disaster-loan/about-covid-19-eidl) (EIDL, pronounced "idle") program. This program supports small businesses with low-interest loans for up to $2 million to pay for things like rent, payroll, previously incurred debt and other business expenses.

Not every small business is eligible for this support (e.g., [pawn shops cannot apply!](https://www.history.com/shows/pawn-stars)), the money can only be used for approved purposes, and the terms of support are not the same for every applicant. In other words, the amount of support from this program is dependent on the circumstances of the business applying for support and the rules are quite complicated. The conditions for receiving EIDL support that we are using in this lab are based on the actual parameters of the program as [published](https://www.sba.gov/sites/default/files/2021-09/COVID-EIDL-FAQs-090821-508.pdf) by the SBA.

In order to help applicants, you are going to create the *RevUp* application. *RevUp* will a) inform owners of small businesses whether they are eligible for the program and b) calculate the terms of the support they can expect from the government. *RevUp* will first calculate whether the applicant is eligible for the program based the size of their loan request and their stated use for the funds. If they are eligible for EIDL support, *RevUp* will calculate the following information for the applicant:
- The interest rate for their loan
- The fees associated with their application
- Whether collateral is required
- Whether a personal guaranty is required

To be eligible, the business owner can ask to borrow as much as $2 million and plan to deploy that funding for
- rent/mortgage,
- payroll,
- business expenses,
- utilities, or
- debt.
If the business is eligible, then the loan's interest rate is
- 3.75% if the business is a for-profit entity, or
- 2.75% if the business is a non-profit entity.

For loans of $25,000 or less, there is no fee for applying. If the loan is for more than $25,000, there is a one-time $100 fee.

For loans of more than $25,000, collateral is required. For loans of more than $200,000, a personal guaranty is required.

## Program Design Task
As my dad always said, “If I cut down a tree in the forest at least I can hear it fall.” Before you start writing code, please write the pseudocode or draw a flow chart for your implementation of the *RevUp* application.

## Program Design Requirements
Your pseudocode or flow chart must describe the entirety of the solution. You may choose to write the flow chart or the pseudocode at any level of detail but remember that this is a tool for you! Your pseudocode or flow chart must include a description of how you plan to determine

Whether the applicant is eligible, based on the size of their request and the way they propose to use the funds,
- The applicant's interest rate,
- Whether the applicant has to pay a fee to apply,
- Whether collateral is required, and
- Whether a personal guaranty is required.

## Programming Task
Your programming task is to implement the *RevUp* application and document the implementation of a single supporting function. In this lab you will not prompt the user for input. Input will be provided for you *automatically* by the skeleton code attached to this assignment (see below). Like Lab 3, you must use the skeleton.

In the main function where you will do your implementation, the following three (3) variables will be in scope:
1. `intended_use`: a `std::string` that will contain the user's intended use for the funds.
2. `requested_loan_amt`: a `double` that will contain the user's requested loan amount.
3. `non_profit_business`: a `bool` that will be set to `true` if the user is applying on behalf of a non-profit entity; it will be set to `false` otherwise.

String literals
- "payroll"
- "rent"
- "mortgage"
- "utilities"
- "debt"
- "ordinary business expenses"

are the only valid intended uses of the money. If `intended_use` matches one of those values, the use is valid. If `intended_use` does not match one of those values, the applicant is ineligible.

If `requested_loan_amt` is less than or equal to $2 million and the applicant's intended use for the funds is valid, the applicant is eligible.

If `non_profit_business` is true, the applicant's interest rate is 2.75%. Otherwise, the applicant's interest rate is 3.75%.

If `requested_loan_amt` is greater than $25,000, the applicant's fee for applying is $100. Otherwise, the applicant's fee for applying is $0.00.

If `requested_loan_am`t is greater than $25,000, the applicant is required to provide collateral. Otherwise, the applicant is not required to provide collateral.

If `requested_loan_amt` is greater than $200,000, the applicant is required to provide a personal guaranty. Otherwise, the applicant is not required to provide a personal guaranty. 

For example, if the applicant runs a non-profit business and is asking for $200 for debt repayment, RevUp will output

```
================================================================================
Eligibility Status:                                                          Yes
Interest Rate:                                                             2.75%
Application Fee:                                                           $0.00
Collateral Required:                                                          No
Personal Guaranty:                                                            No
================================================================================
```

If the applicant runs a for-profit business and is asking for $2000001 for debt repayment, RevUp will output

```
================================================================================
Eligibility Status:                                                           No
================================================================================
```

*Note:* Your program will be tested against other test cases. Your program must compute properly in all cases in order to receive full points! Check the output of the autograder to make sure that your program behaves as expected. Read the autograder's output carefully!

## Programming Requirements
If you are a Windows user, begin with the skeleton code in this repository. This skeleton provides the functions you will need to use to successfully complete this lab. If you do not use this skeleton code you will not be able to complete this lab.

Because the input for the program is provided by the skeleton code, the only requirements are that you meet certain conditions for output. Code that produces properly formatted output has been provided for you:

- `print_horizontal_line`: Has a single parameter (an `int`) that controls the length of the printed horizontal line.
- `format_money`: Has a single parameter (a `double`) that represents a monetary value. The function returns a `std::string` of the monetary value prefixed with the dollar sign.
- `format_percentage`: Has a single parameter (a `double`) that represents a percentage. The function returns a `std::string` of the percentage prefixed with the percent sign.
- `print_labeled_value`: Has four parameters; a label, a label width, a value and a value width (`std::string`, `int`, `std::string`, and `int`, respectively) that define how the label and the value are formatted when they are printed to the screen. The function will print the label in a minimum of the width specified (left aligned) and print the value in a minimum of the width specified (right aligned).
- 
For an eligible applicant, your output must match this template:

```
================================================================================
Eligibility Status:                                                     <Yes/No>
Interest Rate:                                                      <2.75/3.75>%
Application Fee:                                                  $<100.00/0.00>
Collateral Required:                                                    <Yes/No>
Personal Guaranty:                                                      <Yes/No>
================================================================================
```

where each line is exactly 80 columns wide.

For an ineligible applicant, your output must match exactly this:

```
================================================================================
Eligibility Status:                                                           No
================================================================================
```

Besides generating the appropriate output depending on the input, you must also add comments explaining the operation of the the implementation of the `bool_to_yes_no` function. The `bool_to_yes_no function` has a single parameter (a `bool`) and returns a `std::string` whose value is "Yes" if the parameter is `true` and returns a `std::string` whose value is "No", otherwise. You must use a multiline/block comment above bool_to_yes_no that states what the function does, the parameter that it accepts (its meaning and its type) and the return value (its meaning and its type). You must use singleline comments throughout the function to explain its operation.

Your code must have the following characteristics:
1. You may not use any "magic" numbers -- all numeric values defined in this lab document and used in your code must be manipulated as properly typed constants. For example, the only time that the floating-point literal `2.75` should appear in your code is during an assignment to a constant variable whose type is a double, as in `const double NON_PROFIT_INTEREST_RATE = 2.75;`
2. Blocks of code associated with if or else conditions must be enclosed in {}s. 

## Critical Thinking Task
*Matryoshka dolls* are the technical term for what are commonly referred to as stacking dolls. [According to Wikipedia](https://en.wikipedia.org/wiki/Matryoshka_doll), these dolls were first made in the 1890s. An incredibly small, wooden doll is placed inside a series of larger and larger wooden dolls -- together these dolls form a set. Every doll in the set, no matter the size, is painted to look the same. This property of self-similarity makes them like a real-world [fractal](https://en.wikipedia.org/wiki/Fractal)! Here are some pictures to give you a sense for what they look like:

800px-Floral_matryoshka_set_2_smallest_doll_nested.JPG	messages_0.jpeg	messages_0(1).jpeg
The Matryoshka dolls are also referred to as nesting dolls. Smaller dolls are nested inside larger dolls. This past week we learned about a concept in C++ that relies on nesting. In this critical thinking component, you will describe how a teacher could use Matryoshka dolls to teach that concept.

## Critical Thinking Requirement
There are at least two different aspects of C++ that include concepts of nesting. You must write a brief (less than 200 words) lesson plan for how you would use Matryoshka in a classroom to teach one of those concepts to students learning the C++ language. Your lesson plan must include a technical description of how the nesting operates in the C++ language and how it relates (physically) to the dolls.

## Deliverables
1. The pseudocode describing the algorithm of your RevUp program in PDF format (named `design.pdf`).
2. The C++ source code for your RevUp application (named `revup.cpp`).
3. A written response to the Critical Thinking Task prompt in PDF format (named `dolls.pdf`).

## Related Learning Objectives
1. Writing boolean expressions using relational and logical operators
2. Using if-statements to implement selective program execution
3. Recognizing self-similarity/nesting in parts of C++
4. Comparing strings and numbers using relational operations
5. Using pre-defined functionality through function calls

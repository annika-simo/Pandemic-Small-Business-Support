### Pandemic Small Business Support Pseudocode

1. Initialize a set of variables where I will store the calculated attributes of the loan determination:

	1. `eligibility`: Initialize to false;
	2. `interest_rate`: Initialize to 0.0;
	3. `application_fee`: Initialize to 0.0;
	4. `collateral`: Initialize to false; and
	5. `personal_guaranty`: Initialize to false.

2. Use the criteria from the SBA to determine whether the applicant is eligible for a loan (i.e., they are using it for its intended purposes _and_ they are requesting an amount less than $2m USD.)
	1. If they are eligible, set `eligibility` to true; otherwise,
	2. do nothing because `eligibility` defaults to false.

3. Use the criteria to determine the applicant's interest rate:
	1. If the applicant is a non-profit business, set their `interest_rate` to 2.75; otherwise, 
	2. Set their `interest_rate` to 3.75.

4. Use the criteria to determine whether the applicant must put down collateral:
	1. If the applicant is requesting more than $250k USD, set their `collateral` requirement to true, 
	2. do nothing because `collateral` defaults to false.

5. Use the criteria to determine whether the applicant must make a personal guaranty:
	1. If the applicant is requesting more than $200k USD, set their `personal_guaranty` requirement to true, 
	2. do nothing because `personal_guaranty` defaults to false.

6. Use the given functions to output the preceding calculations according to the specifications. 
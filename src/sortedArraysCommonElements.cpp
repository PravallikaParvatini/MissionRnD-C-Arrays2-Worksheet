/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int y_a, y_b, m_a, m_b, d_a, d_b,i=0,j=0,k=0;
	struct transaction *final=NULL;
	if (A == NULL || ALen <= 0 | B == NULL || BLen <= 0)
		return NULL;
	while (i < ALen)
	{
		y_a = (A[i].date[6] - '0') * 1000 + (A[i].date[7] - '0') * 100 + (A[i].date[8] - '0') * 10 + (A[i].date[9] - '0');
		m_a = (A[i].date[3] - '0') * 10 + (A[i].date[4] - '0');
		d_a = (A[i].date[0] - '0') * 10 + (A[i].date[1] - '0');
		while (j < BLen)
		{
			y_b = (B[i].date[6] - '0') * 1000 + (B[i].date[7] - '0') * 100 + (B[i].date[8] - '0') * 10 + (B[i].date[9] - '0');
			m_b = (B[i].date[3] - '0') * 10 + (B[i].date[4] - '0');
			d_b = (B[i].date[0] - '0') * 10 + (B[i].date[1] - '0');
			if (y_a == y_b&&m_a == m_b&&d_a == d_b)
			{
				final = (struct transaction*)realloc(final, (k + 1)*sizeof(struct transaction));
				final[k] = B[j];
				j++;
				k++;
			}
			else
				j++;
		}
		i++;
	}
	if (final == NULL)
		return NULL;
	else
		return final;
}
/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int y1, y2, m1, m2, d1, d2, i = ALen + BLen - 1;
	if ((A == NULL || B == NULL) || ALen < 0 || BLen < 0)
		return NULL;
	struct transaction *result; 
	result = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
	while (ALen > 0 && BLen > 0)
	{
		y1 = (A[ALen - 1].date[6] - '0') * 1000 + (A[ALen - 1].date[7] - '0') * 100 + (A[ALen - 1].date[8] - '0') * 10 + (A[ALen - 1].date[9] - '0');
		y2 = (B[BLen - 1].date[6] - '0') * 1000 + (B[BLen - 1].date[7] - '0') * 100 + (B[BLen - 1].date[8] - '0') * 10 + (B[BLen - 1].date[9] - '0');
		if (y1 > y2)
		{
			result[i] = A[ALen - 1];
			i--;
			ALen--;
		}
		if (y2 > y1)
		{
			result[i] = B[BLen - 1];
			i--;
			BLen--;
		}
		if (y1 == y2)
		{
			m1 = (A[ALen - 1].date[3] - '0') * 10 + (A[ALen - 1].date[4] - '0');
			m2 = (B[BLen - 1].date[3] - '0') * 10 + (B[BLen - 1].date[4] - '0');
			if (m1 > m2)
			{
				result[i] = A[ALen - 1];
				i--;
				ALen--;
			}
			if (m2 > m1)
			{
				result[i] = B[BLen - 1];
				i--;
				BLen--;
			}
			if (m1 == m2)
			{
				d1 = (A[ALen - 1].date[0] - '0') * 10 +(A[ALen - 1].date[1]-'0');
				d2 = (B[BLen - 1].date[0] - '0') * 10 + (B[BLen - 1].date[1]-'0');
				if (d1 > d2)
				{
					result[i] = A[ALen - 1];
					i--;
					ALen--;
				}
				if (d2 > d1)
				{
					result[i] = B[BLen - 1];
					i--;
					BLen--;
				}
				if (d1 == d2)
				{
					result[i] = A[ALen - 1];
					i--;
					ALen--;
					result[i] = B[BLen - 1];
					i--;
					BLen--;
				}
			}
		}
	}
	while (ALen > 0)
	{
		result[i] = A[ALen - 1];
		i--;
		ALen--;
	}
	while (BLen > 0)
	{
		result[i] = B[ BLen - 1]; 
		i--;
		BLen--;
	}
	return result;
}
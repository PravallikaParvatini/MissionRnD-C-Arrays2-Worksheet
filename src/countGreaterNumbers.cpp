/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int y_d, y_a, m_d, m_a, d, d1, i = 0, j, count = 0;
	if (len <= 0 || Arr == NULL || date == NULL)
		return NULL;
	y_d = (date[6]-'0') * 1000 + (date[7]-'0') * 100 + (date[8]-'0') * 10 + (date[9]-'0');
	m_d = (date[3]-'0') * 10 + (date[4]-'0');
	d = (date[0]-'0') * 10 + (date[1]-'0');
	while (i < len)
	{
		y_a = (Arr[i].date[6]-'0') * 1000 + (Arr[i].date[7]-'0') * 100 + (Arr[i].date[8]-'0') * 10 + (Arr[i].date[9]-'0');
		m_a = (Arr[i].date[3]-'0') * 10 + (Arr[i].date[4]-'0');
		d1 = (Arr[i].date[0]-'0') * 10 + (Arr[i].date[1]-'0');
		if (y_d == y_a)
		{
			if (m_d == m_a)
			{
				if (d == d1)
				{
					j = i + 1;
					while (j < len)
					{
						y_a = (Arr[j].date[6] - '0') * 1000 + (Arr[j].date[7] - '0') * 100 + (Arr[j].date[8] - '0') * 10 + (Arr[j].date[9] - '0');
						m_a = (Arr[j].date[3] - '0') * 10 + (Arr[j].date[4] - '0');
						d1 = (Arr[j].date[0] - '0') * 10 + (Arr[j].date[1] - '0');
						if (y_a > y_d)
							count++;
						j++;
					}
				}
			}
		}
		if (count == len - i - 1)
			return (len - i - 1);
		else
			i++;
	}
}

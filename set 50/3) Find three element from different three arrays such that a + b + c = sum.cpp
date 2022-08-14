/*
Given three arrays. 
Find all the pairs from the two arrays such that the sum of those elements is 
in the third array.

Input : a1[] = { 1 , 2 , 3 , 4 , 5 };
    a2[] = { 2 , 3 , 6 , 1 , 2 };
    a3[] = { 3 , 2 , 4 , 5 , 6 };  
        sum = 9
Output : Yes
1  + 2  + 6 = 9  here 1 from a1[] and 2 from
a2[] and 6 from a3[]   
    
Input : a1[] = { 1 , 2 , 3 , 4 , 5 };
    a2[] = { 2 , 3 , 6 , 1 , 2 };
    a3[] = { 3 , 2 , 4 , 5 , 6 };   
         sum = 20 
Output : No 
*/

#include<bits/stdc++.h>
using namespace std;
bool findTriplet(int a1[], int a2[],
				int a3[], int n1,
				int n2, int n3,
				int sum)
{
	unordered_set <int> s;
	for (int i = 0; i < n1; i++)
		s.insert(a1[i]);


	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n3; j++)
		{
			if (s.find(sum - a2[i] - a3[j]) !=
									s.end())
				return true;
		}
	}

	return false;
}

// Driver Code
int main()
{
	int a1[] = { 1 , 2 , 3 , 4 , 5 };
	int a2[] = { 2 , 3 , 6 , 1 , 2 };
	int a3[] = { 3 , 2 , 4 , 5 , 6 };
	int sum = 9;
	int n1 = sizeof(a1) / sizeof(a1[0]);
	int n2 = sizeof(a2) / sizeof(a2[0]);
	int n3 = sizeof(a3) / sizeof(a3[0]);
	findTriplet(a1, a2, a3, n1, n2, n3, sum)?
	cout << "Yes" : cout << "No";

	return 0;
}

/*
Time complexity: O(n2) 
Auxiliary Space: O(n) 
*/

#include <stdio.h> 
#include <locale.h> 
#include <stdbool.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h>
#include <stdlib.h> 

int isPalindrome(long long n)
{
	long long reverse = 0;
	long long temp = 0;


	temp = n;

	while (temp != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + temp % 10;
		temp = temp / 10;
	}

	if (n == reverse)
		return 1;
	else
		return 0;
}

bool isprime(unsigned long n)
{
	unsigned long i;
	unsigned long k;

	if (n <= 3)
	{
		if (n == 1)
		{
			return false;
		}
		return true;
	}
	if ((n % 2) == 0)
	{
		return false;
	}
	k = sqrt(n) + 1;
	for (i = 3; i <= k; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int factor(unsigned long n)
{
	unsigned long k;
	int count = 2;

	for (k = 2; k < n; k++)
	{
		if (n % k == 0)
			count++;
	}

	return count;
}

void NumberOne()
{
	int c = 0;

	for (int i = 1; i < 1000; i++)
		if (i % 3 == 0 || i % 5 == 0)
			c += i;

	printf("Answer NumberOne = %d\n", c);
}

void NumberTwo()
{
	int a = 1;
	int b = 0;
	int c = 0;
	int sum = 0;
	while (c <= 4000000)
	{
		c = a + b;
		if (c % 2 == 0)
			sum += c;
		a = b;
		b = c;
	}
	printf("Answer NumberTwo = %d\n", sum);
}

void NumberThree()
{
	long long num = 600851475143;
	long long count = 2;
	while (1)
	{
		if (num % count == 0)
		{
			num /= count;
			if (num == 1)
			{
				printf("Answer NumberThree = %lli\n", count);
				break;
			}
		}
		count += 1;
	}
}

void NumberFour()
{
	long long b = 1;
	long long c = 0;
	for (int i = 100; i < 999; i++)
	{
		for (int j = 100; j < 999; j++)
		{
			c = (long long)i * j;

			if (isPalindrome(c) == 1)
				if (c > b)
					b = c;
		}
	}
	printf("Answer NumberFour = %lli\n", b);
}

void NumberFive()
{
	const unsigned long val = 20;
	unsigned long x;
	unsigned long y;

	for (x = val; ; x += val)
	{
		for (y = val - 1; y; y--)
		{
			if (x % y != 0)
			{
				break;
			}
		}

		if (y == 0)
		{
			printf("Answer NumberFive = %u \n", x);
			break;
		}
	}
}

void NumberSix()
{
	long long a = 0;
	long long b = 0;
	long long c = 0;
	for (long long i = 1; i <= 100; i++)
		a += i;
	a = pow(a, 2);

	for (long long i = 1; i <= 100; i++)
		b += pow(i, 2);

	c = a - b;
	printf("Answer NumberSix = %lli\n", c);
}

void NumberSeven()
{
	long long c = 0;
	for (long long i = 1; i < 10000000000; i++)
	{
		if (isPrime(i) == 1)
		{
			c++;
		}
		if (c == 10002)
		{
			printf("Answer NumberSeven = %lli\n", i);
			break;
		}
	}
}

void NumberEight()
{
	char* number = "73167176531330624919225119674426574742355349194934" \
		"96983520312774506326239578318016984801869478851843" \
		"85861560789112949495459501737958331952853208805511" \
		"12540698747158523863050715693290963295227443043557" \
		"66896648950445244523161731856403098711121722383113" \
		"62229893423380308135336276614282806444486645238749" \
		"30358907296290491560440772390713810515859307960866" \
		"70172427121883998797908792274921901699720888093776" \
		"65727333001053367881220235421809751254540594752243" \
		"52584907711670556013604839586446706324415722155397" \
		"53697817977846174064955149290862569321978468622482" \
		"83972241375657056057490261407972968652414535100474" \
		"82166370484403199890008895243450658541227588666881" \
		"16427171479924442928230863465674813919123162824586" \
		"17866458359124566529476545682848912883142607690042" \
		"24219022671055626321111109370544217506941658960408" \
		"07198403850962455444362981230987879927244284909188" \
		"84580156166097919133875499200524063689912560717606" \
		"05886116467109405077541002256983155200055935729725" \
		"71636269561882670428252483600823257530420752963450";

	long long largest = 0;

	long long length = strlen(number);
	for (long long i = 0; i < (length - 13); i++) 
	{
		long long product = 1;

		for (long long j = 0; j < 13; j++)
			product *= (*(char*)(number + i + j)) - '0';    //   (long long) product  *= (char*) number[1..13]

		if (product > largest)
			largest = product;
		else if (product == 0) 
			continue;

	}

	printf("Answer NumberEight = %lli\n", largest);

}

void NumberNine()
{
	int p = 1000;
	for (int i = 1; i <= p; i++)
	{
		for (int j = i+1; j <= p; j++)
		{
			int c = p - i - j;
			if ((i*i) + (j*j) == c*c)
			{
				int d = i * j * c;
				printf("Answer NumberNine = %d\n", d);
			}
		}
	}
}

void NumberTen()
{
	unsigned long num = 2000000;
	unsigned long x;
	unsigned long long y = 0;

	for (x = 2; x < num; x++)
	{
		if (isprime(x))
		{
			y += x;
		}
	}
	printf("Answer NumberTen = %llu\n", y);
	return 0;
}

void NumberEleven()
{
	//Reading a table from a file
	FILE* file;
	fopen_s(&file, "NumberEleven.txt", "r");
	int grid[20][20];
	int i;
	int j;
	int greatestProd = 0;
	int temp;

	if (!file)
	{
		printf("\n -- Open file problem --\n");
		return 1;
	}

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			fscanf_s(file, "%d", &grid[i][j]);
		}
	}

	// For each number in the grid, there are 8 possible products
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			//rigth
			if (i + 3 < 20)
			{
				temp = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
				if (temp > greatestProd)
					greatestProd = temp;
			}
			//rigth down
			if ((i + 3 < 20) && (j + 3 < 20))
			{
				temp = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
				if (temp > greatestProd)
					greatestProd = temp;
			}
			//down
			if (j + 3 < 20)
			{
				temp = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
				if (temp > greatestProd)
					greatestProd = temp;
			}
			//left down
			if ((i - 3 > 0) && (j + 3 < 20))
			{
				temp = grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3];
				if (temp > greatestProd)
					greatestProd = temp;
			}
			//left
			if (i - 3 > 0)
			{
				temp = grid[i][j] * grid[i - 1][j] * grid[i - 2][j] * grid[i - 3][j];
				if (temp > greatestProd)
					greatestProd = temp;
			}
			//left up
			if ((i - 3 > 0) && (j - 3 > 0))
			{
				temp = grid[i][j] * grid[i - 1][j - 1] * grid[i - 2][j - 2] * grid[i - 3][j - 3];
				if (temp > greatestProd)
					greatestProd = temp;
			}
			//up
			if (j - 3 > 0)
			{
				temp = grid[i][j] * grid[i][j - 1] * grid[i][j - 2] * grid[i][j - 3];
				if (temp > greatestProd)
					greatestProd = temp;
			}
			//rigth up
			if ((i + 3 < 20) && (j - 3 > 0))
			{
				temp = grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 1] * grid[i + 3][j - 1];
				if (temp > greatestProd)
					greatestProd = temp;
			}
		}
	}

	printf("Answer NumberEleven = %d\n", greatestProd);

	fclose(file);
}

void NumberTwelve()
{
	unsigned long trinum = 0;
	unsigned long i = 0;
	int count;

	for (i = 1; i < ULONG_MAX; i++)
	{
		trinum += i;

		/* triangle number is given by n(n+1)/2 */

		if (i & 1)
			count = factor(i) * factor((i + 1) / 2);
		else
			count = factor(i / 2) * factor(i + 1);

		if (count > 500)
		{
			printf("Answer NumberTwelve = %ld\n", trinum);
			return 0;
		}
		count = 0;
	}
	
}

void NumberThirteen()
{
	unsigned long long numbers[100] = {
		37107287533, 46376937677, 74324986199, 91942213363, 23067588207,
		89261670696, 28112879812, 44274228917, 47451445736, 70386486105,
		62176457141, 64906352462, 92575867718, 58203565325, 80181199384,
		35398664372, 86515506006, 71693888707, 54370070576, 53282654108,
		36123272525, 45876576172, 17423706905, 81142660418, 51934325451,
		62467221648, 15732444386, 55037687525, 18336384825, 80386287592,
		78182833757, 16726320100, 48403098129, 87086987551, 59959406895,
		69793950679, 41052684708, 65378607361, 35829035317, 94953759765,
		88902802571, 25267680276, 36270218540, 24074486908, 91430288197,
		34413065578, 23053081172, 11487696932, 63783299490, 67720186971,
		95548255300, 76085327132, 37774242535, 23701913275, 29798860272,
		18495701454, 38298203783, 34829543829, 40957953066, 29746152185,
		41698116222, 62467957194, 23189706772, 86188088225, 11306739708,
		82959174767, 97623331044, 42846280183, 55121603546, 32238195734,
		75506164965, 62177842752, 32924185707, 99518671430, 73267460800,
		76841822524, 97142617910, 87783646182, 10848802521, 71329612474,
		62184073572, 66627891981, 60661826293, 85786944089, 66024396409,
		64913982680, 16730939319, 94809377245, 78639167021, 15368713711,
		40789923115, 44889911501, 41503128880, 81234880673, 82616570773,
		22918802058, 77158542502, 72107838435, 20849603980, 53503534226,
	};

	unsigned long long sum = 0;
	for (unsigned i = 0; i < 100; ++i)
		sum += numbers[i];

	while (sum > 10000000000)
		sum /= 10;

	printf("Answer NumberThirteen = %llu\n", sum);
}

void NumberFourteen()
{
	unsigned int maxTerms = 0;
	unsigned int longest = 0;
	for (unsigned int i = 3; i <= 1000000; ++i)
	{
		unsigned int tempTerms = 1;
		unsigned int j = i;
		while (j != 1)
		{
			++tempTerms;

			if (tempTerms > maxTerms)
			{
				maxTerms = tempTerms;
				longest = i;
			}

			if (j % 2 == 0)
				j /= 2;
			else
				j = 3 * j + 1;
		}
	}

	printf("Answer NumberFourteen = %d\n", longest);
}

void NumberFifteen()
{
	long long int matrix[21][21];
	int i, j;
	for (i = 0; i <= 21 - 1; i++) {
		matrix[21 - 1][i] = 1;
		matrix[i][21 - 1] = 1;
	}
	for (i = 21 - 2; i >= 0; i--)
		for (j = 21 - 2; j >= 0; j--)
			matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
	printf("Answer NumberFifteen = %lld\n", matrix[0][0]);
}

int main()
{
	NumberOne();
	NumberTwo();
	NumberThree();
	NumberFour();
	NumberFive();
	NumberSix();
	NumberSeven();
	NumberEight();
	NumberNine();
	NumberTen();
	NumberEleven();	//Reading a table from a file
	NumberTwelve();
	NumberThirteen();
	NumberFourteen();
	NumberFifteen();
}

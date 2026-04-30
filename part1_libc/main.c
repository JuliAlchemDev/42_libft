#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define GREEN   "\033[38;2;80;250;123m"   // #50fa7b
#define PINK    "\033[38;2;255;121;198m"  // #ff79c6:
#define PURPLE  "\033[38;2;189;147;249m"  // #bd93f9
#define YELLOW  "\033[38;2;241;250;140m"  // #f1fa8c
#define RESET   "\033[0m"

#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define ITALIC  "\033[3m"
#define UNDERLINE "\033[4m"

#define SEP  PURPLE DIM "------------------\n" RESET

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void check(char *name, int result)
{
    if (result)
        printf(BOLD GREEN "[OK] - " RESET "%s\n", name);
    else 
        printf(BOLD UNDERLINE PINK "[KO] - %s\n" RESET, name);
}

// 1. Character Classification Functions
// Utils
int get_random(int min, int max)
{
    int random_num = rand() % (max - min + 1) + min;
    return (random_num);
}

int edge_cases[] = { 
    0,        // '\0'
    32,       // espacio
    65,       // 'A'
    127,      // DEL
    128,      // fuera ASCII
    255,      // límite unsigned char
    -1,       // típico error
    EOF       // fin de fichero
};
void test_base(int (*ft)(int), int (*orig)(int))
{
    int i = 0;

    printf(ITALIC YELLOW "base cases\n" RESET);

    while (i < 3)
    {
        int value = get_random(32, 127);

        char name[20];
        sprintf(name, "'%c'", value);

        check(name, !!ft(value) == !!orig(value));
        i++;
    }
}
void test_edge(int (*ft)(int), int (*orig)(int), int *cases, int size)
{
    int i = 0;

    printf(ITALIC YELLOW "edge cases\n" RESET);

    while (i < size)
    {
        int value = cases[i];

        char name[20];

        if (value >= 32 && value <= 126)
            sprintf(name, "'%c'", value);
        else
            sprintf(name, "%d", value);

        check(name, !!ft(value) == !!orig(value));
        i++;
    }
}

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);


void test_isalpha(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_isalpha\n" RESET);
    printf(SEP);

    test_base(ft_isalpha, isalpha);
    test_edge(ft_isalpha, isalpha, edge_cases, ARRAY_SIZE(edge_cases));

    printf(SEP);
}

void test_isdigit(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_isdigit\n" RESET);
    printf(SEP);

    test_base(ft_isdigit, isdigit);
    test_edge(ft_isdigit, isdigit, edge_cases, ARRAY_SIZE(edge_cases));

    printf(SEP);
}

void test_isalnum(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_isalnum\n" RESET);
    printf(SEP);

    test_base(ft_isalnum, isalnum);
    test_edge(ft_isalnum, isalnum, edge_cases, ARRAY_SIZE(edge_cases));

    printf(SEP);
}
void test_isascii(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_isascii\n" RESET);
    printf(SEP);

    test_base(ft_isascii, isascii);
    test_edge(ft_isascii, isascii, edge_cases, ARRAY_SIZE(edge_cases));

    printf(SEP);
}

void test_isprint(void){
    printf(SEP);
    printf(BOLD PURPLE "ft_isprint\n" RESET);
    printf(SEP);

    test_base(ft_isprint, isprint);
    test_edge(ft_isprint, isprint, edge_cases, ARRAY_SIZE(edge_cases));

    printf(SEP);
}

// TYPE CONVERSION

int ft_toupper(int c);
int ft_tolower(int c);
int ft_atoi(const char *str);

void test_toupper(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_toupper\n" RESET);
    printf(SEP);

    printf(ITALIC YELLOW "base cases\n" RESET);

    check("'a'", ft_toupper('a') == toupper('a'));
    check("'m'", ft_toupper('m') == toupper('m'));
    check("'z'", ft_toupper('z') == toupper('z'));
    check("'A'", ft_toupper('A') == toupper('A'));
    check("'1'", ft_toupper('1') == toupper('1'));
    check("'@'", ft_toupper('@') == toupper('@'));

    printf(ITALIC YELLOW "edge cases\n" RESET);

    check("0", ft_toupper(0) == toupper(0));
    check("127", ft_toupper(127) == toupper(127));
    check("-1", ft_toupper(-1) == toupper(-1));
    check("128", ft_toupper(128) == toupper(128));

    printf(SEP);
}

void test_tolower(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_tolower\n" RESET);
    printf(SEP);

    printf(ITALIC YELLOW "base cases\n" RESET);

    check("'a'", ft_tolower('a') == tolower('a'));
    check("'m'", ft_tolower('m') == tolower('m'));
    check("'z'", ft_tolower('z') == tolower('z'));
    check("'A'", ft_tolower('A') == tolower('A'));
    check("'1'", ft_tolower('1') == tolower('1'));
    check("'@'", ft_tolower('@') == tolower('@'));

    printf(ITALIC YELLOW "edge cases\n" RESET);

    check("0", ft_tolower(0) == tolower(0));
    check("127", ft_tolower(127) == tolower(127));
    check("-1", ft_tolower(-1) == tolower(-1));
    check("128", ft_tolower(128) == tolower(128));

    printf(SEP);
}

void test_atoi(void)
{
	printf(SEP);
    printf(BOLD PURPLE "ft_atoi\n" RESET);
    printf(SEP);

    printf(ITALIC YELLOW "base cases\n" RESET);
	
	check("12345", atoi("12345") == ft_atoi("12345"));
    check("-123", atoi("-123") == ft_atoi("-123"));
    check("   -", atoi("   -") == ft_atoi("   -"));

	printf(ITALIC YELLOW "edge cases\n" RESET);
	
	check("1231231231311133", atoi("1231231231311133") == ft_atoi("1231231231311133"));
    // Explanation: The converted number is greater than 231 - 1, therefore print 231 - 1 = 2147483647. ????
    check("-999999999999", atoi("-999999999999") == ft_atoi("-999999999999"));
    // Explanation: The converted number is smaller than -231, therefore print -231 = -2147483648. ????
    check("-0012gfg4", atoi("-0012gfg4") == ft_atoi("-0012gfg4"));

    printf(SEP);
}

int main(void)
{
    srand(time(NULL));

    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();

    test_toupper();
	test_tolower();
	test_atoi();
    return (0);
}

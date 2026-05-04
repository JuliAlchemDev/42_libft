#include <ctype.h>
#include <time.h>
#include <string.h>
#include "libft.h"
#include <stddef.h>

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

// Block 1 - Character Classification Functions



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

void test_strlen(void){
    printf(SEP);
    printf(BOLD PURPLE "ft_strlen\n" RESET);
    printf(SEP);

    printf(ITALIC YELLOW "base cases\n" RESET);

    check("'hello'", ft_strlen("hello") == strlen("hello"));
    check("''", ft_strlen("") == strlen(""));
    check("'A'", ft_strlen("A") == strlen("A"));
  

    printf(ITALIC YELLOW "edge cases\n" RESET);
    char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse nunc magna, semper et imperdiet ac, semper quis justo. Cras at ultrices libero. Ut egestas, urna vel varius congue, leo velit pulvinar ipsum, ut egestas lorem libero nec neque. Nunc lacus quam, aliquet ut malesuada in, pharetra in dolor. Vestibulum a imperdiet odio.";
    check("Long string", ft_strlen(long_str) == strlen(long_str));
    check("'hello\n'", ft_strlen("hello\n") == strlen("hello\n"));
    char s[] = {'h','o','l','a','\0','x','x'};
    check("'{'h','o','l','a',\'\0\','x','x'}'", ft_strlen(s) == strlen(s));
   
    printf(SEP);
}


void test_memset(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_memset\n" RESET);
    printf(SEP);
    printf(ITALIC YELLOW "base cases\n" RESET);

    // String normal
    char s1a[] = "Hello World";
    char s1b[] = "Hello World";
    ft_memset(s1a, '.', 5);
    memset(s1b, '.', 5);
    check("'Hello World' con '.' 5 bytes", memcmp(s1a, s1b, sizeof(s1a)) == 0);

    // Fill completo
    char s2a[] = "Hello";
    char s2b[] = "Hello";
    ft_memset(s2a, 'X', 5);
    memset(s2b, 'X', 5);
    check("fill completo sin tocar \\0", memcmp(s2a, s2b, sizeof(s2a)) == 0);

    // Fill con 0 (limpiar memoria)
    char s3a[] = "Hello";
    char s3b[] = "Hello";
    ft_memset(s3a, 0, 5);
    memset(s3b, 0, 5);
    check("fill con '\\0'", memcmp(s3a, s3b, sizeof(s3a)) == 0);

    printf(ITALIC YELLOW "edge cases\n" RESET);

    // len = 0, no toca nada
    char s4a[] = "Hello";
    char s4b[] = "Hello";
    ft_memset(s4a, 'X', 0);
    memset(s4b, 'X', 0);
    check("len = 0", memcmp(s4a, s4b, sizeof(s4a)) == 0);

    // Valor 255 (unsigned char boundary)
    char s5a[] = "Hello";
    char s5b[] = "Hello";
    ft_memset(s5a, 255, 3);
    memset(s5b, 255, 3);
    check("value = 255", memcmp(s5a, s5b, sizeof(s5a)) == 0);

    // Valor negativo (-1 → debe escribir 0xFF igual que 255)
    char s6a[] = "Hello";
    char s6b[] = "Hello";
    ft_memset(s6a, -1, 3);
    memset(s6b, -1, 3);
    check("value = -1", memcmp(s6a, s6b, sizeof(s6a)) == 0);

    // Retorna el puntero original
    char s7[] = "Hello";
    check("retorna puntero original", ft_memset(s7, '.', 3) == s7);

    // Sobre un array de ints (memoria cruda, no solo chars)
    int arr_a[5] = {1, 2, 3, 4, 5};
    int arr_b[5] = {1, 2, 3, 4, 5};
    ft_memset(arr_a, 0, sizeof(arr_a));
    memset(arr_b, 0, sizeof(arr_b));
    check("array de ints a 0", memcmp(arr_a, arr_b, sizeof(arr_a)) == 0);

    printf(SEP);
}

void test_bzero(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_bzero\n" RESET);
    printf(SEP);
    printf(ITALIC YELLOW "base cases\n" RESET);

    // String normal
    char s1a[] = "Hello World";
    char s1b[] = "Hello World";
    ft_bzero(s1a, 5);
    bzero(s1b, 5);
    check("'Hello World' 5 bytes", memcmp(s1a, s1b, sizeof(s1a)) == 0);

    // Fill completo
    char s2a[] = "Hello";
    char s2b[] = "Hello";
    ft_bzero(s2a, 5);
    bzero(s2b, 5);
    check("fill completo", memcmp(s2a, s2b, sizeof(s2a)) == 0);

    printf(ITALIC YELLOW "edge cases\n" RESET);

    // len = 0, no toca nada
    char s3a[] = "Hello";
    char s3b[] = "Hello";
    ft_bzero(s3a, 0);
    bzero(s3b, 0);
    check("len = 0", memcmp(s3a, s3b, sizeof(s3a)) == 0);

    // Array de ints
    int arr_a[5] = {1, 2, 3, 4, 5};
    int arr_b[5] = {1, 2, 3, 4, 5};
    ft_bzero(arr_a, sizeof(arr_a));
    bzero(arr_b, sizeof(arr_b));
    check("array de ints a 0", memcmp(arr_a, arr_b, sizeof(arr_a)) == 0);

    // Solo 1 byte
    char s4a[] = "Hello";
    char s4b[] = "Hello";
    ft_bzero(s4a, 1);
    bzero(s4b, 1);
    check("1 byte", memcmp(s4a, s4b, sizeof(s4a)) == 0);

    printf(SEP);
}
void test_memcpy(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_memcpy\n" RESET);
    printf(SEP);
    printf(ITALIC YELLOW "base cases\n" RESET);

    // String normal
    char s1a[12] = "";
    char s1b[12] = "";
    ft_memcpy(s1a, "Hello World", 11);
    memcpy(s1b, "Hello World", 11);
    check("'Hello World' 11 bytes", memcmp(s1a, s1b, 12) == 0);

    // Copia parcial
    char s2a[12] = "Hello World";
    char s2b[12] = "Hello World";
    char dst_a[6] = "";
    char dst_b[6] = "";
    ft_memcpy(dst_a, s2a, 5);
    memcpy(dst_b, s2b, 5);
    check("copia parcial 5 bytes", memcmp(dst_a, dst_b, 6) == 0);

    // Copia de ints
    int arr_src[5] = {1, 2, 3, 4, 5};
    int arr_a[5] = {0};
    int arr_b[5] = {0};
    ft_memcpy(arr_a, arr_src, sizeof(arr_src));
    memcpy(arr_b, arr_src, sizeof(arr_src));
    check("array de ints", memcmp(arr_a, arr_b, sizeof(arr_a)) == 0);

    // Copia de un int solo
    int x = 20;
    int ya = 10;
    int yb = 10;
    ft_memcpy(&ya, &x, sizeof(int));
    memcpy(&yb, &x, sizeof(int));
    check("copia de int con &", ya == yb);

    printf(ITALIC YELLOW "edge cases\n" RESET);

    // n = 0, no toca nada
    char s3a[] = "Hello";
    char s3b[] = "Hello";
    char dst_c[6] = "XXXXX";
    char dst_d[6] = "XXXXX";
    ft_memcpy(dst_c, s3a, 0);
    memcpy(dst_d, s3b, 0);
    check("n = 0", memcmp(dst_c, dst_d, 6) == 0);

    // Retorna puntero destino
    char s4[] = "Hello";
    char dst_e[6] = "";
    check("retorna puntero dst", ft_memcpy(dst_e, s4, 5) == dst_e);

    printf(SEP);
}

void test_strlcpy(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_strlcpy\n" RESET);
    printf(SEP);
    printf(ITALIC YELLOW "base cases\n" RESET);

    // Copia normal con truncacion
    char s1a[5];
    char s1b[5];
    size_t r1a = ft_strlcpy(s1a, "Hello World", 5);
    size_t r1b = strlcpy(s1b, "Hello World", 5);
    check("truncacion contenido", memcmp(s1a, s1b, 5) == 0);
    check("truncacion return", r1a == r1b);

    // Copia completa
    char s2a[15];
    char s2b[15];
    size_t r2a = ft_strlcpy(s2a, "Hello World", 15);
    size_t r2b = strlcpy(s2b, "Hello World", 15);
    check("copia completa contenido", memcmp(s2a, s2b, 15) == 0);
    check("copia completa return", r2a == r2b);

    printf(ITALIC YELLOW "edge cases\n" RESET);

    // dstsize = 0
    char s3a[] = "XXXXX";
    char s3b[] = "XXXXX";
    size_t r3a = ft_strlcpy(s3a, "Hello", 0);
    size_t r3b = strlcpy(s3b, "Hello", 0);
    check("dstsize = 0 contenido", memcmp(s3a, s3b, 6) == 0);
    check("dstsize = 0 return", r3a == r3b);

    // src vacio
    char s4a[10] = "XXXXX";
    char s4b[10] = "XXXXX";
    size_t r4a = ft_strlcpy(s4a, "", 10);
    size_t r4b = strlcpy(s4b, "", 10);
    check("src vacio contenido", memcmp(s4a, s4b, 10) == 0);
    check("src vacio return", r4a == r4b);

    // dstsize == strlen(src)
    char s5a[5];
    char s5b[5];
    size_t r5a = ft_strlcpy(s5a, "Hello", 5);
    size_t r5b = strlcpy(s5b, "Hello", 5);
    check("dstsize == strlen(src) contenido", memcmp(s5a, s5b, 5) == 0);
    check("dstsize == strlen(src) return", r5a == r5b);

    printf(SEP);
}

void test_strlcat(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_strlcat\n" RESET);
    printf(SEP);
    printf(ITALIC YELLOW "base cases\n" RESET);

    // Concatenacion normal
    char s1a[20] = "Hello ";
    char s1b[20] = "Hello ";
    size_t r1a = ft_strlcat(s1a, "World", 20);
    size_t r1b = strlcat(s1b, "World", 20);
    check("concatenacion contenido", memcmp(s1a, s1b, 20) == 0);
    check("concatenacion return", r1a == r1b);

    // Concatenacion con truncacion
    char s2a[8] = "Hello ";
    char s2b[8] = "Hello ";
    size_t r2a = ft_strlcat(s2a, "World", 8);
    size_t r2b = strlcat(s2b, "World", 8);
    check("truncacion contenido", memcmp(s2a, s2b, 8) == 0);
    check("truncacion return", r2a == r2b);

    printf(ITALIC YELLOW "edge cases\n" RESET);

    // dstsize = 0
    char s3a[20] = "Hello ";
    char s3b[20] = "Hello ";
    size_t r3a = ft_strlcat(s3a, "World", 0);
    size_t r3b = strlcat(s3b, "World", 0);
    check("dstsize = 0 contenido", memcmp(s3a, s3b, 20) == 0);
    check("dstsize = 0 return", r3a == r3b);

    // src vacio
    char s4a[20] = "Hello ";
    char s4b[20] = "Hello ";
    size_t r4a = ft_strlcat(s4a, "", 20);
    size_t r4b = strlcat(s4b, "", 20);
    check("src vacio contenido", memcmp(s4a, s4b, 20) == 0);
    check("src vacio return", r4a == r4b);

    // dstsize == strlen(dst)
    char s5a[20] = "Hello ";
    char s5b[20] = "Hello ";
    size_t r5a = ft_strlcat(s5a, "World", 6);
    size_t r5b = strlcat(s5b, "World", 6);
    check("dstsize == strlen(dst) contenido", memcmp(s5a, s5b, 20) == 0);
    check("dstsize == strlen(dst) return", r5a == r5b);

    // dst vacio
    char s6a[20] = "";
    char s6b[20] = "";
    size_t r6a = ft_strlcat(s6a, "World", 20);
    size_t r6b = strlcat(s6b, "World", 20);
    check("dst vacio contenido", memcmp(s6a, s6b, 20) == 0);
    check("dst vacio return", r6a == r6b);

    printf(SEP);
}

void test_strchr(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_strchr\n" RESET);
    printf(SEP);
    printf(ITALIC YELLOW "base cases\n" RESET);

    // Caracter presente
    char s1[] = "Hello World";
    check("primera 'l'", ft_strchr(s1, 'l') == strchr(s1, 'l'));

    // Primer caracter
    check("primer char 'H'", ft_strchr(s1, 'H') == strchr(s1, 'H'));

    // Ultimo caracter
    check("ultimo char 'd'", ft_strchr(s1, 'd') == strchr(s1, 'd'));

    printf(ITALIC YELLOW "edge cases\n" RESET);

    // Caracter no presente
    check("char no presente 'z'", ft_strchr(s1, 'z') == strchr(s1, 'z'));

    // Buscar '\0'
    check("buscar '\\0'", ft_strchr(s1, '\0') == strchr(s1, '\0'));

    // String vacio
    check("string vacio", ft_strchr("", 'a') == strchr("", 'a'));

    // Valor int fuera de char
    check("c = 256", ft_strchr(s1, 256) == strchr(s1, 256));

    printf(SEP);
}

void test_strrchr(void)
{
    printf(SEP);
    printf(BOLD PURPLE "ft_strrchr\n" RESET);
    printf(SEP);
    printf(ITALIC YELLOW "base cases\n" RESET);

    // Caracter presente varias veces
    char s1[] = "Hello World";
    check("ultima 'l'", ft_strrchr(s1, 'l') == strrchr(s1, 'l'));

    // Primer caracter
    check("primer char 'H'", ft_strrchr(s1, 'H') == strrchr(s1, 'H'));

    // Ultimo caracter
    check("ultimo char 'd'", ft_strrchr(s1, 'd') == strrchr(s1, 'd'));

    printf(ITALIC YELLOW "edge cases\n" RESET);

    // Caracter no presente
    check("char no presente 'z'", ft_strrchr(s1, 'z') == strrchr(s1, 'z'));

    // Buscar '\0'
    check("buscar '\\0'", ft_strrchr(s1, '\0') == strrchr(s1, '\0'));

    // String vacio
    check("string vacio", ft_strrchr("", 'a') == strrchr("", 'a'));

    // Valor int fuera de char
    check("c = 256", ft_strrchr(s1, 256) == strrchr(s1, 256));

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

    test_strlen();
    test_strlcpy();
    test_strlcat();
    test_strchr();
    test_strrchr();

    test_memset();
    test_bzero();
    test_memcpy();
    return (0);
}

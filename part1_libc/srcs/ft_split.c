#include <stdio.h>
#include <stdlib.h>
size_t count_words(const char *str, char limit)
{
    size_t i;
    size_t count;
    i = 0;
    count = 0;
    while(str[i])
    {
        if(str[i] != limit)
        {
            count++;
            while(str[i] && str[i] != limit)
                i++;
        } 
        else
            i++;
    }
    return count;
}  
char *extract_word(const char *s, char limit)
{
    size_t i;
    char *word;
    i = 0;
    while(s[i] && s[i] != limit)
        i++;
    word = malloc(i+1);
    if(!word)
        return NULL;
    i = 0;
    while(s[i] && s[i] != limit)
       {
        word[i] = s[i];
        i++;
       }   
    word[i] = '\0'; 
    return (word);
}
char **ft_split(char const *s, char c)
{
    int i;
    int j;
    char **words;
    
    i = 0;
    j = 0;
    if (!s)
        return NULL;
    words = malloc(sizeof(char*) * (count_words(s, c)+1)); 
    if(!words)
        return NULL;
    while(s[i])
    {
        if(s[i] != c)
        {
            words[j] = extract_word(&s[i], c);
            if (!words[j]) // ✅ si falla, liberar todo
            {
                while (j > 0)
                    free(words[--j]);
                free(words);
                return NULL;
            }
            while(s[i] && s[i] != c)
                i++;
            j++;
        }
        else
            i++;
    }
    words[j] = NULL; // ✅ mejor NULL explícito que 0
    return (words);
}
int main() {
    char *str = "Hello World";
    printf("%s", str);
    
    char **arr = ft_split(str, ' ');
    int i = 0;
    while (arr[i])
    {
        printf("\n|%s|", arr[i]);
        i++;
    }
     printf("\nChar: %d", sizeof(char));  
     printf("\nPointer: %d", sizeof(char*));
    return 0;
}
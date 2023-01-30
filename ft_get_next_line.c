#include "gnl.h"
int ft_strlen(char *str)
{
    int i;
    i = 0;
    if (!str)
        return (0);
        while (str[i] != '\0')
            i++;
        return (i);
}
char *ft_copied(char *save)
{
    int i;
    int c;
    char *dest;

    i = 0;
    while (save[i] != '\n')
        i++;
    if (!save[i])
    {
        free(save);
        return (NULL);
    }
    dest = (char *)malloc(sizeof(char) * (ft_strlen(save) + 1));
    if (!dest)
        return (NULL);
    i++;
    
    c = 0;
    while (save[i])
    {
        dest[c++] = save[i++];
    }
    dest[c] = '\0';
    free(save);
    return (dest);
}
char *ft_get_line(char *save)
{
    int i;
    char *dest;
    i = 0;
    
    if (!save[i])
        return (NULL);
    while (save[i])
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
        i = 0;
        while (save[i] != '\n')
        {
            dest[i] = save[i];
            i++;
        }
        if (save[i] == '\n')
        {
            dest[i] = save[i];
            i++;
        }
    dest[i] = '\0';
    return (dest);
}
char *ft_strjoin(char *s1, char *s2)
{
    int i;
    int x;
    char *save;
    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    save = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (save == NULL)
        return (NULL);
    i = -1;
    x = 0;
        while (s1[++i] != '\0')
            save[i] = s1[i];
    while (s2[x] != '\0')
    save[i++] = s2[x++];
    save[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    free(s1);
    return (save);
}
char *ft_strchr(char *str, char c)
{
    int i;
    int size;
    size = 0;
    i = 0;
    // if there is no new line return Null
    if (!str)
        return (NULL);
    while (str[i] != '\n')
    {
        if (str[i] == c)
            return (str);
        i++;
    }
    return (NULL);
}
char *ft_read_and_save(int fd, char *str)
{
    int no_byte;
    char *buff;
   if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (NULL);
    no_byte = 1;
    while (!ft_strchr(str, '\n') && no_byte != 0)
    {
        no_byte = read(fd, buff, BUFFER_SIZE);
        if (no_byte == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[no_byte] = '\0';
        str = ft_strjoin(str, buff);
    }
    free(buff);
    return (str);
}
char *ft_get_next_line(int fd)
{
    static char *save;
    char *line;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    save = ft_read_and_save(fd, save);
    if (!save)
        return (NULL);
    line = ft_get_line(save);
    save = ft_copied(save);
    return (line);
}
int main()
{
    int fd;
    int i;
    i = 0;
    char *str;
    fd = open("text.txt", O_RDONLY);
    while (i < 3)
    {
        str = ft_get_next_line(fd);
        printf("fd %d (%d) %s", fd, i, str);
        free(str);
        i++;
    }
    close(fd);
    return (0);
}
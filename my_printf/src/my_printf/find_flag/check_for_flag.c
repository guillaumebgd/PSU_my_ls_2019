/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** check_for_flag.c
*/

int check_base(char c)
{
    const char bases_list[] = "diuboxX";
    int i = 0;

    while (bases_list[i]) {
        if (bases_list[i] == c)
            return (i);
        i += 1;
    }
    return (-1);
}

int check_for_mod(char c)
{
    const char mod_list[] = "#hlq";
    int i = 0;

    while (mod_list[i]) {
        if (mod_list[i] == c)
            return (i);
        i += 1;
    }
    return (-1);
}

int check_for_flag(char c)
{
    const char flag_list[] = "cdiuboxXsSp";
    int i = 0;

    while (flag_list[i]) {
        if (flag_list[i] == c)
            return (i);
        i += 1;
    }
    return (-1);
}
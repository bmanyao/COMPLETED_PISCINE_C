/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										 * подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */


/* ************************************************************************** */

void		ft_putchar(char c)			/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

t_list		*ft_create_elem(void *data)	/* Функция создает экземпляр структуры типа t_list, заполняет его данными - адрес из указателя data
										 * в первый элемент экземпляра структуры, нулевой адрес во второй элемент экземпляра структуры. И в 
										 * конце функция его возвращает адрес созданого экземпляра структуры типа t_list*/
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адрес выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры адрес принятого
										 * в аргументах элемента неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}

/* ************************************************************************** */

void	ft_putstr(void *str)			/* Функция принимает адрес неизвестного типа но предпологаая что там находиться строка переводит адрес в тип
										 * 'char' и печатает cсодержимое */
{
	while (*((char *)str))
		ft_putchar(*((char *)str++));
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))/* функция принимает адресс первого экземпляра структуры уепи связанных между собой 
										 * структур и применяет для каждого экземпляра структуры этой цепи функцию, адресскоторой мы приняли в 
										 * аргументах */
{
	while (begin_list)					/* Запускаем цикл, который пройдется покаждому экземпляру структуры цепи связаных между собой структур */
	{
		(*f)(begin_list->data);			/* На каждой итерации этого цикла, к каждому экземпляру структуры, мы применяем функцию принятую в аргументах */
		begin_list = begin_list->next;	/* Сохраняем в указателе адресс следующего экземпляра структуры для работы с ним на след итерации цикла */
	}
}

int			main(void)
{
	t_list	*list;						/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */

	list = ft_create_elem("Bro ");		/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										 * данных которыем мы ей отправим) и вернет адрес этого экземпляра структуры типа t_list,
										 * который мы сохраним в указателе на экземпляр структуры типа t_list */
	list->next = ft_create_elem("Hey ");/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										 * данных которыем мы ей отправим) и вернет адрес этого экземпляра структуры типа t_list 
										 * И сохранит этот адрес в указателе на экземпляр структуры типа t_list, который хранится в одном из элементов 
										 * текущего экземпляра структуры, адрес которой хранится в указателе 'list' */
	/* И создадим еще дополнительно несколько экземпляров структуры, которые свяжем между собой и с предыдущим экземпляром */
	list->next->next = ft_create_elem("Hello ");
	list->next->next->next = ft_create_elem("My ");
	list->next->next->next->next = ft_create_elem("Cool ");
	list->next->next->next->next->next = ft_create_elem("Friend ");

	ft_list_foreach(list, &ft_putstr);	/* Отправляем адрес первого экземпляра структуры цепи связанных между собой экземпляров структур
										 * и адресс функции в аргументы функции 'ft_list_foreach'. Отправленный аадресс функции будет использован
										 * для вызова этой функции по отношению к каждому элементу цепи связанных между собой экземпляров цепи */
	ft_putchar('\n');					/* Печатаем символ переноса строки для кореектного отображения вывода */
	return (0);							/* Завершаем функцию и возвращаем ноль */
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_display_file(char *argv)				/* Функция принимаем строку содержащую имя и путь до файла, и печатает его содержимое */
{
	int		r;									/* Обьявляем переменную которая будет хранить количество считаных в буфер символов */
	int 	fd;									/* Обьявляем переменную которая будет хранить идентификатор файлового потока(дескриптор файла) нашего файла.
												** (Файловый дескриптор — это неотрицательное число, которое является идентификатором
												** какого-либо потока ввода-вывода, который может быть связан с файлами, каталогами или сокетами.
												** Сами дескрипторы файлов привязаны к идентификатору процесса. Самые известные файловые дескрипторы - это 0, 1, 2.
												** Нулю соответствует STDIN(стандартный поток ввода), еденице соответствует STDOUT(стандартный поток вывода),
												** а двойке соответствует STDERR(стандартный поток ошибок). У каждой програмы есть все три этих системных потока.) */
	char	buffer;								/* Обьявляем переменную типа 'char' для хранения символа завершающего нуля. Её мы используем как буффер для считывания
												** туда порциями по одному байту данных из потока, на который указывает идентификатор файлового потока(дескриптор файла),
												** который будет хранится в переменной 'fd' */

	if ((fd = open(argv, O_RDONLY)) == -1)		/* Отправляем в функцию 'open' строку с именем и путем до файла, а также флаг 'O_RDONLY'.
												** Благодраря пути до файла и флагу 'O_RDONLY' функция сразу из условия откроет поток для чтения из файла 
												** и вернет нам идентификатор этого потока (файловый дескриптор) который мы сохраним в 'fd'.
												** Как только мы получили результат работы функции мы сразу проверияем все ли прошло хорошо, сверяя
												** содержимое переменной 'fd', в котором должен быть дескриптор файла.
												** ЕСЛИ что то пойшло не так и функция может открыть поток до файла, то она вернет номер ошибки '-1' */
	{
		ft_display_custom_error(errno, argv);	/* Если функция вернула '-1', мы запускаем функцию для печати подробной ошибки, отправляя ей в
												** аргументы содержимое переменной 'errno' хранящей номер последней ошибки программы и адрес
												** строки, с которой была связана ошибка, а после игнорирует остальной код и завершаем функцию */
	}
	else										/* ЕСЛИ все прошло хорошо и мы получили в переменную 'fd' идентификатор потока (файловый дескриптор) 
												** то мы запускаем код, который считает из файла данные и напечатает их через стандартный поток вывода */
	{
		while ((r = read(fd, &buffer, 1)))		/* Запускаем цикл, который с помощью функции 'open' сразу из условия будет порциями считывать данные из файла 
												** во временный буфер используя дескриптор файла(идентификатор потока к файлу), массив 'buffer' и размер массива.
												** После считывания порции данных из файла, функция сместит метку указывающую на адрес начала файла, с  
												** которого функция должна начать читать данные, на другой адрес, который будет указывать на симол
												** идущий после последнего считаного символа.
												** После завершения работы функция вернет нам число, отражающее колличество считанных в буфер символов, которое
												** мы сохраним в переменной 'r'.
												** Цикл проверит содержимое переменной 'r' и если он увидит что функция 'open' вернула некоторое число, то он 
												** запустит код внутри себя, который проверит это число, и если все хорошо, напечатает содержимое буфера */
		{
			if (r == -1)						/* Проверяем число которое нам вернула функция 'open'. Если это число равно '-1' значит у нас произошла ошибка */
			{
				ft_display_custom_error(errno, argv);/* И мы запускаем функцию для печати подробной ошибки, отправляя ей в аргументы содержимое переменной
												** 'errno' хранящей номер последней ошибки программы и адрес строки, с которой была связана ошибка */
				break;							/* А после завершаем цикл */
			}
			else								/* Если это число не равно '-1' значит функция отработала успешно и 'buffer' содержит считанные данные */
			{
				ft_putchar(buffer);				/* Печатаем содержимое массива сиволов содержащих порцию считанных из файла данных */
			}
		}										
		if ((close(fd)) == -1)					/* Закрываем файловый поток с помощью функции 'close' и дескриптора файла(идентификатора файлового потока).
												** И проверяем число которое нам вернула функция. Если это число равно '-1' значит у нас произошла ошибка 
												** закрытия файлового потока */
		{
			ft_display_custom_error(errno, argv);/* Запускаем функцию для печати подробной ошибки, отправляя ей в аргументы содержимое переменной
												** 'errno' хранящей номер последней ошибки программы и адрес строки, с которой была связана ошибка */
		}
	}
}
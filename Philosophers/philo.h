/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:08:21 by lloginov          #+#    #+#             */
/*   Updated: 2024/11/22 18:41:55 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define NC "\e[0m"		  // reset color
# define YELLOW "\e[1;33m" // yellow
# define BLUE "\e[1;34m"	  // bleu
# define GREEN "\e[1;32m"  // green
# define RED "\e[1;31m"	  // red
# define PURPLE "\033[0;35m" // violette

typedef struct t_philo
{
	int				id;
	int				nb_forks;
	int				nb_philo;
	char			*philo;
	int				must_eat;
	int				dead;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t	*printf;
}	t_philo;

typedef	struct t_data
{
	long long		start_time;
	int			time_eat;
	int			time_die;
	int			time_sleep;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eat;
	t_philo			*philo;
}	t_data;


// philo

// philo_utils
void	phree( t_philo *philo, t_data *data);
void	*print_message(void *arg);
int		get_time(void);
int	lockclear(t_data *data, char *str);

// void	innit_var2( t_philo *philo);
int		ft_atoi(const char *str);
// void	phree( t_philo *philo);

// philo
int	innit_philo(int ac, char **av,  t_philo *philo, t_data *data);
int	philo_thread(t_philo *philo, t_data *data);
int parsing(int ac, char **av);
void *routine(void *arg);

// main
int		main(int ac, char **av);

//algo
int	thinking(t_data *data);
int	eating(t_data *data);
int	slepping(t_data *data);

#endif
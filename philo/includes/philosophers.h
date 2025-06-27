/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:52:56 by fernando          #+#    #+#             */
/*   Updated: 2025/06/27 12:08:23 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* Structuts */
typedef struct s_data {
	int num_philosophers;   // Número de filósofos
	int num_philo_eaten;	// Filosofos que han terminado de comer
	int time_to_die;        // Tiempo máximo sin comer
	int time_to_eat;        // Tiempo que tarda en comer
	int time_to_sleep;      // Tiempo que tarda en dormir
	int max_meals;          // Número máximo de comidas (opcional)
	long start_time;        // Tiempo de inicio del programa
	pthread_mutex_t *forks; // Array de mutexes para los tenedores
	pthread_mutex_t print;  // Mutex para imprimir en la salida estándar
	pthread_mutex_t stop_mutex;	// Mutex para acceder y modificar los datos globales
	int stop_simulation;    // Bandera para detener la simulación
} t_data;

typedef struct s_philosopher {
	int id;               // Identificador único del filósofo
	pthread_t thread;     // Hilo asociado al filósofo
	int left_fork;        // Índice del tenedor izquierdo
	int right_fork;       // Índice del tenedor derecho
	long last_meal_time;  // Tiempo de la última comida
	int meal_count;       // Número de comidas realizadas
	int have_eaten;		  // 0 si no ha terminado todas las comidas
	struct s_data *data;  // Puntero a los datos compartidos
} t_philosopher;

/** Time functions **/
long int	get_time(void);
void		wait(long time_to_sleep, t_philosopher *philo);
void		wait2(long time_to_sleep);
long int	get_diff_time(long int init_time);
long 		intget_time(void);

/** Utils **/
int		ft_atoi(const char *str);
void	print_status(t_philosopher *philo, const char *status);
int		ft_strlen(const char *str);

/** Error functions **/
void	err_msg_args();
void	ft_free(t_data *data, t_philosopher **phil, char *msg);
int		eval_params(t_data *data);
int		cmp_atoi(char *str);

/*** Philosophers functions ***/
void	*philosopher_routine(void *arg);
int		start_philos(t_philosopher *philos, int n);
void    think_aux(t_philosopher *philo);
int		eval_status(t_philosopher *philo);
int		catch_forks(t_philosopher *philo);

#endif

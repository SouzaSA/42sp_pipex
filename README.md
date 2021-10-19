# 42sp_pipex

Program that mimics the behavior of linux pipe.

First the main command checks the input it has four input parameters.

If the input is suitable it calls ft_pipex. Which has the responsibility to call the ft_forker function for each command of the input list, in the mandatory part there are two.

Forker is the main function of the program. 

Está em português no futuro altero.

##Mandatory part
```
 main
  |
  | ft_pipex
  |
  | ft_forker
  |______________ pid = 0
  | pai          | filho
  |              | se for o primeiro filho copia o arquivo de entrada na entrada padrão (0)
  |              | duplica o o pipe[1] na saida padrão (1)
  |              | executa primeiro comando
  |              * finaliza
  |
  | copia a saída do pipe[0] na entrada padrão (0) e fecha o pipe[0]
  | verifica se é o ultimo comando
  | retorna para o while do ft_pipex onde e acrescenta mais um ao indice.
  |
  |_______________ pid = 0
  | pai           | filho
  |               | verifica se é o ultimo comando
  |               | ultimo comando então não faz nada
  |               * finaliza
  |
  |
  | duplica o o pipe[1] na saida padrão (1)
  | executa ultimo comando;
  |
  *
 FIM
 ```
  
  ##Bonus part
```
                   main
                    |
                    | ft_pipex
 __________________>|
|                   | ft_forker
| caso não seja     |______________ pid = 0
| o último comando  | pai          | filho
| copia a saída do  |              | se for o primeiro filho copia o arquivo de entrada na entrada padrão (0)
| pipe[0] na        |              | duplica o o pipe[1] na saida padrão (1)
| entrada padrão    |              | executa primeiro comando
| (0) e fecha o     |              * finaliza
| pipe[0]           | 
|                   | copia a saída do pipe[0] na entrada padrão (0) e fecha o pipe[0]
|                   | verifica se é o ultimo comando, caso sim retorna para o while do ft_pipex
|                   | ft_pipex onde e acrescenta mais um ao indice e verifica se chegou ao ultimo comando,
|                   | caso contrário sai do laço.
|__________________<|
                    |
                    |
                    |_______________ pid = 0
                    | pai           | filho
                    |               | verifica se é o ultimo comando
                    |               | ultimo comando então não faz nada
                    |               * finaliza
                    |
                    |
                    | duplica o o pipe[1] na saida padrão (1)
                    | executa ultimo comando;
                    |
                    *
                   FIM
```
